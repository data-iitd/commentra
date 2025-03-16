
import sys

n, k = map(int, sys.stdin.readline().split())
cnt = [0] * (100000 * 2 + 13)

for _ in range(n):
    x = int(sys.stdin.readline())
    cnt[x] += 1

a = [cnt[i] for i in range(len(cnt)) if cnt[i] > 0]
a.sort()

ans = sum(a[:len(a) - k])
print(ans)

