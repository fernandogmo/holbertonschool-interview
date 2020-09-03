#!/usr/bin/python3
''' Computes metrics from data generated by 0-generator.py '''
import sys
from collections import OrderedDict


def print_log(size, codes):
    ''' Prints computed metrics '''
    print("File size: {}".format(size))
    for k, v in codes.items():
        if v != 0:
            print("{}: {}".format(k, v))


if __name__ == "__main__":
    line_count = total_size = 0
    CODES = [200, 301, 400, 401, 403, 404, 405, 500]
    codes = OrderedDict((k, 0) for k in CODES)
    try:
        for line in sys.stdin:
            try:
                codes[int(line.split()[-2])] += 1
            except KeyError:
                pass
            try:
                total_size += int(line.split()[-1])
            except Exception:
                pass
            line_count += 1
            if line_count % 10 == 0:
                print_log(total_size, codes)
        print_log(total_size, codes)
    except KeyboardInterrupt:
        print_log(total_size, codes)
