#!/usr/bin/python3

"""
Checks to see if a data set is UTF-8
"""

def validUTF8(data):
    """ This function does the checking """
    x = len(data)
    i = 0;
    while(i < x):
        num = data[i] & 0xFF
        if num >> 7 == 0:
            i += 1
            continue
        return False
    return True
