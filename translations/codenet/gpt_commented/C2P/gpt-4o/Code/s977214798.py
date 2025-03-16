import sys

# Function to read an integer from input
def nextint():
    return int(sys.stdin.readline().strip())

n = nextint()  # Read the number of nodes

# Adjacency list representation of the graph
a = [[0] * (n - 1) for _ in range(n)]

# Read the adjacency list from input
for i in range(n):
    a[i] = [nextint() - 1 for _ in range(n - 1)]  # Store edges, adjusting for 0-based indexing

# Arrays to store edges and distances
e1 = [0] * (1000000)
e2 = [0] * (1000000)
d = [0] * (1000000)  # Array to store computed distances
b = [False] * (1000000)  # Visited flag for nodes

# Function to calculate a unique identifier for a pair of nodes
def p(a, b):
    if a < b:
        return a + b * n  # Return a unique index based on the order of a and b
    else:
        return b + a * n  # Return a unique index based on the order of a and b

# Recursive function to compute the maximum distance from a given node
def f(from_node):
    if b[from_node]: 
        return -1  # Return -1 if the node has already been visited (cycle detected)
    if d[from_node]: 
        return d[from_node]  # Return the computed distance if already calculated
    b[from_node] = True  # Mark the node as visited
    max_distance = 0  # Variable to track the maximum distance

    # Get the first edge
    to = e1[from_node]
    if to != 0:
        now = f(to)  # Recursively compute distance for the first edge
        if now < 0: 
            return now  # Return if a cycle is detected
        if now > max_distance: 
            max_distance = now  # Update max if a longer distance is found

    # Get the second edge
    to = e2[from_node]
    if to != 0:
        now = f(to)  # Recursively compute distance for the second edge
        if now < 0: 
            return now  # Return if a cycle is detected
        if now > max_distance: 
            max_distance = now  # Update max if a longer distance is found

    b[from_node] = False  # Unmark the node as visited for future calls
    d[from_node] = max_distance + 1  # Store and return the computed distance
    return d[from_node]

# Build the edge representation
for i in range(n):
    for j in range(n - 2):
        from_edge = p(i, a[i][j])  # Get unique index for the current edge
        to_edge = p(i, a[i][j + 1])  # Get unique index for the next edge
        # Store the edges in e1 and e2
        if e1[from_edge] == 0:
            e1[from_edge] = to_edge  # Assign the first edge
        elif e2[from_edge] == 0:
            e2[from_edge] = to_edge  # Assign the second edge
        else:
            print("-1")  # Output -1 if more than two edges are found
            sys.exit(0)  # Exit the program

ans = 0  # Variable to store the final answer
# Compute the maximum distance for each node
for i in range(n):
    from_edge = p(i, a[i][0])  # Get unique index for the starting edge
    now = f(from_edge)  # Compute the distance
    if now < 0:
        ans = -1  # Set answer to -1 if a cycle is detected
        break  # Exit the loop
    if now > ans: 
        ans = now  # Update the answer if a longer distance is found

print(ans)  # Output the final answer
# <END-OF-CODE>
