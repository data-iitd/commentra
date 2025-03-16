import sys
import io
import os
import math

def input():
    return sys.stdin.readline()

def read_int():
    return int(input())

def read_ints():
    return list(map(int, input().split()))

def solve(n, k, logs_length):
    left, right = 1, int(1e9) + 1000
    while left < right:
        mid = (left + right) // 2
        if not need_it(mid, logs_length, k):
            left = mid + 1
        else:
            right = mid
    print(left)

def need_it(mid, logs_length, k):
    for log in logs_length:
        k -= (log + mid - 1) // mid - 1
    return k >= 0

def main():
    n, k = read_ints()
    logs_length = read_ints()
    solve(n, k, logs_length)

if __name__ == "__main__":
    main()
