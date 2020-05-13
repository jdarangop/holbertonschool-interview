#!/usr/bin/env python3
""" Minimum Operations """


def minOperations(n):
    """ Find the minimum of operations to reach and string
        using only the operations copy and paste.
        n: int Number of elements in a String.
        Return: Minimum number of this operations.
    """
    if type(n) != int or n <= 0:
        return None
    result = 0
    for i in range(2, n + 1):
        while(n % i == 0):
            result += i
            n = n / i

    return result
