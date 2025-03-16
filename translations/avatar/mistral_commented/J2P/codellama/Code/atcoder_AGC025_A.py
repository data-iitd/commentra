
import math
import os
import random
import re
import sys

# Complete the maxSubarray function below.
def maxSubarray(arr):
    max_so_far = 0
    max_ending_here = 0
    for i in range(len(arr)):
        max_ending_here += arr[i]
        if max_so_far < max_ending_here:
            max_so_far = max_ending_here
        if max_ending_here < 0:
            max_ending_here = 0
    return max_so_far

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input())

    arr = list(map(int, input().rstrip().split()))

    result = maxSubarray(arr)

    fptr.write(str(result) + '\n')

    fptr.close()

