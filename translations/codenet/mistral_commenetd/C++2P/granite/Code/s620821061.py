

import sys
from math import gcd

def bit_matching(n, m, a, b):
    G = [[] for _ in range(2 * n)]
    match = [-1] * (2 * n)
    used = [False] * (2 * n)

    def dfs(v):
        used[v] = True
        for u in G[v]:
            w = match[u]
            if w < 0 or not used[w] and dfs(w):
                match[v] = u
                match[u] = v
                return True
        return False

    for i in range(n):
        for j in range(m):
            if gcd(a[i], b[j])!= 1:
                G[i].append(n + j)
                G[n + j].append(i)

    res = 0
    for v in range(n):
        if match[v] < 0:
            used = [False] * (2 * n)
            if dfs(v):
                res += 1

    return res

if __name__ == "__main__":
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n, m = data[0], data[1]
    a = data[2:2 + n]
    b = data[2 + n:]
    print(bit_matching(n, m, a, b))

