#!/usr/bin/python3
"""Lockboxes: determine if all boxes can be opened."""

from typing import List


def canUnlockAll(boxes: List[List[int]]) -> bool:
    """Return True if all boxes can be opened, else False."""
    if not isinstance(boxes, list):
        return False

    n = len(boxes)
    if n == 0:
        return True

    open = set([0])
    stack = list(boxes[0])

    while stack:
        key = stack.pop()
        if isinstance(key, int) and 0 <= key < n and key not in open:
            open.add(key)
            for new_key in boxes[key]:
                stack.append(new_key)

    return len(open) == n
