#!/usr/bin/python3
"""This will rotate a 2D matrix"""


def rotate_2d_matrix(matrix):
    """Does the rotation"""
    tmp = list(zip(*matrix[::-1]))
    matrix.clear()
    for n in tmp:
        matrix.append(list(n))
