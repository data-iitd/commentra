
n = int(input())
a = [int(x) for x in input().split()]
acc = [0] * (n + 1)
for i in range(n):
    acc[i + 1] = (acc[i] + a[i]) % MOD
ans = 0
for i in range(n):
    ans += a[i] * (MOD + acc[n] - acc[i + 1]) % MOD
    ans %= MOD
print(ans)

