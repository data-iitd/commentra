import math
import os
import random
import re
import sys

# Complete the minimumMoves function below.
def minimumMoves(nums, d):
    result = 0
    a = 0
    for i in range(1, len(nums)):
        a = nums[i - 1] - nums[i]
        if a >= 0:
            result += math.ceil(a / d)
            nums[i] += math.ceil(a / d) * d
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    d = int(input())

    nums = list(map(int, input().rstrip().split()))

    result = minimumMoves(nums, d)

    fptr.write(str(result) + '\n')

    fptr.close()

