
import math
import os
import random
import re
import sys

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isValid(s):
    # Write your code here
    if len(s) % 2 != 0:
        return "NO"
    else:
        x = 0
        y = 0
        for i in range(len(s) // 2):
            x += int(s[i])
        for i in range(len(s) // 2, len(s)):
            y += int(s[i])
        if x == y:
            return "YES"
        else:
            return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')
    fptr.close()

