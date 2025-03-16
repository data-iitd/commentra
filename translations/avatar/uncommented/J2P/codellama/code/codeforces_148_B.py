import math
import os
import random
import re
import sys

#
# Complete the 'breakingRecords' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY scores as parameter.
#

def breakingRecords(scores):
    # Write your code here
    max_score = scores[0]
    min_score = scores[0]
    max_count = 0
    min_count = 0
    result = []
    for i in range(1, len(scores)):
        if scores[i] > max_score:
            max_score = scores[i]
            max_count += 1
        elif scores[i] < min_score:
            min_score = scores[i]
            min_count += 1
    result.append(max_count)
    result.append(min_count)
    return result

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

# 