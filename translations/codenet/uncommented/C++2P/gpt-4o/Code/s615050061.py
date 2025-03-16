from collections import defaultdict

B = 13131
N = 500000 + 7

def pow_mod(a, k):
    if k < 0:
        k += (1 << 63) - 1
    t = 1
    while k:
        if k & 1:
            t *= a
        a *= a
        k >>= 1
    return t

def main():
    n = int(input())
    s = input().strip()
    f = [0] * N
    g = [0] * N
    map_count = defaultdict(int)
    cnt = 0

    for i in range(1, n + 1):
        if s[i - 1] == '+' or s[i - 1] == '-':
            f[i] = f[i - 1] + (1 if s[i - 1] == '+' else -1) * pow_mod(B, g[i])
            g[i] = g[i - 1]
        else:
            f[i] = f[i - 1]
            g[i] = g[i - 1] + (-1 if s[i - 1] == '<' else 1)

    for i in range(n, 0, -1):
        map_count[f[i]] += 1
        cnt += map_count[f[n] * pow_mod(B, g[i - 1]) + f[i - 1]]

    print(cnt)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
