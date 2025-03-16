import sys

# Function to read an integer from input
def nextint():
    c = sys.stdin.read(1)  # Read a character
    while c not in ('-', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'):
        c = sys.stdin.read(1)
    s = False
    if c == '-':
        s = True
        c = sys.stdin.read(1)
    x = 0
    while '0' <= c <= '9':
        x = x * 10 + int(c)
        c = sys.stdin.read(1)
    return -x if s else x

n = 0  # Variable to store the number of nodes

# Function to calculate a unique identifier for a pair of nodes
def p(a, b):
    return a + b * n if a < b else b + a * n

# Arrays to store edges and distances
e1 = [0] * 1000000
e2 = [0] * 1000000
d = [0] * 1000000  # Array to store computed distances
b = [False] * 1000000  # Visited flag for nodes

# Recursive function to compute the maximum distance from a given node
def f(from_):
    if b[from_]: return -1  # Return -1 if the node has already been visited (cycle detected)
    if d[from_]: return d[from_]  # Return the computed distance if already calculated
    b[from_] = True  # Mark the node as visited
    to = e1[from_]  # Get the first edge
    max_ = 0  # Variable to track the maximum distance
    if to != 0:
        now = f(to)  # Recursively compute distance for the first edge
        if now < 0: return now  # Return if a cycle is detected
        if now > max_: max_ = now  # Update max if a longer distance is found
    to = e2[from_]  # Get the second edge
    if to != 0:
        now = f(to)  # Recursively compute distance for the second edge
        if now < 0: return now  # Return if a cycle is detected
        if now > max_: max_ = now  # Update max if a longer distance is found
    b[from_] = False  # Unmark the node as visited for future calls
    return d[from_] = max_ + 1  # Store and return the computed distance

# Main function
def main():
    global n
    n = nextint()  # Read the number of nodes
    # Read the adjacency list from input
    a = [[0] * (n - 1) for _ in range(n)]
    for i in range(n):
        for j in range(n - 1):
            a[i][j] = nextint() - 1  # Store edges, adjusting for 0-based indexing
    # Build the edge representation
    for i in range(n):
        for j in range(n - 2):
            from_ = p(i, a[i][j])  # Get unique index for the current edge
            to = p(i, a[i][j + 1])  # Get unique index for the next edge
            # Store the edges in e1 and e2
            if e1[from_] == 0:
                e1[from_] = to  # Assign the first edge
            elif e2[from_] == 0:
                e2[from_] = to  # Assign the second edge
            else:
                print(-1)  # Output -1 if more than two edges are found
                return
    ans = 0  # Variable to store the final answer
    # Compute the maximum distance for each node
    for i in range(n):
        from_ = p(i, a[i][0])  # Get unique index for the starting edge
        now = f(from_)  # Compute the distance
        if now < 0:
            ans = -1  # Set answer to -1 if a cycle is detected
            break  # Exit the loop
        if now > ans: ans = now  # Update the answer if a longer distance is found
    print(ans)  # Output the final answer

if __name__ == "__main__":
    main()
