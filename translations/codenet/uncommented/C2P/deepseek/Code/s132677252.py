import sys
import array

mod = 1000000007

class Node:
    def __init__(self, one=0, zero=0):
        self.one = one
        self.zero = zero

def mod_pow(r, n):
    t = 1
    s = r
    while n > 0:
        if n & 1:
            t = (t * s) % mod
        s = (s * s) % mod
        n >>= 1
    return t

def merge(a, n):
    one = 0
    zero = 1
    total = 1
    for i in range(n):
        one = (one * a[i].zero + zero * a[i].one) % mod
        zero = zero * a[i].zero % mod
        total = total * (a[i].zero + a[i].one) % mod
    return Node(one, (total + mod - one) % mod)

class Deque:
    def __init__(self):
        self.array = []
        self.front = 0
        self.last = 0

    def get_size(self):
        return (self.last + (~self.front + 1)) & (len(self.array) - 1)

    def deque_realloc(self):
        array = [Node() for _ in range(2 * (len(self.array) - 1))]
        k = 0
        for i in range(self.front, self.last):
            array[k] = self.array[i]
            k += 1
        self.array = array
        self.front = 0
        self.last = k

    def get_at(self, x):
        return self.array[(self.front + x) & (len(self.array) - 1)]

    def assign_at(self, x, v):
        self.array[(self.front + x) & (len(self.array) - 1)] = v

    def push_front(self, v):
        if ((self.last + 1) & (len(self.array) - 1)) == self.front:
            self.deque_realloc()
        self.front = (self.front + len(self.array) - 1) & (len(self.array) - 1)
        self.array[self.front] = v

def run():
    n = int(sys.stdin.readline().strip())
    p = array.array('i', [0] * (n + 1))
    depth = array.array('i', [0] * (n + 1))
    cnt = array.array('i', [0] * (n + 1))
    cnt[0] = 1
    g = []
    for _ in range(n + 1):
        g.append(Deque())
    for i in range(1, n + 1):
        p[i] = int(sys.stdin.readline().strip())
        g[p[i]].push_front(Node(1, 1))
        depth[i] = depth[p[i]] + 1
        cnt[depth[i]] += 1

    dp = [Deque() for _ in range(n + 1)]
    child = [Deque() for _ in range(n + 1)]
    lst = [Node() for _ in range(n + 1)]
    for i in range(n, -1, -1):
        v = i
        if len(g[v]) == 0:
            dp[v].push_front(Node(1, 1))
            continue
        len_child = 0
        for p in g[v]:
            child[len_child] = p
            len_child += 1
        if len_child > 1:
            child.sort(key=lambda x: x.get_size())
            for d in range(child[1].get_size()):
                j = 0
                for k in range(len_child):
                    lst[j] = child[k].get_at(d)
                    j += 1
                child[0].assign_at(d, merge(lst, j))
            for j in range(1, len_child):
                child[j] = None
        dp[v] = child[0]
        dp[v].push_front(Node(1, 1))

    ans = 0
    for i in range(dp[0].get_size()):
        ans += mod_pow(2, n + 1 - cnt[i]) * dp[0].get_at(i).one % mod
    print(ans % mod)

if __name__ == "__main__":
    run()
