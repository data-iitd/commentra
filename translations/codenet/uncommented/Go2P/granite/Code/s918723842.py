
import bufio
import os
import sys

def main():
    H, W, N = map(int, input().split())
    A = max(H, W)
    print((N + A - 1) // A)

def max(a, b):
    if a < b:
        return b
    return a

def read_line():
    return sys.stdin.readline().rstrip()

def read_int():
    return int(input())

def read_ints():
    return list(map(int, input().split()))

def read_str():
    return input()

def read_strs():
    return input().split()

def debug(s):
    print(s, file=sys.stderr)

def solve():
    pass

if __name__ == '__main__':
    solve()
