import sys

# Define a structure for a directed edge in the graph
class DirectedEdge:
    def __init__(self, vertex, next):
        self.vertex = vertex
        self.next = next

# Define a structure for the directed graph
class DirectedGraph:
    def __init__(self, vertex_num):
        self.edge = []
        self.start = [-1] * vertex_num
        self.pointer = 0
        self.vertex_num = vertex_num
        self.edge_max_size = 1

# Function to initialize a new graph with a given number of vertices
def new_graph(vertex_num):
    return DirectedGraph(vertex_num)

# Function to add a directed edge to the graph
def add_edge(g, from_v, to_v):
    if g.pointer == g.edge_max_size:
        g.edge_max_size *= 2
        g.edge.extend([None] * (g.edge_max_size - len(g.edge)))
    g.edge.append(DirectedEdge(to_v, g.start[from_v]))
    g.start[from_v] = g.pointer
    g.pointer += 1

# Define the modulo constant
mod = 1000000007

# Function to compute r^n % mod using exponentiation by squaring
def mod_pow(r, n):
    t = 1
    s = r
    while n > 0:
        if n & 1:
            t = (t * s) % mod
        s = (s * s) % mod
        n >>= 1
    return t

# Define a structure for a node in the dynamic programming array
class Node:
    def __init__(self, one, zero):
        self.one = one
        self.zero = zero

# Function to merge two nodes in the dynamic programming array
def merge(a, n):
    one = 0
    zero = 1
    total = 1
    for i in range(n):
        one = (one * a[i].zero + zero * a[i].one) % mod
        zero = zero * a[i].zero % mod
        total = total * (a[i].zero + a[i].one) % mod
    return Node(one, (total + mod - one) % mod)

# Define the type for values stored in the deque
DequeVal = Node

# Define a structure for the deque
class Deque:
    def __init__(self):
        self.array = []
        self.front = 0
        self.last = 0
        self.mask = 1

# Function to initialize a new deque
def new_deque():
    return Deque()

# Function to free the memory allocated for a deque
def free_deque(d):
    pass

# Function to get the number of elements in the deque
def get_size(d):
    return (d.last + (~d.front + 1)) & d.mask

# Function to reallocate the deque when necessary
def deque_realloc(d):
    array = [None] * (2 * (d.mask + 1))
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

# Function to add an element to the front of the deque
def push_front(d, v):
    if ((d.last + 1) & d.mask) == d.front:
        deque_realloc(d)
    d.front = (d.front + d.mask) & d.mask
    d.array[d.front] = v

# Function to compare the sizes of two deques
def cmp_deque_size(a, b):
    p = a[0]
    q = b[0]
    d = get_size(p) - get_size(q)
    return d if d != 0 else 0

# Function to run the main logic of the program
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
        len_child = 0
        p = g.start[v]
        while p != -1:
            u = g.edge[p].vertex
            child[len_child] = dp[u]
            len_child += 1
            p = g.edge[p].next
        if len_child > 1:
            child.sort(key=lambda x: get_size(x))
            for d in range(get_size(child[1])):
                j = 0
                while j < len_child and d < get_size(child[j]):
                    lst[j] = get_at(child[j], d)
                    j += 1
                assign_at(child[0], d, merge(lst, j))
            for j in range(1, len_child):
                free_deque(child[j])
        dp[v] = child[0]
        push_front(dp[v], Node(1, 1))
    ans = 0
    for i in range(get_size(dp[0])):
        ans += mod_pow(2, n + 1 - cnt[i]) * get_at(dp[0], i).one % mod
    print(ans % mod)

# Main function to run the program
if __name__ == "__main__":
    run()
