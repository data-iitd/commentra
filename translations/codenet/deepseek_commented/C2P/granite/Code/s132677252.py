
import sys

MOD = 1000000007

def mod_pow(r, n):
    t = 1
    s = r
    while n > 0:
        if n & 1:
            t = (t * s) % MOD
        s = (s * s) % MOD
        n >>= 1
    return t

def merge(a, n):
    one = 0
    zero = 1
    total = 1
    for i in range(n):
        one = (one * a[i][1] + zero * a[i][0]) % MOD
        zero = (zero * a[i][1]) % MOD
        total = (total * (a[i][0] + a[i][1])) % MOD
    return (one, (total + MOD - one) % MOD)

class Deque:
    def __init__(self):
        self.array = []
        self.front = 0
        self.last = 0
        self.mask = 1

    def get_size(self):
        return (self.last + (~self.front + 1)) & self.mask

    def realloc(self):
        new_array = [0] * (2 * (self.mask + 1))
        k = 0
        for i in range(self.front, self.last):
            new_array[k] = self.array[i]
            k += 1
        self.array = new_array
        self.front = 0
        self.last = k
        self.mask = 2 * self.mask + 1

    def get_at(self, x):
        return self.array[(self.front + x) & self.mask]

    def assign_at(self, x, v):
        self.array[(self.front + x) & self.mask] = v

    def push_front(self, v):
        if (self.last + 1) & self.mask == self.front:
            self.realloc()
        self.front = (self.front + self.mask) & self.mask
        self.array[self.front] = v

def run():
    n = int(input())
    parent = [0] * (n + 1)
    depth = [0] * (n + 1)
    cnt = [0] * (n + 1)
    cnt[0] = 1
    graph = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        parent[i] = int(input())
        graph[parent[i]].append(i)
        depth[i] = depth[parent[i]] + 1
        cnt[depth[i]] += 1
    dp = [Deque() for _ in range(n + 1)]
    child = [Deque() for _ in range(n + 1)]
    lst = [0] * (n + 1)
    for i in range(n, -1, -1):
        if len(graph[i]) == 0:
            dp[i].push_front((1, 1))
            continue
        for j in graph[i]:
            child[j] = dp[j]
        child.sort(key=lambda x: x.get_size())
        for d in range(child[1].get_size()):
            j = 0
            for k in range(len(child)):
                if d < child[k].get_size():
                    lst[j] = child[k].get_at(d)
                    j += 1
            dp[i].assign_at(d, merge(lst[:j], j))
        for j in range(1, len(child)):
            del child[j].array
        dp[i] = child[0]
        dp[i].push_front((1, 1))
    ans = 0
    for i in range(dp[0].get_size()):
        ans += (mod_pow(2, n + 1 - cnt[i]) * dp[0].get_at(i)[0]) % MOD
    print(ans % MOD)

if __name__ == "__main__":
    run()

