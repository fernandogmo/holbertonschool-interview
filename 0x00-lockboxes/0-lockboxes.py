#!/usr/bin/python3
# Check if n locked boxes with keys inside can all be opened
# starting only with the 0th box unlocked.
# Solution uses bitflags for O(1) space complexity.


def canUnlockAll(boxes):
    opened, visited = 1, 0
    i, n = 0, len(boxes)
    while i < n:
        flag = 2**i
        if (visited & flag) or not (opened & flag):
            i += 1
            continue
        box = boxes[i]
        visited |= flag
        for key in box:
            if key < n:
                opened |= 2**key
            if key < i:
                i = key
        if not (visited & 2**i):
            continue
        i += 1
    return opened == 2**n - 1


if __name__ == '__main__':
    good_cases = [
        [[1], [2], [3], [4], []],
        [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]],
        [[2], [3, 4], [1, 5]],
        [[2]],
        [[0, 1], [2, 3], [7, 4], [2]],
        [[0, 4, 4], [5], [3], [1], [2], [5]],
        [[]],
        [[0, 1], [2, 3], [7, 4], [2]],
    ]
    for case in good_cases:
        assert canUnlockAll(case), "boxes = {}".format(str(case))

    bad_cases = [
        [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]],
        [[1, 3], [3, 0, 1], [2], [0]],
        [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6], [7]],
        [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6], [7]],
        [],
        [[1, 2, 3], [], [], [], []],
        [[1, 4], [2], [0, 4, 1], [6], [3], [4, 1], [5, 6], [7]],
        [[1], [1], [1]],
        [[], [2], [4]],
        [[], [1, 2, 7], [0, 3]]
    ]
    for case in bad_cases:
        assert canUnlockAll(case) is False, "boxes = {}".format(str(case))
