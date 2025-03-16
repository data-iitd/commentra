
import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(n, a, b):
    k = n // (a + b)
    if (n - k * (a + b)) > a:
        return a * k + (n - k * (a + b)) - (n - (k * (a + b) + a))
    else:
        return a * k + (n - k * (a + b))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    a = int(input())

    b = int(input())

    result = solve(n, a, b)

    fptr.write(str(result) + '\n')

    fptr.close()

