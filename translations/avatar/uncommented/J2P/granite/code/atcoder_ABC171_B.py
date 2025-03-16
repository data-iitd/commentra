
import sys
import io
import os
import math
import heapq
import collections
import bisect
import time
import random
import itertools
import string

def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    ans = sum(a[:k])
    print(ans)

if __name__ == "__main__":
    main()

