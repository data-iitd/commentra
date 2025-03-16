import sys
import math

# Define custom data types

class DirectedEdge:
    def __init__(self, vertex, next_edge):
        self.vertex = vertex
        self.next_edge = next_edge

class DirectedGraph:
    def __init__(self, vertex_num):
        self.edge = []
        self.start = [-1] * vertex_num
        self.pointer = 0
        self.vertex_num = vertex_num
        self.edge_max_size = 1

# Function to create a new graph with given number of vertices

def new_graph(vertex_num):
    return DirectedGraph(vertex_num)

# Function to add an edge between two vertices

def add_edge(g, from_vertex, to_vertex):
    if g.pointer == g.edge_max_size:
        g.edge_max_size *= 2
        g.edge.extend([None] * (g.edge_max_size - len(g.edge)))
    g.edge.append(DirectedEdge(to_vertex, g.start[from_vertex]))
    g.start[from_vertex] = g.pointer
    g.pointer += 1

# Define a constant for modular arithmetic

mod = 1000000007

# Function to compute modular exponentiation

def mod_pow(r, n):
    t = 1
    s = r
    while n > 0:
        if n & 1:
            t = (t * s) % mod
        s = (s * s) % mod
        n >>= 1
    return t

# Define a custom data structure for dynamic programming

class Node:
    def __init__(self, one, zero):
        self.one = one
        self.zero = zero

# Define a custom deque data structure

class Deque:
    def __init__(self):
        self.array = []
        self.front = 0
        self.last = 0
        self.mask = 1

    def new_deque(self):
        return Deque()

    def free_deque(self):
        del self.array

    def get_size(self):
        return (self.last + (~self.front + 1)) & self.mask

    def deque_realloc(self):
        array = [None] * (2 * (self.mask + 1))
        k = 0
        for i in range(self.front, self.last):
            array[k] = self.array[i]
            k += 1
        del self.array
        self.array = array
        self.front = 0
        self.last = k
        self.mask = 2 * self.mask + 1

    def get_at(self, x):
        return self.array[(self.front + x) & self.mask]

    def assign_at(self, x, v):
        self.array[(self.front + x) & self.mask] = v

    def push_front(self, v):
        if ((self.last + 1) & self.mask) == self.front:
            self.deque_realloc()
        self.front = (self.front + self.mask) & self.mask
        self.array[self.front] = v

    def cmp_deque_size(self, a, b):
        d = get_size(a) - get_size(b)
        return -1 if d == 0 else 1 if d > 0 else -1

# Main function to run the program

def run():
    n = int(input().strip())
    p = [0] * (n + 1)
    depth = [0] * (n + 1)
    cnt = [0] * (n + 1)
    cnt[0] = 1
    g = new_graph(n + 1)
    for i in range(1, n + 1):
        p[i] = int(input().strip())
        add_edge(g, p[i], i)
        depth[i] = depth[p[i]] + 1
        cnt[depth[i]] += 1
    dp = [None] * (n + 1)
    child = [None] * (n + 1)
    lst = [None] * (n + 1)
    for i in range(n, -1, -1):
        v = i
        if g.start[v] == -1:
            dp[v] = Deque()
            dp[v].push_front(Node(1, 1))
            continue
        len_ = 0
        p_ = g.start[v]
        while p_ != -1:
            u = g.edge[p_].vertex
            child[len_] = dp[u]
            len_ += 1
            p_ = g.edge[p_].next_edge
        if len_ > 1:
            child.sort(key=get_size)
            for d in range(get_size(child[1])):
                j = 0
                for