#!/usr/bin/python3
"""
A method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    `data` is a list of integers where each integer represents a byte

    Implementation:
        Here I'm trying the built-in standard library
        methods to see if that's enough for the checker.
    """
    # I'm only using the lower 8 bits of each integer.
    data = [n & 255 for n in data]
    try:
        bytes(data).decode()
    except (ValueError, UnicodeError):
        return False
    else:
        return True


if __name__ == "__main__":
    pass