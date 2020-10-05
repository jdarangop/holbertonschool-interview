#!/usr/bin/env python3
""" Rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    """ Given an n x n 2D matrix, rotate it 90 degrees.
        Args:
            matrix: (list of list) With the matrix.
        Returns:
            (list of list) With the matrix rotated.
    """
    tmp_mat = [[0 for i in range(len(matrix[0]))] for j in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            tmp_mat[i][j] += matrix[i][j]
            matrix[i][j] -= matrix[i][j]
    result = []
    for i in range(len(tmp_mat)):
        tmp = []
        for row in tmp_mat:
            tmp.append(row[i])
        result.append(tmp[::-1])
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            matrix[i][j] += result[i][j]
