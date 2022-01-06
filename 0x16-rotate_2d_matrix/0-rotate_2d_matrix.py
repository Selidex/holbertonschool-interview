#!/usr/bin/python3
"""This will rotate a 2D matrix"""


def rotate_2d_matrix(matrix):
    """Does the rotation"""
    tmp = list(zip(*matrix[::-1]))
    tmp2 = [list(n) for n in tmp]
    matrix.clear()
    matrix.append(tmp2)
