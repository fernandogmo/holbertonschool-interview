#!/usr/bin/python3
"""
N non-attacking queens on an N×N chessboard
Print every solution to the problem, one-per-line.
Example:
fernando@ubuntu:~$ ./0-nqueens.py 4
[[0, 1], [1, 3], [2, 0], [3, 2]]
[[0, 2], [1, 0], [2, 3], [3, 1]]
fernando@ubuntu:~$ ./0-nqueens.py 6
[[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]]
[[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
[[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
[[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]
"""
import sys


def is_valid(result, pos):
    for queen in result:
        if queen[1] == pos[1]:
            return False
        if (queen[0] + queen[1]) == (pos[0] + pos[1]):
            return False
        if (queen[0] - queen[1]) == (pos[0] - pos[1]):
            return False
    return True


def n_queens(n, row, result):
    if (row == n):
        print(result)
    else:
        for col in range(n):
            pos = [row, col]
            if is_valid(result, pos):
                result.append(pos)
                n_queens(n, row + 1, result)
                result.remove(pos)


if __name__ == "__main__":
    try:
        n = int(sys.argv[1])
    except IndexError:
        print("Usage: nqueens N")
        exit(1)
    except ValueError:
        print("N must be a number")
        exit(1)
    else:
        if n < 4:
            print("N must be at least 4")
            exit(1)
        else:
            result = []
            n_queens(n, 0, result)
