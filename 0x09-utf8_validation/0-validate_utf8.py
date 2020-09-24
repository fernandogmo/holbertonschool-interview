#!/usr/bin/python3
"""
A method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    data = iter(data)
    mask = int('0b11111111', 2)
    try:
        for n in data:
            n &= mask
            if int('0x00', 16) <= n <= int('0x7f', 16):
                continue
            if int('0xc2', 16) <= n <= int('0xdf', 16):
                n1 = next(data) & mask
                if int('0x80', 16) <= n1 <= int('0xbf', 16):
                    continue
                else:
                    return False
            elif int('0xe0', 16) <= n <= int('0xef', 16):
                n1 = next(data) & mask
                n2 = next(data) & mask
                if int('0xa0', 16) <= n1 <= int('0xbf', 16) and \
                        int('0x80', 16) <= n2 <= int('0xbf', 16):
                    continue
                else:
                    return False
            elif int('0xf0', 16) <= n <= int('0xf4', 16):
                n1 = next(data) & mask
                n2 = next(data) & mask
                n3 = next(data) & mask
                if int('0x90', 16) <= n1 <= int('0x8f', 16) and \
                        int('0x80', 16) <= n2 <= int('0xbf', 16) and \
                        int('0x80', 16) <= n3 <= int('0xbf', 16):
                    continue
                else:
                    return False
    except StopIteration:
        return False
    return True


if __name__ == "__main__":
    pass
