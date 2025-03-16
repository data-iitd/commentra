# Define a constant for infinity (a large value)
INF = 1000000001

# Define a constant for the maximum number of vertices
N = 100000

# Define a structure to represent an edge in the graph
class Edge:
  def __init__(self, source, target, weight):
    self.source = source
    self.target = target
    self.weight = weight

# Function to find the minimum of two values
def min(a, b):
  if a < b:
    return a
  else:
    return b

# Function to relax an edge
def relax(u, v, w):
  global distances
  global prev_distances
  if distances[v] > distances[u] + w:
    distances[v] = distances[u] + w
    prev_distances[v] = distances[v]

# Function to read input from stdin
def read_input():
  global edges
  global distances
  global prev_distances
  global N
  global V
  global E
  global r
  V, E, r = map(int, input().split())
  edges = []
  for i in range(E):
    source, target, weight = map(int, input().split())
    edges.append(Edge(source, target, weight))
  distances = [INF] * N
  prev_distances = [0] * N
  distances[r] = 0

# Function to print output to stdout
def print_output():
  for i in range(V):
    if distances[i] == INF:
      print("INF")
    else:
      print(distances[i])

# Main function
def main():
  read_input()
  for i in range(1, V):
    for edge in edges:
      relax(edge.source, edge.target, edge.weight)
    same = True
    for j in range(V):
      if distances[j]!= prev_distances[j]:
        same = False
        break
    if same:
      break
  print_output()

# Call the main function
if __name__ == "__main__":
  main()

