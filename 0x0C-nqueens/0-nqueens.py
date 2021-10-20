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
    board = create_board(N)
    queen(board, 0)


def isSafe(board, row, col):

    for i in range(col):
        if (board[row][i]):
            return False
    i = row
    j = col
    while i >= 0 and j >= 0:
        if(board[i][j]):
            return False
        i -= 1
        j -= 1

    i = row
    j = col
    while j >= 0 and i < len(board):
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1

    return True


def queen(board, col):
    """ Adds a queen to the board"""
    if (col == len(board)):
        queens = []
        for row in range(len(board)):
            for column in range(len(board[row])):
                if board[row][column] == 1:
                    queens.append([row, column])
        print(queens)
        return True
    test = False
    for i in range(len(board)):
        if (isSafe(board, i, col)):
            board[i][col] = 1
            test = queen(board, col + 1) or test
            board[i][col] = 0
    return test


def create_board(size):
    """creates a 2d array representing a square
    empty chess board filled with [ ]'s"""
    board = []
    row = []
    if isinstance(size, int):
        row = [0 for x in range(size)]
        board = [row.copy() for x in range(size)]
        return board


if __name__ == "__main__":
    main()
