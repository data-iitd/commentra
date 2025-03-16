import math
import os
import random
import re
import sys

# Complete the maxLeft function below.
def maxLeft(n):
    if n > 2:
        return n - 2
    else:
        return 0

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        result = maxLeft(n)

        fptr.write(str(result) + '\n')

    fptr.close()

