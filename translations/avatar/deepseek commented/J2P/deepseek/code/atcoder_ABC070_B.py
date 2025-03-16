import sys
import io
import os
import math
import collections
import heapq
import itertools
import bisect
import re

# Import necessary modules for input/output operations and utility methods

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_reader = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
    out_writer = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
    
    # Set up input and output streams, and create an InputReader instance
    
    a = int(in_reader.readline().strip())
    b = int(in_reader.readline().strip())
    c = int(in_reader.readline().strip())
    d = int(in_reader.readline().strip())
    
    # Read four integers from the input
    
    if c > b:
        print(0)
    elif a > d:
        print(0)
    elif a < c:
        print(min(b, d) - c)
    else:
        l = [a, b, c, d]
        l.sort()
        print(l[2] - l[1])
    
    # Check the values of a, b, c, and d and print the result based on the conditions

if __name__ == "__main__":
    main()

