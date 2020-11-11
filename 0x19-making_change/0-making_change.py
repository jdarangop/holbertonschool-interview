#!/usr/bin/python3
""" Make Change """


def makeChange(coins, total):
    """ determine the fewest number of coins
        needed to meet a given amount total.
        Args:
            coins: (list) the values of the coins in your possession.
            total: (int) amount to be calculated.
        Returns:
            (int) fewest number of coins needed to meet total
                  or -1.
    """
    if total <= 0:
        return 0
    coins = sorted(coins)
    change = [total + 1] * (total + 1)
    change[0] = 0
    for i in range(total + 1):
        for coin in coins:
            if coin <= i:
                change[i] = min(change[i], 1 + change[i - coin])

    return change[total] if change[total] < total else -1
