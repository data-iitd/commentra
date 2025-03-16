
import sys
import math

n, x = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))

A.sort()

# S = [0] * n
# sum = 0
# for i in range(n):
#     sum += A[i]
#     S[i] = sum

ans = 0
for i in range(n):
    if x >= A[i]:
        ans += 1
        x -= A[i]
    else:
        break
if ans == n and x > 0:
    ans -= 1

print(ans)

