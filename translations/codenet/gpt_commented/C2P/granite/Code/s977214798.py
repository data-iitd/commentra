
import sys

# Function to read an integer from input
def nextint():
    c = sys.stdin.read(1) # Read a character
    # Skip non-digit characters until a digit or '-' is found
    while c!= '-' and (c < '0' or '9' < c): c = sys.stdin.read(1) 
    s = False # Flag for negative numbers
    if c == '-': # Check for negative sign
        s = True 
        c = sys.stdin.read(1) # Read the next character
    x = 0 # Variable to store the integer value
    # Convert characters to integer
    while '0' <= c and c <= '9':
        x = x * 10 + ord(c) - ord('0')
        c = sys.stdin.read(1) 
    return -x if s else x

n = nextint() # Read the number of nodes

# Function to calculate a unique identifier for a pair of nodes
def p(a, b):
    if a < b:
        return a + b * n
    else:
        return b + a * n

a = [[0] * (n - 1) for _ in range(n)] # Adjacency list representation of the graph

# Arrays to store edges and distances
e1 = [0] * (n * (n - 1) // 2)
e2 = [0] * (n * (n - 1) // 2)
d = [0] * (n * (n - 1) // 2) # Array to store computed distances
b = [False] * (n * (n - 1) // 2) # Visited flag for nodes

# Read the adjacency list from input
for i in range(n):
    for j in range(n - 1):
        a[i][j] = nextint() - 1 # Store edges, adjusting for 0-based indexing

# Build the edge representation
for i in range(n):
    for j in range(n - 2):
        from_ = p(i, a[i][j]) # Get unique index for the current edge
        to = p(i, a[i][j + 1]) # Get unique index for the next edge
        # Store the edges in e1 and e2
        if e1[from_] == 0:
            e1[from_] = to # Assign the first edge
        elif e2[from_] == 0:
            e2[from_] = to # Assign the second edge
        else:
            print(-1) # Output -1 if more than two edges are found
            sys.exit() # Exit the program

ans = 0 # Variable to store the final answer

# Compute the maximum distance for each node
for i in range(n):
    from_ = p(i, a[i][0]) # Get unique index for the starting edge
    now = f(from_) # Compute the distance
    if now < 0:
        ans = -1 # Set answer to -1 if a cycle is detected
        break # Exit the loop
    if now > ans: ans = now # Update the answer if a longer distance is found

print(ans) # Output the final answer

# Recursive function to compute the maximum distance from a given node
def f(from_):
    if b[from_]: return -1 # Return -1 if the node has already been visited (cycle detected)
    if d[from_]!= 0: return d[from_] # Return the computed distance if already calculated
    b[from_] = True # Mark the node as visited
    to = e1[from_] # Get the first edge
    max_ = 0 # Variable to track the maximum distance
    if to!= 0:
        now = f(to) # Recursively compute distance for the first edge
        if now < 0: return now # Return if a cycle is detected
        if now > max_: max_ = now # Update max if a longer distance is found
    to = e2[from_] # Get the second edge
    if to!= 0:
        now = f(to) # Recursively compute distance for the second edge
        if now < 0: return now # Return if a cycle is detected
        if now > max_: max_ = now # Update max if a longer distance is found
    b[from_] = False # Unmark the node as visited for future calls
    return d[from_] = max_ + 1 # Store and return the computed distance

The Python code is a translation of the given C code. It reads the input, builds the edge representation, and computes the maximum distance for each node using a recursive function. The final answer is then printed.