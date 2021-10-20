#!/usr/bin/python3
"""This is a solution for the N Queens problem"""

import sys


def main():
    """This is the main function. Does the thing"""
    if len(sys.argv) < 2:
        print("Usage: nqueens N")
        return
    N = sys.argv[1]
    if N.isdigit() is not True:
        print("N must be a number")
        return
    N = int(N)
    if N < 4:
        print("N must be at least 4")
        return

if __name__ == "__main__":
    main()
