#!/usr/bin/python3
""" Log parsing """
import sys
from signal import signal, SIGINT


def handler(signum, frame):
    """ Handler for the signal."""
    print("File size: {}".format(total_size))
    for j in sorted(errors.keys()):
        print("{}: {}".format(j, errors[j]))
    raise KeyboardInterrupt


counter = 1
total_size = 0
errors = {"200": 0, "301": 0, "400": 0, "401": 0,
          "403": 0, "404": 0, "405": 0, "500": 0}
for i in sys.stdin:
    splitted = i.split(" ")
    file_size = int(splitted[8].replace("\n", ""))
    total_size += file_size
    errors[splitted[7]] += 1
    counter += 1
    if counter % 10 == 0:
        print("File size: {}".format(total_size))
        for j in sorted(errors.keys()):
            print("{}: {}".format(j, errors[j]))
    signal(SIGINT, handler)
