
import sys
import io
import random
import math
import string
import time
import collections
import itertools
import bisect

# <START-OF-CODE>

if __name__ == '__main__':
    n = int(input())
    p = [int(x) for x in input().split()]

    ans = 0
    for i in range(n-2):
        if p[i] > p[i+1] and p[i+1] > p[i+2]:
            ans += 1
        if p[i] < p[i+1] and p[i+1] < p[i+2]:
            ans += 1

    print(ans)

# 