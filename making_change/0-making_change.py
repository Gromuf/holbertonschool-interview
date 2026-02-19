#!/usr/bin/python3
"""Making change
"""


def makeChange(coins, total):
    """Determines the fewest number of coins needed to meet a given amount total
    Args:
        coins (list): list of the values of the coins in your possession
        total (int): the total amount you need to make change for
    Returns:
        int: fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    num_coins = 0

    for coin in coins:
        if total <= 0:
            break
        count = total // coin
        num_coins += count
        total %= coin

    return num_coins if total == 0 else -1
