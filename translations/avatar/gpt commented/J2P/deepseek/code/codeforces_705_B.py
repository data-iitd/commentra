import sys
import io
import os
import math
import random
import re
from collections import defaultdict, Counter, deque
from itertools import accumulate, permutations, combinations, product, combinations_with_replacement

input = sys.stdin.readline

def solve():
    t = int(input())
    arr = list(map(int, input().split()))
    
    prev_winner = 0
    
    for i in range(t):
        if arr[i] == 1:
            if prev_winner == 0:
                prev_winner = 2
        if prev_winner == 2 or prev_winner == 0:
            if (arr[i] - 1) % 2 == 0:
                print(2)
                prev_winner = 2
            else:
                print(1)
                prev_winner = 1
        else:
            if (arr[i] - 1) % 2 == 0:
                print(1)
                prev_winner = 1
            else:
                print(2)
                prev_winner = 2

# Read the number of test cases
t = 1
while t > 0:
    solve()
    t -= 1
