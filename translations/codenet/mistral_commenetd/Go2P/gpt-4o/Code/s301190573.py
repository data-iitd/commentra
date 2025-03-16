import sys

# Function to read a single line from the standard input
def next_line():
    return sys.stdin.readline().strip()

# Function to read two integers from a single line
def next_ints():
    return map(int, next_line().split())

# Function to read an array of integers from a single line
def next_int_array():
    return list(map(int, next_line().split()))

# Initialize arrays for parent and rank
par = []
rank = []

# Function to initialize arrays
def initialize(n):
    global par, rank
    par = list(range(n))
    rank = [0] * n

# Function to find the root of a node
def root(i):
    if par[i] == i:
        return i
    par[i] = root(par[i])  # Path compression
    return par[i]

# Function to check if two nodes have the same parent
def same(i, j):
    return root(i) == root(j)

# Function to unite two nodes
def unite(i, j):
    global par, rank
    i = root(i)
    j = root(j)
    if i == j:
        return
    if rank[i] < rank[j]:
        par[i] = j
    else:
        par[j] = i
        if rank[i] == rank[j]:
            rank[i] += 1

# Main function
def main():
    # Read number of nodes and edges
    n, m = next_ints()
    # Read array of edges
    p = next_int_array()
    # Initialize arrays
    initialize(n)
    # Process each edge by uniting their parents
    for _ in range(m):
        x, y = next_ints()
        unite(x - 1, y - 1)
    # Count the number of disconnected components
    s = sum(1 for i in range(n) if same(i, p[i] - 1))
    # Print the result
    print(s)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
