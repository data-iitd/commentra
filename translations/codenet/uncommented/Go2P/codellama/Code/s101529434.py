
import sys

K, X = map(int, sys.stdin.readline().split())
if 500*K >= X:
    print("Yes")
else:
    print("No")

