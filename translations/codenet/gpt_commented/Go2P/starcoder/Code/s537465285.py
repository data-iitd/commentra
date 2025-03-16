import sys

# Initialize buffered reader and writer for input and output
reader = sys.stdin
writer = sys.stdout

# Function to read the next line from standard input
def NextLine():
  return reader.readline().rstrip()

# Function to read the next integer from standard input
def NextInt():
  return int(NextLine())

# Function to write output to standard output
def Write(s):
  writer.write(str(s) + '\n')

# Function to flush the buffered writer to output
def Output():
  writer.flush()

# Function to check if the graph is bipartite
def Bipartite(S):
  N = len(S) # Get the number of nodes
  D = [0] * N # Distance array to store levels of nodes
  D[0] = 1 # Start with the first node at level 1
  Q = [0] * N # Queue for BFS
  ret = True # Variable to track if the graph is bipartite
  pos = 1 # Position in the queue

  # Perform BFS to check for bipartiteness
  for i in range(N):
    if not ret: break # Exit if already determined not bipartite
    q = Q[i] # Current node
    for j, s in enumerate(S[q]):
      if s == '0':
        continue # Skip if there is no edge
      if D[j] == 0:
        # Assign level to the adjacent node
        D[j] = D[q] + 1
        Q[pos] = j # Add to queue
        pos += 1
        continue
      # Check if the adjacent node has the same level
      if D[j] % 2 == D[q] % 2:
        ret = False # Not bipartite
        break
    #print(i, q, D, Q, ret)
  return ret # Return the result of bipartiteness check

# Function to perform the Floyd-Warshall algorithm to find the longest shortest path
def WarshallFloyd(S):
  N = len(S) # Get the number of nodes
  G = [[0] * N for i in range(N)] # Initialize the graph matrix

  # Initialize the graph with distances
  for i in range(N):
    for j in range(N):
      if i == j: continue # Skip self-loops
      if S[i][j] == '0':
        G[i][j] = N # No edge, set to a large value
      else:
        G[i][j] = 1 # Edge exists, set distance to 1

  # Floyd-Warshall algorithm to find shortest paths
  for k in range(N):
    for i in range(N):
      for j in range(N):
        if G[i][k] + G[k][j] < G[i][j]:
          G[i][j] = G[i][k] + G[k][j] # Update shortest path

  # Find the maximum distance in the graph
  ans = 0
  for i in range(N):
    for j in range(N):
      if ans < G[i][j]: ans = G[i][j] # Update maximum distance
  return ans + 1 # Return the maximum distance found

# Main function to execute the program
def main():
  N = NextInt() # Read the number of nodes
  S = [] # Initialize the adjacency matrix
  for i in range(N):
    S.append(NextLine()) # Read each line of the adjacency matrix
  
  # Check if the graph is bipartite and process accordingly
  if not Bipartite(S):
    Write(-1) # Output -1 if not bipartite
  else:
    Write(WarshallFloyd(S)) # Output the longest shortest path if bipartite
  Output() # Flush the output

if __name__ == '__main__':
  main()

