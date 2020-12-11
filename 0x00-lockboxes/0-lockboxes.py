#!/usr/bin/python3
# Check if n locked boxes with keys inside can all be opened
# starting only with the 0th box unlocked.


def canUnlockAll(boxes):
    if not boxes:
        return True
    opened = {0}
    keys = [0]

    while keys:
        for key in boxes[keys.pop()]:
            if 0 <= key < len(boxes) and key not in opened:
                opened.add(key)
                keys.append(key)

    return len(boxes) == len(opened)


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
