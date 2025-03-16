
import sys
import math
import itertools
import collections
import heapq
import bisect
import random
import time
import functools
import operator
import re
import string
import bisect

def main():
    N = int(input())
    S = [int(x) for x in input().split()]
    size = 1 << N
    S.sort()
    spawned = [False] * size
    spawned[size - 1] = True
    active = [S[size - 1]]
    for i in range(N):
        active.sort(reverse=True)
        activated = []
        next = size - 1
        for slime in active:
            while next >= 0 and (S[next] >= slime or spawned[next]):
                next -= 1
            if next < 0:
                print("No")
                return
            spawned[next] = True
            activated.append(S[next])
        active.extend(activated)
    print("Yes")

if __name__ == "__main__":
    main()

