
import math
import os
import random
import re
import sys

# Complete the twoStrings function below.
def twoStrings(s1, s2):
    if '4' in s1 or '7' in s1:
        return 'NO'
    else:
        s1 = list(s1)
        s2 = list(s2)
        s1.sort()
        s2.sort()
        if s1 == s2:
            return 'YES'
        else:
            return 'NO'

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s1 = input()

        s2 = input()

        result = twoStrings(s1, s2)

        fptr.write(result + '\n')

    fptr.close()

