
import sys

n, k = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
# 変数未使用エラー回避
a[0] = 0

sum = k
ans = 1
while sum < n:
    sum = sum - 1 + k
    ans += 1

print(ans)

