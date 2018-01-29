#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random
import string

MAX_KEY_VALUE = 100.0
MIN_KEY_VALUE = -100.0
MIN_VALUE = 0
MAX_VALUE = 2 ** 64 - 1

if __name__ == "__main__":
    for num in range(1, 20):
        values = []
        output_filename = "tests/{:02d}.t".format( num )
        with open( output_filename, 'w') as output:
            for _ in range( 0, random.randint( 2, 100000 ) ):
                key = random.uniform(MIN_KEY_VALUE, MAX_KEY_VALUE)
                value = random.randint(MIN_VALUE, MAX_VALUE)
                values.append( (key, value) )
                output.write( "{:.6f}\t{}\n".format(key, value) )
        # Answer.
        # values[0][0] -- key
        # values[0][1] -- value
        output_filename = "tests/{:02d}.a".format( num )
        with open( output_filename, 'w') as output:
            values = sorted( values, key=lambda x: x[0] )
            for value in values:
                output.write( "{:.6f}\t{}\n".format(value[0], value[1]) )
