
import sys
input = sys.stdin.readline

n = int(input())
cnt = [1] * 26
MOD = 10**9 + 7
s = [input().rstrip() for _ in range(n)]

for c in s:
    cnt[ord(c) - ord('a')] += 1

ans = cnt[0]
for i in range(1, 26):
    ans *= cnt[i]
    ans %= MOD

print(ans - 1)
