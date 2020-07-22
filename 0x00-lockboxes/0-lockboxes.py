#!/usr/bin/python3

def canUnlockAll(boxes):
    n = len(boxes)
    stoppingpoint = 2**n - 1
    openbits = 1
    visitbits = 0
    i = 0
    while i < n:
        box = boxes[i]
        boxbits = 2**i
        if (visitbits & boxbits):
            i += 1
            continue
        if not (openbits & boxbits):
            i += 1
            continue
        visitbits |= boxbits
        if len(box):
            for key in box:
                if key > n - 1:
                    continue
                openbox = 2**key
                openbits |= openbox
            j = min(box)
            if j < i and not (visitbits & 2**j):
                i = j
                continue
        i += 1

    return openbits == stoppingpoint


if __name__ == '__main__':
    good_cases = [
        [[2], [3, 4], [1, 5]],
        [[1], [2], [3], [4], []],
        [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]],
        [[2]],
        [[0, 1], [2, 3], [7, 4], [2]]
    ]
    for case in good_cases:
        assert canUnlockAll(case), "boxes = {}".format(str(case))

    bad_cases = [
        [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]],
    ]
    for case in bad_cases:
        assert canUnlockAll(case) is False, "boxes = {}".format(str(case))

    boxes = [[1, 3], [3, 0, 1], [2], [0]]
    print(canUnlockAll(boxes),  "\t: False")
    print('-----------------------------')

    boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6], [7]]
    print(canUnlockAll(boxes), "\t: False")
    print('-----------------------------')

    boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6], [7]]
    print(canUnlockAll(boxes), "\t: False")
    print('-----------------------------')

    boxes = [[2], [3, 4], [1, 5]]
    print(canUnlockAll(boxes), "\t: True 59")
    print('-----------------------------')

    boxes = [[2]]
    print(canUnlockAll(boxes), "\t: True 63")
    print('-----------------------------')

    boxes = []
    print(canUnlockAll(boxes), "\t: False")
    print('-----------------------------')

    boxes = [[1, 2, 3], [], [], [], []]
    print(canUnlockAll(boxes), "\t: False")
    print('-----------------------------')

    boxes = [[0, 4, 4], [5], [3], [1], [2], [5]]
    print(canUnlockAll(boxes), "\t: True")
    print('-----------------------------')

    boxes = [[1, 4], [2], [0, 4, 1], [6], [3], [4, 1], [5, 6], [7]]
    print(canUnlockAll(boxes), "\t: False")
    print('-----------------------------')

    boxes = [[1], [1], [1]]
    print(canUnlockAll(boxes), "\t: False")
    print('-----------------------------')

    boxes = [[], [2], [4]]
    print(canUnlockAll(boxes), "\t: False")
    print('-----------------------------')

    boxes = [[]]
    print(canUnlockAll(boxes), "\t: True")
    print('-----------------------------')

    boxes = [[0, 1], [2, 3], [7, 4], [2]]
    print(canUnlockAll(boxes), "\t: True 95")
    print('-----------------------------')

    boxes = [[2]]
    print(canUnlockAll(boxes), "\t: True 99")
    print('-----------------------------')

    boxes = [[], [1, 2, 7], [0, 3]]
    print(canUnlockAll(boxes), "\t: False")
    print('-----------------------------')
