#!/usr/bin/python3
"""This will rotate a 2D matrix"""


def rotate_2d_matrix(m):
    """Does the rotation"""
    [(m.pop(0), m.append(list(n))) for n in zip(*m[::-1])]
