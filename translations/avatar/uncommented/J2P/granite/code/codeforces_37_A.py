
import sys
import math
import bisect
import re
import heapq
from collections import deque
from collections import Counter as CC
from itertools import combinations as Comb
from itertools import permutations as Permutation
def GCD(x, y):
    while (y):
        x, y = y, x % y
    return x
def LCM(x, y):
    return (x * y) // GCD(x, y)
mod = 100000007
# Driver Code
def main():
    n = int(input())
    d = {}
    for i in range(n):
        val = int(input())
        if val in d:
            d[val] += 1
        else:
            d[val] = 1
    max = 0
    for key, value in d.items():
        if value > max:
            max = value
    print(max, len(d))
if __name__ == "__main__":
    main()
