
import math
import os
import random
import re
import sys

# Complete the isPalindrome function below.
def isPalindrome(s):
    return s == s[::-1]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        s = input()

        result = isPalindrome(s)

        fptr.write(result + '\n')

    fptr.close()

