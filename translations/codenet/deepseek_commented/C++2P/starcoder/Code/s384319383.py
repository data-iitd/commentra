n = int(input())
s = input()
cnt = [1] * 26
for i in s:
    cnt[ord(i) - ord('a')] += 1
ans = cnt[0]
for i in range(1, 26):
    ans *= cnt[i]
    ans %= MOD
print(ans - 1)

