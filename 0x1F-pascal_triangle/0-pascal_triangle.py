#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """ returns a list of lists of integers representing
        the Pascal’s triangle of n.
        Args:
            n: (int) exponent.
        Returns:
            (list of lists) of integers representing
            the Pascal’s triangle of n.
    """
    if n <= 0:
        return []
    triangle = []
    for i in range(n):
        if i == 0:
            triangle.append([1])
        else:
            row = []
            prev = triangle[i - 1]
            for j in range(len(prev) + 1):
                if j == 0 or j == len(prev):
                    if j == 0:
                        row.append(1)
                    if j == len(prev):
                        row.append(1)
                else:
                    row.append(prev[j - 1] + prev[j])
            triangle.append(row)

    return triangle
