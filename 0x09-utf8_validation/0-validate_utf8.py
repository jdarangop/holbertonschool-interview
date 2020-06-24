#!/usr/bin/env python3
""" UTF-8 Validation """


def count_bytes(num):
    """ count bytes from de first byte encoding.
        Args:
            num: (int) integer number.
        Return:
            amount of first ones.
    """
    counter = 0
    factor = 7
    while num & 1 << factor:
        counter += 1
        factor -= 1
    return counter


def validUTF8(data):
    """ determines if a given data set
        represents a valid UTF-8 encoding.
        Args:
            data: (list) containing characters in decimal numbers.
        Returns:
            True if it's valid, False if doesn't.
    """
    i = 0
    while i < len(data):
        if data[i] < 1 << 7:
            i += 1
        else:
            num_bytes = count_bytes(data[i])
            if i + num_bytes > len(data):
                return False
            else:
                for j in range(num_bytes):
                    if count_bytes(data[i + j]) != 1:
                        return False
                i += num_bytes
    return True
