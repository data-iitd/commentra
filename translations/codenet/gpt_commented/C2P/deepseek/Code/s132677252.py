import sys

# Define types for 32-bit and 64-bit integers
i32 = int
i64 = int

# Structure to represent a directed edge in the graph
class DirectedEdge:
    def __init__(self, vertex, next):
        self.vertex = vertex
        self.next = next

# Structure to represent a directed graph
class DirectedGraph:
    def __init__(self, vertex_num):
        self.edge = []
        self.start = [-1] * vertex_num
        self.pointer = 0
        self.vertex_num = vertex_num
        self.edge_max_size = 1

# Function to create a new directed graph with a specified number of vertices
def new_graph(vertex_num):
    g = DirectedGraph(vertex_num)
    g.edge = [DirectedEdge(0, 0)] * 1
    g.start = [-1] * vertex_num
    g.pointer = 0
    g.vertex_num = vertex_num
    g.edge_max_size = 1
    for i in range(vertex_num):
        g.start[i] = -1
    return g

# Function to add a directed edge from 'from' to 'to' in the graph
def add_edge(g, frm, to):
    if g.pointer == g.edge_max_size:
        g.edge_max_size *= 2
        g.edge = [DirectedEdge(0, 0)] * g.edge_max_size
    g.edge.append(DirectedEdge(to, g.start[frm]))
    g.start[frm] = g.pointer
    g.pointer += 1

# Define a constant for modulo operations
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

# Structure to represent a node in dynamic programming
class Node:
    def __init__(self, one, zero):
        self.one = one
        self.zero = zero

# Function to merge multiple dp nodes
def merge(a, n):
    one = 0
    zero = 1
    total = 1
    for i in range(n):
        one = (one * a[i].zero + zero * a[i].one) % mod
        zero = zero * a[i].zero % mod
        total = total * (a[i].zero + a[i].one) % mod
    return Node(one, (total + mod - one) % mod)

# Structure to represent a deque (double-ended queue)
class Deque:
    def __init__(self):
        self.array = [Node(0, 0)] * 2
        self.front = 0
        self.last = 0
        self.mask = 1

# Function to create a new deque
def new_deque():
    return Deque()

# Function to free the memory allocated for a deque
def free_deque(d):
    pass

# Function to get the size of the deque
def get_size(d):
    return (d.last + (~d.front + 1)) & d.mask

# Function to reallocate memory for the deque when it is full
def deque_realloc(d):
    array = [Node(0, 0)] * (2 * (d.mask + 1))
    k = 0
    for i in range(d.front, d.last):
        array[k] = d.array[i]
        k += 1
    d.array = array
    d.front = 0
    d.last = k
    d.mask = 2 * d.mask + 1

# Function to get the value at a specific index in the deque
def get_at(d, x):
    return d.array[(d.front + x) & d.mask]

# Function to assign a value at a specific index in the deque
def assign_at(d, x, v):
    d.array[(d.front + x) & d.mask] = v

# Function to push a value to the front of the deque
def push_front(d, v):
    if ((d.last + 1) & d.mask) == d.front:
        deque_realloc(d)
    d.front = (d.front + d.mask) & d.mask
    d.array[d.front] = v

# Comparison function for sorting deques based on their size
def cmp_deque_size(a, b):
    p = a[0]
    q = b[0]
    d = get_size(p) - get_size(q)
    return -1 if d == 0 else 1 if d > 0 else 1

# Main function to run the algorithm
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
    lst = [Node(0, 0)] * (n + 1)
    for i in range(n, -1, -1):
        v = i
        if g.start[v] == -1:
            dp[v] = new_deque()
            push_front(dp[v], Node(1, 1))
            continue
        len = 0
        p = g.start[v]
        while p != -1:
            u = g.edge[p].vertex
            child[len] = dp[u]
            len += 1
            p = g.edge[p].next
        if len > 1:
            child.sort(key=lambda x: get_size(x))
            for d in range(get_size(child[1])):
                j = 0
                for k in range(len):
                    lst[j] = get_at(child[k], d)
                    j += 1
                assign_at(child[0], d, merge(lst, j))
            for j in range(1, len):
                free_deque(child[j])
        dp[v] = child[0]
        push_front(dp[v], Node(1, 1))
    ans = 0
    for i in range(get_size(dp[0])):
        ans += mod_pow(2, n + 1 - cnt[i]) * get_at(dp[0], i).one % mod
    print(ans % mod)

# Main function to execute the program
if __name__ == "__main__":
    run()
