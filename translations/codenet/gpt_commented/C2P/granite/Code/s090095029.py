
import sys

# Read the number of nodes and edges from standard input
n, m = map(int, sys.stdin.readline().split())

# Initialize an array to track connections (r0) and set all values to false
r0 = [False] * n

# Initialize an array to store nodes connected to node n (r1) and a counter for it
r1 = []
nr1 = 0

# Process each edge input
for i in range(m):
  a, b = map(int, sys.stdin.readline().split())
  
  # Ensure a is the smaller node and b is the larger node
  if a > b:
    a, b = b, a
  
  # Mark the connection from node a to node b in r0
  if a == 1: r0[b - 1] = True # If a is 1, mark b-1 as connected
  
  # If b is the last node (n), store a-1 in r1
  if b == n: r1.append(a - 1) # Store a-1 in r1 and increment the count

# Initialize a result variable to determine if a connection is possible
res = False

# Check if any of the nodes connected to node n are also connected to node 1
for i in r1:
  if r0[i]: res = True # If r0 at r1[i] is true, set res to true

# Output the result based on the value of res
print("POSSIBLE" if res else "IMPOSSIBLE")

# End of the program

