
import sys
import os
import io
import math
import heapq
import collections
import bisect
import time
import random
import itertools
import string

def main():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort()
    prev = arr[0]
    for i in range(1, n):
        prev = (prev + arr[i]) / 2
    print(prev)

if __name__ == "__main__":
    main()

