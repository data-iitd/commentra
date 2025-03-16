import sys
from collections import deque

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

class Node:
    def __init__(self, one=0, zero=0):
        self.one = one
        self.zero = zero

def merge(a):
    one = 0
    zero = 1
    total = 1
    for node in a:
        one = (one * node.zero + zero * node.one) % mod
        zero = (zero * node.zero) % mod
        total = (total * (node.zero + node.one)) % mod
    return Node(one, (total + mod - one) % mod)

class Graph:
    def __init__(self, vertex_num):
        self.edge = []
        self.start = [-1] * vertex_num
        self.pointer = 0
        self.vertex_num = vertex_num
        self.edge_max_size = 1

    def add_edge(self, from_vertex, to_vertex):
        if self.pointer == self.edge_max_size:
            self.edge_max_size *= 2
            self.edge.extend([None] * (self.edge_max_size - len(self.edge)))
        self.edge[self.pointer] = (to_vertex, self.start[from_vertex])
        self.start[from_vertex] = self.pointer
        self.pointer += 1

def run():
    n = int(sys.stdin.readline().strip())
    p = [0] * (n + 1)
    depth = [0] * (n + 1)
    cnt = [0] * (n + 1)
    cnt[0] = 1
    g = Graph(n + 1)

    for i in range(1, n + 1):
        p[i] = int(sys.stdin.readline().strip())
        g.add_edge(p[i], i)
        depth[i] = depth[p[i]] + 1
        cnt[depth[i]] += 1

    dp = [None] * (n + 1)
    child = [None] * (n + 1)
    lst = [Node() for _ in range(n + 1)]

    for v in range(n, -1, -1):
        if g.start[v] == -1:
            dp[v] = deque()
            dp[v].append(Node(1, 1))
            continue

        len_child = 0
        for p in range(g.start[v], -1, g.edge[p][1] if p < g.pointer else -1):
            u = g.edge[p][0]
            child[len_child] = dp[u]
            len_child += 1

        if len_child > 1:
            child = sorted(child[:len_child], key=lambda x: len(x))
            for d in range(len(child[1])):
                j = 0
                for j in range(len_child):
                    if d < len(child[j]):
                        lst[j] = child[j][d]
                assign_at(child[0], d, merge(lst[:j]))

            for j in range(1, len_child):
                child[j] = None  # Freeing the deque

        dp[v] = child[0]
        dp[v].appendleft(Node(1, 1))

    ans = 0
    for i in range(len(dp[0])):
        ans += (mod_pow(2, n + 1 - cnt[i]) * dp[0][i].one) % mod

    print(ans % mod)

if __name__ == "__main__":
    run()

# <END-OF-CODE>
