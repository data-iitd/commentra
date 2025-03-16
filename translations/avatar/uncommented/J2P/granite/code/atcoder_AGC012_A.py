
import sys
import math
import bisect
import re
import heapq
from collections import deque
from decimal import *
from fractions import *

def main():
    n = int(input())
    array = list(map(int, input().split()))
    array.sort()
    head = len(array) - 2
    res = 0
    for i in range(n):
        res += array[head]
        head -= 2
    print(res)

if __name__ == "__main__":
    main()

