
import math
import os
import random
import re
import sys

# Complete the minimumBribes function below.
def minimumBribes(q):
    previous = q[0]
    answer = 0
    for i in range(1, len(q)):
        if q[i] > previous:
            answer += 1
        if q[i] > previous * 2:
            answer += 1
        if answer > 2:
            print("Too chaotic")
            return
        previous = q[i]
    print(answer)

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)

# 