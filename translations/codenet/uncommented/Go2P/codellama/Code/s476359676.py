
import sys

n = int(sys.stdin.readline())

ans = 0
aPrev = 0
for i in range(n):
    a = int(sys.stdin.readline())
    if a > i or a > aPrev+1:
        print(-1)
        sys.exit()
    elif a == aPrev+1:
        ans += 1
    else:
        ans += a
    aPrev = a

print(ans)

