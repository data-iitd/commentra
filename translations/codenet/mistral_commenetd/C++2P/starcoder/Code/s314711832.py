
#define MIN(a, b) ((a < b)? a : b)
#define INF 1000000001
#define N 100000

# Read input
V, E, r = map(int, raw_input().split())

# Initialize edges vector
edges = []
for i in range(E):
  source, target, distance = map(int, raw_input().split())
  new_edge = {'source': source, 'target': target, 'weight': distance}
  edges.append(new_edge)

# Initialize distances array with maximum value
distances = [INF] * N

# Set initial distance of source vertex to 0
distances[r] = 0

# Bellman-Ford algorithm
for i in range(1, V):
  # Initialize previous distances array with current distances
  prev_distances = distances[:]

  # Update distances for all vertices
  for edge in edges:
    distances[edge['target']] = MIN(distances[edge['source']] + edge['weight'], distances[edge['target']])

  # Check if all distances have been updated
  same = True
  for j in range(V):
    if distances[j]!= prev_distances[j]:
      same = False
      break

  # If all distances have been updated, break the loop
  if same: break

# Print results
for i in range(V):
  if distances[i] == INF:
    print "INF"
  else:
    print distances[i]

# 