#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random
import string
import sys

MAX_KEY_VALUE = 100.0
MIN_KEY_VALUE = -100.0
MIN_VALUE = 0
MAX_VALUE = 2 ** 64 - 1

if __name__ == "__main__":
    if 1 == len(sys.argv):
        min_n_of_elems = 2
        max_n_of_elems = 10000
    else:
        min_n_of_elems = int(sys.argv[1])
        max_n_of_elems = int(sys.argv[2])

    for num in range(1, 3):
        values = []
        output_filename = "tests/{:02d}.t".format( num )
        with open( output_filename, 'w') as output:
            for _ in range( 0, random.randint( min_n_of_elems, max_n_of_elems ) ):
                key = random.uniform(MIN_KEY_VALUE, MAX_KEY_VALUE)
                key = round(key, 6)
                value = random.randint(MIN_VALUE, MAX_VALUE)
                values.append( (key, value) )
                output.write( "{:.6f}\t{}\n".format(key, value) )
