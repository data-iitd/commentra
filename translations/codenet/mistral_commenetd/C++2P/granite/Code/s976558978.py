
# URL_HERE

# This is the main Python file for solving a problem. Replace URL_HERE with the URL of the problem statement.

import sys
import math
import string
import re
import fractions
import array
import bisect
import collections
import datetime
import functools
import itertools
import operator
import random
import fileinput
import copy
import time
import heapq
import types
import json
import os
import threading
import queue
import urllib.request, urllib.parse, urllib.error
import numba
import scipy
import sklearn

# Define the necessary standard libraries and modules for the solution.

def main():
    # Read the input from the command line arguments.
    if len(sys.argv) > 1:
        input_file = sys.argv[1]
    else:
        input_file = "dataabc155A.txt"
    # Open the input file for reading.
    with open(input_file, 'r') as f:
        lines = f.readlines()
    # Read the two integers a and b from the input file.
    a = int(lines[0])
    b = int(lines[1])
    # If a is smaller than b, print a b times.
    # If b is smaller than a, print b a times.
    if a < b:
        print(" ".join([str(a)] * b))
    else:
        print(" ".join([str(b)] * a))
    return 0

if __name__ == "__main__":
    main()

