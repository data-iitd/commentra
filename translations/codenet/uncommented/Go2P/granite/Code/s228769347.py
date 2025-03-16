
import sys
import os
import io
import math
import heapq
import copy
import time
import collections
import itertools
import bisect
import string
import re
import array
import queue

def main():
    start_time = time.time()

    #fp = open("input.txt")
    #fw = open("output.txt", "w")
    fp = sys.stdin
    fw = sys.stdout

    n = int(fp.readline())
    ll = list(map(int, fp.readline().split()))

    ll.sort()

    ans = 0
    for i in range(n-2):
        for j in range(i+1, n-1):
            l = j + 1
            r = n
            while l < r:
                m = (l + r) // 2
                if ll[m] < ll[i] + ll[j]:
                    l = m + 1
                else:
                    r = m
            ans += l - (j + 1)

    print(ans)

    #fw.write(str(ans))
    #fp.close()
    #fw.close()
    print(time.time() - start_time)

if __name__ == "__main__":
    main()

