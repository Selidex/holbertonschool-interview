#!/usr/bin/python3
"""This will rotate a 2D matrix"""


def rotate_2d_matrix(matrix):
    """Does the rotation"""
    print(matrix)
    matrix = list(zip(*matrix[::-1]))
    print(matrix)