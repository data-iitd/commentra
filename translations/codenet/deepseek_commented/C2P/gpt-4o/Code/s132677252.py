import sys
from collections import deque

mod = 1000000007

# Define a class for a directed edge in the graph
class GraphEdge:
    def __init__(self, vertex, next_edge):
        self.vertex = vertex  # The destination vertex of the edge
        self.next = next_edge  # The index of the next edge in the adjacency list

# Define a class for the directed graph
class DirectedGraph:
    def __init__(self, vertex_num):
        self.edge = [None] * 1  # Array of edges
        self.start = [-1] * vertex_num  # Array of start pointers for each vertex
        self.pointer = 0  # Current number of edges
        self.vertex_num = vertex_num  # Number of vertices
        self.edge_max_size = 1  # Maximum size of the edge array

    def add_edge(self, from_vertex, to_vertex):
        if self.pointer == self.edge_max_size:
            self.edge_max_size *= 2
            self.edge.extend([None] * (self.edge_max_size - len(self.edge)))
        self.edge[self.pointer] = GraphEdge(to_vertex, self.start[from_vertex])  # Set the new edge
        self.start[from_vertex] = self.pointer  # Update the start pointer to the new edge
        self.pointer += 1

# Function to compute r^n % mod using exponentiation by squaring
def mod_pow(r, n):
    t = 1
    s = r
    while n > 0:
        if n & 1:
            t = (t * s) % mod  # If n is odd, multiply t by s
        s = (s * s) % mod  # Square s
        n >>= 1  # Halve n
    return t

# Define a class for a node in the dynamic programming array
class DPNode:
    def __init__(self, one, zero):
        self.one = one  # Number of ways to have exactly one edge
        self.zero = zero  # Number of ways to have exactly zero edges

# Function to merge two nodes in the dynamic programming array
def merge(nodes):
    one = 0
    zero = 1
    total = 1
    for node in nodes:
        one = (one * node.zero + zero * node.one) % mod  # Calculate the number of ways to have exactly one edge
        zero = (zero * node.zero) % mod  # Calculate the number of ways to have exactly zero edges
        total = (total * (node.zero + node.one)) % mod  # Calculate the total number of ways
    return DPNode(one, (total + mod - one) % mod)  # Return the merged node

# Function to run the main logic of the program
def run():
    n = int(sys.stdin.readline().strip())  # Read the number of vertices
    p = [0] * (n + 1)  # Array to store parent pointers
    depth = [0] * (n + 1)  # Array to store depths of vertices
    cnt = [0] * (n + 1)  # Array to count vertices at each depth
    cnt[0] = 1  # There is one way to have zero edges (the root itself)
    g = DirectedGraph(n + 1)  # Initialize the graph

    for i in range(1, n + 1):
        p[i] = int(sys.stdin.readline().strip())  # Read the parent of each vertex
        g.add_edge(p[i], i)  # Add the edge to the graph
        depth[i] = depth[p[i]] + 1  # Calculate the depth of each vertex
        cnt[depth[i]] += 1  # Increment the count of vertices at the current depth

    dp = [None] * (n + 1)  # Array to store dynamic programming results
    child = [None] * (n + 1)  # Array to store child deques
    lst = [None] * (n + 1)  # Array to store merged nodes

    for v in range(n, -1, -1):
        if g.start[v] == -1:
            dp[v] = deque()
            dp[v].append(DPNode(1, 1))  # Initialize the dp array for leaf nodes
            continue

        len_children = 0
        for p in range(g.start[v], -1, -1):  # Collect child deques
            u = g.edge[p].vertex
            child[len_children] = dp[u]
            len_children += 1

        if len_children > 1:
            child.sort(key=lambda x: len(x))  # Sort child deques by size
            for d in range(len(child[1])):
                j = 0
                for j in range(len_children):
                    if d < len(child[j]):
                        lst[j] = child[j][d]  # Get nodes at the current depth
                dp[v].append(merge(lst[:j]))  # Merge nodes and assign to the first child deque

            for j in range(1, len_children):
                child[j] = None  # Free memory of unused child deques

        dp[v].append(DPNode(1, 1))  # Add the current node to the dp array

    ans = 0
    for i in range(len(dp[0])):
        ans += (mod_pow(2, n + 1 - cnt[i]) * dp[0][i].one) % mod  # Calculate the answer

    print(ans % mod)  # Print the result

# Main function to run the program
if __name__ == "__main__":
    run()

# <END-OF-CODE>
