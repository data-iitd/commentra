
import math
import os
import random
import re
import sys

# Complete the beacons function below.
def beacons(n, beacon):
    max = 0
    dp = [0] * 1000001
    if beacon[0] != 0:
        dp[0] = 1
    for i in range(1, 1000001):
        if beacon[i] != 0 and beacon[i] < i:
            dp[i] = dp[i - beacon[i] - 1] + 1
        elif beacon[i] != 0:
            dp[i] = 1
        else:
            dp[i] = dp[i - 1]
        max = max(max, dp[i])
    return n - max

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    beacon = list(map(int, input().rstrip().split()))

    result = beacons(n, beacon)

    fptr.write(str(result) + '\n')

    fptr.close()

