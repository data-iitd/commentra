import sys
import math
import collections
import bisect
import heapq
import time
import random
import itertools
import functools
import operator
import re
import string
import queue
import threading
import concurrent.futures
import copy

def calculateMaxOfMin(arr, n):
    s = []
    left = [-1] * n
    right = [n] * n
    ans = [0] * (n + 1)
    for i in range(n):
        left[i] = -1
        right[i] = n
    for i in range(n):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
            left[i] = s[-1]
        s.append(i)
    s.clear()
    for i in range(n - 1, -1, -1):
        while s and arr[s[-1]] >= arr[i]:
            s.pop()
        if s:
            right[i] = s[-1]
        s.append(i)
    for i in range(n):
        len = right[i] - left[i] - 1
        ans[len] = max(ans[len], arr[i])
    for i in range(n - 1, 0, -1):
        ans[i] = max(ans[i], ans[i + 1])
    return ans

if __name__ == "__main__":
    n = int(input())
    arr = [int(x) for x in input().split()]
    result = calculateMaxOfMin(arr, n)
    for i in range(1, n + 1):
        print(result[i], end=" ")

