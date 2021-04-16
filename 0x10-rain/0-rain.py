#!/usr/bin/python3
"""
Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.

Requirements:
- Prototype: def rain(walls)
- walls is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index walls[-1])
    are not walls, meaning they will not retain water.
- If the list is empty return 0.
"""


def rain(walls):
    """ See module description """
    assert all(map(lambda x: x >= 0, walls))
    right = len(walls) - 1
    volume = left = leftmax = rightmax = 0
    while left < right:
        if walls[left] < walls[right]:
            if walls[left] >= leftmax:
                leftmax = walls[left]
            else:
                volume += leftmax - walls[left]
            left += 1
        else:
            if walls[right] >= rightmax:
                rightmax = walls[right]
            else:
                volume += rightmax - walls[right]
            right -= 1
    return volume


if __name__ == "__main__":
    cases = [(0, []),
             (2, [3, 1, 3]),
             (1, [2, 3, 1, 2, 2]),
             (6, [0, 4, 0, 3, 0, 2, 0, 1]),
             (6, [0, 1, 0, 2, 0, 3, 0, 4])]
    for volume, walls in cases:
        assert rain(walls) == volume, \
               "case {} failed with volume {}".format(walls, rain(walls))
