#!/usr/bin/python3


def canUnlockAll(boxes):
    opened, visited = 1, 0
    i, n = 0, len(boxes)
    while i < n:
        box = boxes[i]
        flag = 2**i
        if (visited & flag) or not (opened & flag):
            i += 1
            continue
        visited |= flag
        if len(box):
            for key in box:
                if key > n - 1:
                    continue
                openbox = 2**key
                opened |= openbox
            j = min(box)
            if j < i and not (visited & 2**j):
                i = j
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
