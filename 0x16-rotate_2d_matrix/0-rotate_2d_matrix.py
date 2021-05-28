#!/usr/bin/python3
"""
0x16 - Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ In-place rotation of NxN matrix """
    N = len(matrix)
    for y in range(N // 2):
        last = N - 1
        for x in range(y, last - y):
            tmp = matrix[y][x]
            matrix[y][x] = matrix[last - x][y]
            matrix[last - x][y] = matrix[last - y][last - x]
            matrix[last - y][last - x] = matrix[x][last - y]
            matrix[x][last - y] = tmp


if __name__ == "__main__":
    matrix = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]

    rotate_2d_matrix(matrix)
    print(matrix)
