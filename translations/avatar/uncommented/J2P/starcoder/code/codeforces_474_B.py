
# <START-OF-CODE>

import sys

def fun(arr, q, n, m):
    i = 0
    j = n
    while i <= j:
        md = i + (j - i) / 2
        if arr[md] == q:
            return md
        elif arr[md] > q:
            j = md - 1
        else:
            i = md + 1
    return -1

n = int(raw_input())
arr = [0] * n
arr[0] = int(raw_input())
for i in range(1, n):
    arr[i] = int(raw_input()) + arr[i-1]
m = int(raw_input())
q = [0] * m
for i in range(m):
    q[i] = int(raw_input())
for k in range(m):
    print fun(arr, q[k], n, m) + 1

# 