#!/usr/bin/python3
"""Finds the parameter of an island"""


def island_perimeter(grid):
    """Finds the perimeter of a grid"""
    p = 0
    for x in range(0, len(grid)):
        for y in range(0, len(grid[0])):
            if grid[x][y] == 1:
                if y != 0 and grid[x][y - 1]:
                    pass
                else:
                    p += 1
                if y != len(grid[0]) - 1 and grid[x][y + 1]:
                    pass
                else:
                    p += 1
                if x != 0 and grid[x - 1][y]:
                    pass
                else:
                    p += 1
                if x != len(grid) - 1 and grid[x + 1][y]:
                    pass
                else:
                    p += 1
    return p
