import math
import os
import random
import re
import sys

# Complete the minimumMoves function below.
def minimumMoves(n, k):
    i = 1
    req = 1
    while k - req >= 0:
        if k - req >= 0:
            k = k - req
        else:
            break
        i += 1
        if i % n != 0:
            req = i % n
        else:
            req = n
    return k

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()

    n = int(nk[0])

    k = int(nk[1])

    result = minimumMoves(n, k)

    fptr.write(str(result) + '\n')

    fptr.close()

