#!/usr/bin/python3
"""
In a text file, there is a single character `H`. Your text editor can execute
only two operations in this file: `Copy All` and `Paste`. Given a number `n`,
write a method that calculates the fewest number of operations needed to result
in exactly `n` `H` characters in the file.

Prototype: `def minOperations(n)`
Returns an integer
If `n` is impossible to achieve, return `0`
Example:

n = 9

H → Copy All → Paste → HH
                        ↪ Paste → HHH
                                    ↪ Copy All → Paste → HHHHHH
                                                            ↪ Paste → HHHHHHHHH

Number of operations: 6
"""


def minOperations(n):
    d = n // 2
    while d > 0:
        q, r = divmod(n, d)
        if (r == 0):
            return q + minOperations(d)
        d -= 1
    return 0


if __name__ == '__main__':
    for i in range(50, 101):
        print("min ops for {} is {}".format(i, minOperations(i)))
