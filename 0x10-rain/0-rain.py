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
    assert(all(map(lambda x: x >= 0, walls)))
    volume = width = 0
    prev_wall = 0
    for wall in walls:
        print(f"{wall=}: {prev_wall=}, {width=}")
        if wall == 0 and prev_wall:
            width += 1
            print(f"{wall=}: {prev_wall=}, {width=}")
            print(f"{volume=} --------------------")
            continue
        if prev_wall:
            volume += width * min(prev_wall, wall)
            width = 0
        prev_wall = wall

        print(f"{wall=}: {prev_wall=}, {width=}")
        print(f"{volume=} --------------------")
    print(volume)
    return volume


if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(walls)
    assert(rain(walls) == 6)
