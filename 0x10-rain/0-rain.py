#!/usr/bin/python3
""" Rain """


def rain(walls):
    """ calculate how much water will be retained after it rains.
        Args:
            walls: (list) a list of non-negative integers.
        Returns:
            (int) indicating total amount of rainwater retained.
                  0 if the list is empty.
    """
    if type(walls) != list or walls is None or walls == []:
        return 0
    tmp = 0
    tmp_sum = 0
    total_sum = 0
    for i in range(len(walls)):
        if i == 0 and walls[i] == 0:
            continue
        if walls[i] < 0:
            return 0
        if walls[i] > tmp:
            tmp = walls[i]
            total_sum += tmp_sum
            tmp_sum = 0
        else:
            tmp_sum += (tmp - walls[i])

    return total_sum
