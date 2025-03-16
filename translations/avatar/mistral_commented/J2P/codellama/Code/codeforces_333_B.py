
import math
import os
import random
import re
import sys

#
# Complete the 'countCells' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER m
#  3. 2D_INTEGER_ARRAY banned
#

def countCells(n, m, banned):
    # Write your code here
    answer = (n - 2) * 2
    for i in range(m):
        if banned[i][0] > 1 and banned[i][0] < n:
            answer -= 1
        if banned[i][1] > 1 and banned[i][1] < n:
            answer -= 1
    if n % 2 != 0:
        mid = (n + 1) / 2
        if not any(mid == x for x in banned):
            answer -= 1
    return answer

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    banned = []

    for _ in range(m):
        banned.append(list(map(int, input().rstrip().split())))

    result = countCells(n, m, banned)

    fptr.write(str(result) + '\n')

    fptr.close()

