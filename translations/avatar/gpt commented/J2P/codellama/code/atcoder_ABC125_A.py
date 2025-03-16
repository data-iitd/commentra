import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(sec, per_num, max_sec):
    ans_num = 0
    for i in range(sec, max_sec + 1, sec):
        ans_num += per_num
    return ans_num

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    sec = int(input())

    per_num = int(input())

    max_sec = int(input())

    result = solve(sec, per_num, max_sec)

    fptr.write(str(result) + '\n')

    fptr.close()

