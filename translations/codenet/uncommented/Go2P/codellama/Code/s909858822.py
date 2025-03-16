
import sys

A, B = map(int, sys.stdin.readline().split())

ans = 0
if 6 <= A <= 12:
    ans = B // 2
elif 12 < A:
    ans = B

print(ans)

