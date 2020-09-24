#!/usr/bin/python3
"""
A method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    data = iter(data)
    mask = int('0b11111111', 2)
    for n in data:
        n &= mask
        if int('0x00', 16) <= n <= int('0x7f', 16):
            continue
        if int('0b11000010', 2) <= n < int('0b11100000', 2):
            n1 = next(data) & mask
            if int('0b01111111', 2) < n1 < int('0b11000000', 2):
                continue
            else:
                return False
        elif n < int('0b11110000', 2):
            n1 = next(data) & mask
            n2 = next(data) & mask
            if int('0b01111111', 2) < n1 < int('0b11000000', 2) and \
                    int('0b01111111', 2) < n2 < int('0b11000000', 2):
                continue
            else:
                return False
        elif n < int('0b11111000', 2):
            n1 = next(data) & mask
            n2 = next(data) & mask
            n3 = next(data) & mask
            if int('0b01111111', 2) < n1 < int('0b11000000', 2) and \
                    int('0b01111111', 2) < n2 < int('0b11000000', 2) and \
                    int('0b01111111', 2) < n3 < int('0b11000000', 2):
                continue
            else:
                return False
    return True


if __name__ == "__main__":
    pass
