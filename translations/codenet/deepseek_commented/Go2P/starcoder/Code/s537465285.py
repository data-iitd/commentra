import sys

# Reader for input
reader = sys.stdin

# Writer for output
writer = sys.stdout

# NextLine reads a line of input
def NextLine():
  line = reader.readline()
  if (line == ""):
    return None
  return line.rstrip()

# NextInt reads an integer from input
def NextInt():
  line = NextLine()
  if (line == None):
    return None
  return int(line)

# Write prints a line to the output
def Write(s):
  writer.write(str(s) + "\n")

# Output flushes the writer to ensure all buffered data is written
def Output():
  writer.flush()

# Bipartite checks if a graph is bipartite
def Bipartite(S):
  N = len(S)
  D = [0] * N # Distance array
  D[0] = 1 # Start from the first vertex
  Q = [0] * N # Queue for BFS
  ret = True # Return value
  pos = 1 # Position in the queue
  for i in range(0, N):
    if not ret: break
    q = Q[i]
    for j, s in enumerate(S[q]):
      if s == '0':
        continue
      if D[j] == 0:
        D[j] = D[q] + 1
        Q[pos] = j
        pos += 1
        continue
      if D[j] % 2 == D[q] % 2:
        ret = False
        break
  return ret

# WarshallFloyd computes the shortest paths between all pairs of vertices
def WarshallFloyd(S):
  N = len(S)
  G = [[0] * N for i in range(N)]
  for i in range(N):
    for j in range(N):
      if i == j: continue
      if S[i][j] == '0':
        G[i][j] = N # Set distance to a large number
      else:
        G[i][j] = 1 # Direct edge weight
  for k in range(0, N):
    for i in range(0, N):
      for j in range(0, N):
        if G[i][k] + G[k][j] < G[i][j]:
          G[i][j] = G[i][k] + G[k][j] # Update shortest path
  ans = 0
  for i in range(0, N):
    for j in range(0, N):
      if ans < G[i][j]: ans = G[i][j] # Find the maximum distance
  return ans + 1 # Return the result

# Main function to execute the program
def main():
  N = NextInt()
  S = []
  for i in range(0, N):
    S.append(NextLine())
  if not Bipartite(S):
    Write(-1) # If not bipartite, write -1
  else:
    Write(WarshallFloyd(S)) # Otherwise, compute and write the result
  Output() # Flush the writer

# Entry point of the program
if __name__ == "__main__":
  main()

