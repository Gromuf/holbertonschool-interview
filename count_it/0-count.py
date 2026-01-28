#!/usr/bin/python3

import requests


def count_words(subreddit, word_list):
    counts = {}
    for word in word_list:
        w = word.lower()
        counts[w] = counts.get(w, 0)

    def helper(after=None):
        url = f"https://www.reddit.com/r/{subreddit}/hot.json"
        headers = {"User-Agent": "python:count_words:v1.0"}
        params = {"limit": 100, "after": after}
        try:
            response = requests.get(
                url,
                headers=headers,
                params=params,
                allow_redirects=False
            )
        except requests.RequestException:
            return
        if response.status_code != 200:
            return
        data = response.json().get("data", {})
        posts = data.get("children", [])
        for post in posts:
            title = post.get("data", {}).get("title", "").lower()
            words_in_title = title.split()
            for word in words_in_title:
                if word in counts:
                    counts[word] += 1
        after = data.get("after")
        if after:
            helper(after)
    helper()
    sorted_counts = sorted(
        [(word, count) for word, count in counts.items() if count > 0],
        key=lambda x: (-x[1], x[0])
    )
    for word, count in sorted_counts:
        print(f"{word}: {count}")
