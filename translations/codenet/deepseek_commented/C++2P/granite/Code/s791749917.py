
import sys

H, W = map(int, sys.stdin.readline().split())

ans = 0
if H == 1 or W == 1:
    ans = 1
else:
    m = H * W
    if m % 2 == 0:
        ans = m // 2
    else:
        ans = m // 2 + 1

print(ans)
