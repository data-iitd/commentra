
import sys
input = sys.stdin.readline

MOD = 10**9 + 7

n = int(input())
s = input().strip()

cnt = [1] * 26
for c in s:
    cnt[ord(c) - ord('a')] += 1

ans = cnt[0]
for i in range(1, 26):
    ans *= cnt[i]
    ans %= MOD

print(ans - 1)
