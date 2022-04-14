#!/usr/bin/python3
""" This function returns pascal's triangle up to n rows"""


def pascal_triangle(n):
    """This function return's Pascal's triangle up to n rows"""
    pascal = []
    for i in range(n):
        pascal.append([])
        pascal[i].append(1)
        for j in range(1, i):
            pascal[i].append(pascal[i - 1][j - 1] + pascal[i - 1][j])
        if(i != 0):
            pascal[i].append(1)
    return pascal
