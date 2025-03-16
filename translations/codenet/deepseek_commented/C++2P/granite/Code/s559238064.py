
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
import queue
import random
import fileinput
import copy
import time
import types

# Read input string from standard input
z = input()

# Calculate the size of the string and store it in a
a = len(z)

# Iterate through the string
for i in range(a - 1):
    # Check if any two consecutive characters are the same
    if z[i] == z[i + 1]:
        # Print "Bad" if a pair is found and exit
        print("Bad")
        sys.exit(0)

# Print "Good" if no pair is found
print("Good")
