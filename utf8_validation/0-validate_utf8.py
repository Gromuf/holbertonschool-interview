#!/usr/bin/python3
"""
Module that provides a function to validate UTF-8 encoding.
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
        data (list of int): List of integers representing bytes (0–255)

    Returns:
        bool: True if data is a valid UTF-8 encoding, else False
    """
    num_bytes = 0

    for byte in data:
        byte = byte & 0xFF
        if (num_bytes == 0):
            mask = 1 << 7
            while (mask & byte):
                num_bytes += 1
                mask >>= 1
            if (num_bytes == 0):
                continue
            if (num_bytes == 1 or num_bytes > 4):
                return False
        else:
            if not (byte & 0b10000000 and not (byte & 0b01000000)):
                return False
        num_bytes -= 1
    return num_bytes == 0
