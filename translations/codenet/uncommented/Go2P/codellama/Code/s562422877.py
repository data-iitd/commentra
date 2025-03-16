
import sys

N = int(sys.stdin.readline().strip())
A = list(map(int, sys.stdin.readline().strip().split()))

A.sort()

ans = 0
for i in range(1, N):
    ans += A[i] - A[i-1]

print(ans)

