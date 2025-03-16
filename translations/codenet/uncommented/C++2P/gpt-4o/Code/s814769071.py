MOD = 10**9 + 7

n, k = map(int, input().split())
mx = n * (n + 1) // 2 - (n - k) * (n - k + 1) // 2
mn = k * (k - 1) // 2
res = 0

for i in range(k, n + 2):
    res += mx - mn + 1
    mx += n - i
    mn += i
    res %= MOD

print(res)
# <END-OF-CODE>
