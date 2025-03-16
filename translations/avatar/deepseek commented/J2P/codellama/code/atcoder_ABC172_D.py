
import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(n):
    ans = 0
    for i in range(1, n+1):
        term = n // i
        sum = term * (term + 1) // 2
        ans += i * sum
    return ans

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    result = solve(n)

    fptr.write(str(result) + '\n')
    fptr.close()

