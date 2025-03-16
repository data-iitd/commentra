import math
import os
import random
import re
import sys

#
# Complete the 'is_palindrome' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def is_palindrome(s):
    # Write your code here
    return "Yes" if s == s[::-1] else "No"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = is_palindrome(s)

    fptr.write(result + '\n')
    fptr.close()

