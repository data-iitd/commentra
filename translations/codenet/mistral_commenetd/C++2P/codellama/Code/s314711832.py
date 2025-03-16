
#include <iostream>
#include <vector>
#define MIN(a, b) ((a < b) ? a : b)
#define INF 1000000001
#define N 100000

using namespace std;

struct edge {
  int source;
  int target;
  int weight;
};

vector<edge> edges;

int distances[N];
int prev_distances[N] = {0};

# Main function
def main():
  V, E, r = 0, 0, 0 # V: number of vertices, E: number of edges, r: source vertex

  # Read input
  V, E, r = map(int, input().split())

  # Initialize edges vector
  for i in range(E):
    source, target, distance = map(int, input().split())
    new_edge = edge(source, target, distance)
    edges.append(new_edge)
    
  # Initialize distances array with maximum value
  for i in range(N):
    distances[i] = INF # max value

  # Set initial distance of source vertex to 0
  distances[r] = 0

  # Bellman-Ford algorithm
  for i in range(1, V):
    # Initialize previous distances array with current distances
    for j in range(V):
      prev_distances[j] = distances[j]  

    # Update distances for all vertices
    for edgeptr in edges:
      distances[edgeptr.target] = min(distances[edgeptr.source] + edgeptr.weight, distances[edgeptr.target])
    
    # Check if all distances have been updated
    same = True
    for j in range(V):
      if distances[j] != prev_distances[j]:
	same = False
	break

    # If all distances have been updated, break the loop
    if same: break

  # Print results
  for i in range(V):
    if distances[i] == INF:
      print("INF")
    else:
      print(distances[i])



