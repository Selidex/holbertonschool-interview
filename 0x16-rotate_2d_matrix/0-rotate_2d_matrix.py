#!/usr/bin/python3
"""This will rotate a 2D matrix"""


def rotate_2d_matrix(matrix):
    """Does the rotation"""
    [(matrix.pop(0), matrix.append(list(n))) for n in list(zip(*matrix[::-1]))]
