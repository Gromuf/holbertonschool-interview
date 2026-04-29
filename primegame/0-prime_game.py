#!/usr/bin/python3
"""
0-prime_game
"""


def isWinner(x, nums):
    """
    Determine le gagnant du jeu des nombres premiers sur plusieurs manches.
    """
    if x < 1 or not nums:
        return None
    max_n = max(nums)
    if max_n < 2:
        max_n = 2

    is_prime = [True] * (max_n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for p in range(2, int(max_n ** 0.5) + 1):
        if is_prime[p]:
            for i in range(p * p, max_n + 1, p):
                is_prime[i] = False
    prime_counts = [0] * (max_n + 1)
    count = 0
    for i in range(len(is_prime)):
        if is_prime[i]:
            count += 1
        prime_counts[i] = count
    maria_wins = 0
    ben_wins = 0
    for i in range(x):
        n = nums[i]
        if prime_counts[n] % 2 != 0:
            maria_wins += 1
        else:
            ben_wins += 1
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
