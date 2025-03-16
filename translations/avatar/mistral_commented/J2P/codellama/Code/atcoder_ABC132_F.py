import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    # Calculate the length of the repeated string
    length = len(s)

    # Calculate the number of times the string can be repeated
    num_repeats = int(math.ceil(n / length))

    # Calculate the length of the final string
    final_length = num_repeats * length

    # Calculate the number of characters in the final string
    num_chars = final_length - (final_length - n)

    # Count the number of a's in the final string
    count = 0
    for i in range(num_chars):
        if s[i % length] == 'a':
            count += 1

    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()

