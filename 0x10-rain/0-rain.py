#!/usr/bin/python3
""" This module finds the amount of rain collected given a set of walls"""


def rain(walls):
    """ This function does the math"""
    i1 = 0
    i2 = 0
    fall = 0
    if len(walls) < 3:
        return 0
    for x in range(0, len(walls)):
        if walls[x] >= walls[i2]:
            i2 = x
        if walls[i2] >= walls[i1]:
            tmp = i2
            i2 = i1
            i1 = tmp
    fall = walls[i2] * (abs(i2 - i1) - 1)
    if i2 > i1:
        return (fall + rain(walls[0:i1 + 1]) +
                rain(walls[i2:]) -
                sum(walls[i1 + 1: i2]))
    else:
        return (fall + rain(walls[0:i2 + 1]) +
                rain(walls[i1:]) -
                sum(walls[i2 + 1: i1]))
