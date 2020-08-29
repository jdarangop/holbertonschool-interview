#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    # walls = [0, 1, 0, 2, 0, 3, 0, 4]
    # walls = [0, 2, 0, 1, 0, 1, 0, 4]
    # walls = [0, 2, 0, 1, 0, 1, 4, 0]
    # walls = [3, 0, 0, 1, 0, 1, 4, 0]
    # walls = [3, 0, 0, 0, 0, 0, 0, 0]
    # walls = [0, 0, 0, 0, 0, 0, 0, 0]
    # walls = [2, 1]
    # walls = []
    # walls = None
    # walls = [0, 1, 0, -2, 0, 3, 0, 4]
    # lls = [0, 4, 0, 3, 0, 2, 0, 1]
    walls = [2, 0, 2]
    print(rain(walls))
