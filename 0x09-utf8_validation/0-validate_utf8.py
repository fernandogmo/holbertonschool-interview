#!/usr/bin/python3
"""
A method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    bit_count = 0
    for n in data:
        mask = 1 << 7
        if not bit_count:
            while n & mask:
                bit_count += 1
                mask >>= 1
            if bit_count > 4:
                return False
        elif n >> 6 != 2:
            return False
        if bit_count:
            bit_count -= 1
    return bit_count == 0


if __name__ == "__main__":
    pass
