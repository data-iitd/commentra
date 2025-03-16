
import math
import os
import random
import re
import sys

#
# Complete the 'minCost' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY s
#  2. INTEGER_ARRAY p
#  3. INTEGER_ARRAY c
#  4. INTEGER x
#

def minCost(s, p, c, x):
    # Write your code here
    n = len(s)
    dp = [[0] * (n + 1) for _ in range(n + 1)]
    for i in range(n):
        dp[i][i + 1] = s[i]
    for i in range(n - 1, -1, -1):
        for j in range(i + 2, n + 1):
            dp[i][j] = max(dp[i][j - 1], dp[i + 1][j] + c[i])
    return x * (n - 1) + sum(dp[0][i] for i in range(1, n + 1))

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    x = int(first_multiple_input[1])

    s = list(map(int, input().rstrip().split()))

    p = list(map(int, input().rstrip().split()))

    c = list(map(int, input().rstrip().split()))

    result = minCost(s, p, c, x)

    fptr.write(str(result) + '\n')

    fptr.close()

