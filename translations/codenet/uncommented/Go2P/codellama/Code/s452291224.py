
import sys

A, B, C = map(int, sys.stdin.readline().split())
if C-A+B < 0:
    print(0)
else:
    print(C-A+B)

