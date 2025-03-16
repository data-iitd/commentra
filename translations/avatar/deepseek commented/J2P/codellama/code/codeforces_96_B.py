import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(n):
    mask = 2
    while True:
        binary = bin(mask)[2:]
        if binary.count('0') != binary.count('1'):
            mask += 1
            continue
        binary = binary.replace('0', '4').replace('1', '7')
        if int(binary, 2) == n:
            return int(binary, 2)
        mask += 1

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    result = solve(n)

    fptr.write(str(result) + '\n')

    fptr.close()

