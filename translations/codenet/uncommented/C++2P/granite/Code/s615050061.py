
B = 13131
N = 500000 + 7

n = int(input())
s = input()
f = [0] * (n + 1)
g = [0] * (n + 1)
cnt = 0

def pow(a, k):
    if k < 0: k += (1 << 63) - 1
    t = 1
    while k:
        if k & 1: t = t * a
        a = a * a
        k >>= 1
    return t

for i in range(1, n + 1):
    if s[i - 1] == '+' or s[i - 1] == '-':
        f[i] = f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow(B, g[i] = g[i - 1])
    else:
        f[i] = f[i - 1]
        g[i] = g[i - 1] + (1 if s[i - 1] == '<' else -1)

m = {}
for i in range(n, 0, -1):
    m[f[i]] = m.get(f[i], 0) + 1
    cnt += m[f[n] * pow(B, g[i - 1]) + f[i - 1]]

print(cnt)

