
import sys

N, X = map(int, input().split())

ans = 0
min = sys.maxsize
for i in range(N):
    tmp = int(input())
    X -= tmp
    ans += 1
    if tmp < min: min = tmp

ans += X // min

print(ans)

