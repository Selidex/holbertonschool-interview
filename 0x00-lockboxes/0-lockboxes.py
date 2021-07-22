#!/usr/bin/python3
"""This is an attempt to solve the lockbox problem"""


def canUnlockAll(boxes):
    """Attempts to crack the lock boxes"""
    if boxes is None or len(boxes) == 0 or len(boxes) == 1:
        return True
    if boxes[0] is None or len(boxes[0]) == 0:
        return False
    deadend = 0
    size = len(boxes)
    openBoxes = []
    keys = [0]
    for x in boxes[0]:
        if x < len(boxes) and x not in keys:
            keys.append(x)
    while(deadend == 0):
        deadend = 1
        for x in keys:
            for y in boxes[x]:
                if y < len(boxes) and y not in keys:
                    keys.append(y)
                    deadend = 0
        if len(boxes) == len(keys):
            return True
    return False
