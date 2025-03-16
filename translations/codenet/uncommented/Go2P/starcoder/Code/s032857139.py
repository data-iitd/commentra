
MOD = 1000000000 + 7
ALPHABET_NUM = 26

n, x = map(int, input().split())
A = list(map(int, input().split()))

A.sort()

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

