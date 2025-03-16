import sys
from collections import deque

# Define custom data types

class GraphEdge:
    def __init__(self, vertex, next_edge):
        self.vertex = vertex  # Vertex number
        self.next = next_edge  # Pointer to next edge

class DirectedGraph:
    def __init__(self, vertex_num):
        self.edge = [None] * 1  # Array of edges
        self.start = [-1] * vertex_num  # Array to store starting vertices of each edge
        self.pointer = 0  # Index to keep track of memory allocation
        self.vertex_num = vertex_num  # Number of vertices in the graph
        self.edge_max_size = 1  # Maximum size of edge array

# Function to create a new graph with given number of vertices
def new_graph(vertex_num):
    return DirectedGraph(vertex_num)

def add_edge(g, from_vertex, to_vertex):
    if g.pointer == g.edge_max_size:
        g.edge_max_size *= 2
        g.edge.extend([None] * (g.edge_max_size - len(g.edge)))  # Expand edge array

    g.edge[g.pointer] = GraphEdge(to_vertex, g.start[from_vertex])  # Add new edge to the graph
    g.start[from_vertex] = g.pointer  # Update starting vertex of the new edge
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

# Function to create a new deque
def new_deque():
    return deque()

# Function to merge two nodes
def merge(lst, j):
    # Placeholder for merge logic
    # This function needs to be defined based on the specific merging logic required
    return Node(0, 0)  # Replace with actual merging logic

def run():
    n = int(sys.stdin.readline().strip())  # Read the number of vertices from the standard input

    p = [0] * (n + 1)  # Array to store the parent pointers
    depth = [0] * (n + 1)  # Array to store the depth of each vertex
    cnt = [0] * (n + 1)  # Array to store the number of nodes at each depth

    cnt[0] = 1  # Initialize the number of nodes at depth 0

    g = new_graph(n + 1)  # Create a new graph with n+1 vertices

    for i in range(1, n + 1):
        p[i] = int(sys.stdin.readline().strip())  # Read the parent pointer for each vertex
        add_edge(g, p[i], i)  # Add an edge from the parent to the current vertex
        depth[i] = depth[p[i]] + 1  # Update the depth of the current vertex
        cnt[depth[i]] += 1  # Increment the number of nodes at the current depth

    dp = [None] * (n + 1)  # Array to store deques for each vertex
    child = [None] * (n + 1)  # Array to store the children deques for each vertex
    lst = [Node(0, 0)] * (n + 1)  # Array to store the last dp values for each vertex

    for v in range(n, -1, -1):
        if g.start[v] == -1:
            dp[v] = new_deque()  # If the vertex has no children, create a new deque for it
            dp[v].append(Node(1, 1))  # Add the initial dp values (one and zero)
            continue

        len_children = 0
        for p in range(g.start[v], -1, -1):  # Traverse children
            u = g.edge[p].vertex
            child[len_children] = dp[u]
            len_children += 1

        if len_children > 1:
            child = sorted(child[:len_children], key=lambda x: len(x))  # Sort the children deques based on their sizes

            for d in range(len(child[1])):
                j = 0
                for j in range(len_children):
                    if d < len(child[j]):
                        lst[j] = child[j][d]  # Get the last dp values from the children deques
                dp[0] = merge(lst, j)  # Merge the last dp values and update the root deque

            for j in range(1, len_children):
                del child[j]  # Free the memory of the children deques

        dp[v] = child[0]  # Update the root deque with the merged dp values
        dp[v].append(Node(1, 1))  # Add the initial dp values (one and zero)

    ans = 0  # Initialize the answer to 0

    for i in range(len(dp[0])):
        ans += (mod_pow(2, n + 1 - cnt[i]) * dp[0][i].one) % mod  # Calculate the answer using the dp values

    print(ans % mod)  # Print the answer modulo 1000000007

# Main function to run the program
if __name__ == "__main__":
    run()

# <END-OF-CODE>
