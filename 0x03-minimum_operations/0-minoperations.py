#!/usr/bin/python3
""" Minimum Operations """


def minOperations(n):
    """ Find the minimum of operations to reach and string
        using only the operations copy and paste.
        n: int Number of elements in a String.
        Return: Minimum number of this operations.
    """
    if type(n) != int or n <= 1:
        return 0
    result = 0
    i = 2
    # while(n % i == 0 and i <= n + 1):
    # for i in range(2, n + 1):
    while(i <= n + 1):
        if (n % i == 0):
            result += i
            n = n / i
        else:
            i += 1
    #    i += 1

    return result
