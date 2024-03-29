#!/usr/bin/python3
""" a module that returns the perimeter of the island described in grid"""


def island_perimeter(grid):
    """function declaration"""
    rows = len(grid)
    colons = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(colons):
            if grid[i][j] == 1:
                perimeter += 4
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
    return perimeter
