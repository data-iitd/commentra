import sys
import io
import os
import math
import heapq
import bisect
import itertools
from collections import deque

input = sys.stdin.readline

def solve():
    t = int(input())
    arr = [int(input()) for _ in range(t)]
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

# Call the solve function
solve()
