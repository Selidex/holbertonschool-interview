#!/usr/bin/python3

"""
Checks to see if a data set is UTF-8
"""


def validUTF8(data):
    """ This function does the checking """
    x = len(data)
    i = 0
    while(i < x):
        num = data[i] & 0xFF
        """ If the byte starts with 0, its a single character, so continue"""
        if num >> 7 == 0:
            i += 1
            continue
        """ If the byte starts with 110, it is a two byte character.
        all bytes that follow the initial byte must start with b10, ie be 2.
        otherwise return false"""
        if num >> 5 == 0b110 and i < x - 1:
            if data[i + 1] >> 6 == 2:
                i += 2
                continue
        """ 1110 signals a 3 byte character"""
        if num >> 4 == 0b1110 and i < x - 2:
            if data[i + 1] >> 6 == data[i + 2] >> 6 == 2:
                i += 3
                continue
        """ 11110 signals a 4 byte character"""
        if num >> 3 == 0b11110 and i < x - 3:
            if data[i + 1] >> 6 == data[i + 2] >> 6 == data[i + 3] >> 6 == 2:
                i += 4
                continue
        return False
    return True
