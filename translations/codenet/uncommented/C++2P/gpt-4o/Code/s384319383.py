n = int(input())
cnt = [1] * 26
s = list(input().strip() for _ in range(n))

for char in s:
    cnt[ord(char) - ord('a')] += 1

ans = cnt[0]
for i in range(1, 26):
    ans *= cnt[i]
    ans %= int(1e9 + 7)

print(ans - 1)
# <END-OF-CODE>
