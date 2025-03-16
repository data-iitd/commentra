
# Include the limits header file for INT_MAX, etc.
# Include the math header file for mathematical functions.
# Include the standard input/output header file.
# Include the standard library header file.
# Include the algorithm header file for sorting and other utility functions.
# Include the cfloat header file for floating-point constants.
# Include the complex header file for complex numbers.
# Include the functional header file for function objects.
# Include the iostream header file for input/output streams.
# Include the map header file for associative arrays.
# Include the queue header file for FIFO queues.
# Include the set header file for sets.
# Include the stack header file for LIFO stacks.
# Include the string header file for strings.
# Include the unordered_map header file for hash-based associative arrays.
# Include the vector header file for dynamic arrays.

from __future__ import print_function
from __future__ import division

import sys
import math
import io
import os
import random
import re
import time
import collections
import itertools
import bisect

# Input parameters

# Read the first line of input from stdin
N, X = [int(x) for x in input().strip().split()]

# Read the second line of input from stdin
roads = [int(x) for x in input().strip().split()]

# Read the third line of input from stdin
qs = [int(x) for x in input().strip().split()]

# Initialize the answer
ans = 0

# Initialize the minimum value
min = 1000000000

# Iterate over the roads
for i in range(N):
    # Read the next value
    tmp = roads[i]

    # Update the answer
    ans += 1

    # Update the minimum value
    if tmp < min:
        min = tmp

# Update the answer
ans += X // min

# Output the answer
print(ans)

# 