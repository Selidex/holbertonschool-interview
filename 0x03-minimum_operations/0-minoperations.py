#!/usr/bin/python3
"""Time to do a thing for interviews"""


def minOperations(n):
    """Going to do some weird math here"""
    m = 0
    i = 2
    for i in range(2, n):
        while(n % i == 0):
            m += i
            n = n/i
        if i >= n:
            return m
    return m
