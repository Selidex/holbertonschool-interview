#!/usr/bin/python3
def rain(walls):
    i1 = 0
    i2 = 0
    v1 = 0
    v2 = 0
    fall = 0
    if walls:
        for x in range(0, len(walls)):
            if walls[x] > v2:
                v2 = walls[x]
                i2 = x
            if v2 > v1:
                tmp = v1
                tmpx = i1
                v1 = v2
                i1 = i2
                v2 = tmp
                i2 = tmpx
        return v2 * abs(i1 - i2)
    else:
        return 0
