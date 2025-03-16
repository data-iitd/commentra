

import sys
import math
import bisect
import heapq
import collections
import itertools
import functools
import operator
import re
import array
import random
import string
import copy
import time
import fractions
import numbers
import re
import array
import random
import string
import copy
import time
import fractions
import numbers

def main():
    num = 998244353
    n = int(input())
    ai = []
    bi = []
    for i in range(n):
        a, b = map(int, input().split())
        ai.append(a)
        bi.append(b)
    ai.sort()
    bi.sort()
    if n % 2 == 1:
        print(bi[n // 2] - ai[n // 2] + 1)
    else:
        b = (ai[n // 2] + ai[n // 2 - 1]) / 2
        c = (bi[n // 2] + bi[n // 2 - 1]) / 2
        print(int(2 * (c - b) + 1))

if __name__ == "__main__":
    main()

These comments should provide a clear understanding of the code logic for anyone who reads it.

