
import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(n, arr):
    arr.sort()
    res = 0
    head = len(arr) - 2
    for i in range(n):
        res += arr[head]
        head -= 2
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = solve(n, arr)

    fptr.write(str(result) + '\n')

    fptr.close()

