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


def n_queens(n, row, result):
    if row == n:
        print(result)
    else:
        for col in range(n):
            if all(q[1] != col and
                   q[0] + q[1] != row + col and
                   q[0] - q[1] != row - col for q in result):
                result.append([row, col])
                n_queens(n, row + 1, result)
                result.remove([row, col])


if __name__ == "__main__":
    try:
        n = int(sys.argv[1])
    except IndexError:
        print("Usage: nqueens N") or exit(1)
    except ValueError:
        print("N must be a number") or exit(1)
    else:
        if n < 4:
            print("N must be at least 4") or exit(1)
        else:
            n_queens(n, 0, [])
