#!/usr/bin/python3
""" Log parsing """
import sys


counter = 1
total_size = 0
errors = {"200": 0, "301": 0, "400": 0, "401": 0,
          "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for i in sys.stdin:
        splitted = i.split(" ")
        if len(splitted) >= 2:
            file_size = int(splitted[-1].replace("\n", ""))
            total_size += file_size
            if splitted[-2] in errors:
                errors[splitted[-2]] += 1
            if counter % 10 == 0:
                print("File size: {}".format(total_size))
                for j in sorted(errors.keys()):
                    if errors[j] != 0:
                        print("{}: {}".format(j, errors[j]))
            counter += 1
except AssertionError as error:
    pass
finally:
    print("File size: {}".format(total_size))
    for j in sorted(errors.keys()):
        if errors[j] != 0:
            print("{}: {}".format(j, errors[j]))
