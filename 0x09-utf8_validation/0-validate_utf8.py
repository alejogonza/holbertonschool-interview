#!/usr/bin/python3
"""
validate UTF-8 encoding
"""


def validUTF8(data):
    """ Method for validating utf-8
    @param data: data to test
    @return: True if utf-8 else false
    """
    total_bytes = 0
    first_mask = 1 << 7
    second_mask = 1 << 6
    for i in data:
        another_mask = 1 << 7
        if total_bytes == 0:
            while another_mask & i:
                total_bytes += 1
                another_mask = another_mask >> 1
            if total_bytes == 0:
                continue
            if total_bytes == 1 or total_bytes > 4:
                return False
        else:
            if not (i & first_mask and not (i & second_mask)):
                return False
        total_bytes -= 1
    return total_bytes == 0
