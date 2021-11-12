#!/usr/bin/python3
"""
Create a function `def island_perimeter(grid):` that returns the
perimeter of the island described in `grid`:

- `grid` is a list of list of integers:
    - 0 represents water
    - 1 represents land
    - Each cell is square, with a side length of 1
    - Cells are connected horizontally/vertically (not diagonally).
    - `grid` is rectangular, with its width and height not exceeding 100
- The `grid` is completely surrounded by water
- There is only one island (or nothing).
- The island doesn’t have “lakes” (water inside that isn’t connected
  to the water surrounding the island).
"""


def island_perimeter(grid):
    """ Function to find the perimeter of an island """
    if not grid or any(type(arr) != list for arr in grid):
        return 0
    width = len(grid[0]) - 1
    if any(len(arr) != width + 1 for arr in grid):
        return 0
    islands = connections = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]:
                islands += 1
                if j < len(grid[0]) - 1 and grid[i][j + 1] == 1:
                    connections += 1
                if i < len(grid) - 1 and grid[i + 1][j] == 1:
                    connections += 1
    return 4 * islands - 2 * connections


if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    assert(island_perimeter(grid) == 12)
