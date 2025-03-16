

import sys

mod = 1000000007

def mod_pow(r, n):
    t = 1
    s = r
    while n > 0:
        if n & 1:
            t = (t * s) % mod
        s = (s * s) % mod
        n >>= 1
    return t

class Deque:
    def __init__(self):
        self.array = []
        self.front = 0
        self.last = 0
        self.mask = 1

    def get_size(self):
        return (self.last + (~self.front + 1)) & self.mask

    def deque_realloc(self):
        array = [0] * (2 * (self.mask + 1))
        k = 0
        for i in range(self.front, self.last):
            array[k] = self.array[i]
            k += 1
        self.array = array
        self.front = 0
        self.last = k
        self.mask = 2 * self.mask + 1

    def get_at(self, x):
        return self.array[(self.front + x) & self.mask]

    def assign_at(self, x, v):
        self.array[(self.front + x) & self.mask] = v

    def push_front(self, v):
        if((self.last + 1) & self.mask) == self.front:
            self.deque_realloc()
        self.front = (self.front + self.mask) & self.mask
        self.array[self.front] = v

def run():
    n = int(input())
    p = [0] * (n + 1)
    depth = [0] * (n + 1)
    cnt = [0] * (n + 1)
    cnt[0] = 1
    g = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        p[i] = int(input())
        g[p[i]].append(i)
        depth[i] = depth[p[i]] + 1
        cnt[depth[i]] += 1
    dp = [Deque() for _ in range(n + 1)]
    child = [Deque() for _ in range(n + 1)]
    lst = [0] * (n + 1)
    for v in range(n, -1, -1):
        if len(g[v]) == 0:
            dp[v].push_front((1, 1))
            continue
        len = 0
        for p in g[v]:
            u = p
            child[len].push_front(dp[u].get_at(0))
            len += 1
        child.sort(key=lambda x: x.get_size())
        for d in range(child[1].get_size()):
            j = 0
            for i in range(len):
                if d < child[i].get_size():
                    lst[j] = child[i].get_at(d)
                    j += 1
            dp[v].push_front(merge(lst[:j]))
        for i in range(1, len):
            del child[i].array[:]
        ans = 0
        for i in range(dp[v].get_size()):
            ans += (mod_pow(2, n + 1 - cnt[i]) * dp[v].get_at(i)[0]) % mod
        print(ans % mod)

def merge(lst):
    one = 0
    zero = 1
    total = 1
    for i in range(len(lst)):
        one = (one * lst[i][1] + zero * lst[i][0]) % mod
        zero = zero * lst[i][1] % mod
        total = total * (lst[i][0] + lst[i][1]) % mod
    return (one, (total + mod - one) % mod)

if __name__ == "__main__":
    run()
