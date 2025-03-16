
import sys
import os
import io
import re
import math
import collections
import bisect
import heapq
import time
import random
import itertools
import string
import copy
import deepcopy
import operator
import functools
import fractions
import array
import typing
from typing import List, Tuple, Dict, Set, NewType
from collections import Counter, defaultdict, deque
from heapq import heappush, heappop, heapify
from functools import reduce, lru_cache, singledispatch
from bisect import bisect_left, bisect_right
from operator import itemgetter, attrgetter, methodcaller
from fractions import Fraction
from array import array

# Define the MP class
class MP:
    def __init__(self, s: str):
        self.s = s
        self.n = len(s)
        self.table = [-1] * (self.n + 1)
        j = -1
        for i in range(self.n):
            while j >= 0 and s[i]!= s[j]:
                j = self.table[j]
            j += 1
            self.table[i + 1] = j

# Define the root function
def root(i: int, uni: List[int]) -> int:
    if i == uni[i]:
        return i
    uni[i] = root(uni[i], uni)
    return uni[i]

# Define the main function
def main():
    # Set up input/output streams
    if os.getenv("MASPY") == "ますπ":
        sys.stdin = open(os.getenv("BEET_THE_HARMONY_OF_PERFECT"))
    if os.getenv("MASPYPY") == "ますπッピ":
        sys.stdout = open(os.getenv("NGTKANA_IS_GENIUS10"), "w")

    # Read strings and initialize pattern matching
    s = input()
    t = input()
    ns = len(s)
    nt = len(t)
    ss = [s] * ((nt - 1) // ns + 1)
    sss = "".join(ss) + "".join(ss)
    ok = [False] * ns
    uni = list(range(ns))
    mp = MP(t)
    m = 0
    for i in range(ns):
        ok[i] = True
        for m in range(nt):
            if t[m]!= sss[i + m]:
                ok[i] = False
                break
        if ok[i]:
            i += nt - mp.table[m]
            m = mp.table[m]
        while m >= 0 and t[m]!= sss[i + m]:
            i += m - mp.table[m]
            m = mp.table[m]
        i -= 1
        m += 1
    ans = 0
    r = rr = 0
    for i in range(ns):
        if not ok[i]:
            continue
        if not ok[(i + nt) % ns]:
            continue
        r = root(i, uni)
        rr = root((i + nt) % ns, uni)
        if rr == r:
            print(-1)
            return
        uni[rr] = r
    counter = [0] * ns
    for i in range(ns):
        r = root(i, uni)
        if not ok[r]:
            continue
        counter[r] += 1
    for i in range(ns):
        if ans < counter[i]:
            ans = counter[i]
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

