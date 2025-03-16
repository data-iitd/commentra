#include<stdio.h>
#define MAX 100
#define INF 999999
#define NIL -1
#define WHITE 0
#define BLACK 2

// Include the standard input-output library for input and output operations.

// Define constants for maximum size of the graph, infinity, nil, white, and black respectively.

int prim();

// Declare the function prim which implements Prim's algorithm for finding the Minimum Spanning Tree.

int n, G[MAX][MAX];

// Declare variables for the number of vertices and the graph represented by an adjacency matrix.

int main()
{
  int i, j;

  // Declare loop variables for iterating through the graph.

  scanf("%d", &n);
  // Read the number of vertices from the input.

  for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
    {
      scanf("%d", &G[i][j]);
    }
    }
  // Read the adjacency matrix representing the graph from the input.

  printf("%d\n", prim());
  // Call the prim function and print the result.

  return 0;
}

// Main function to execute the program.

int prim()
{
  int u, i, v, mincost, d[n], pi[n], color[n], sum=0;

  // Declare variables for Prim's algorithm: u (current vertex), i, v (neighbor vertices), mincost (minimum cost), d (distance), pi (predecessor), color (color of vertices), and sum (total cost of the MST).

  for(u=0; u<n; u++)
    {
      d[u] = INF;
      pi[u] = NIL;
      color[u] = WHITE;
    }

  // Initialize all distances to infinity, predecessors to nil, and colors to white.

  d[0] = 0;
  // Set the distance of the first vertex to 0.

  while(1)
    {
      mincost = INF;

      // Initialize mincost to infinity.

      for(i=0; i<n; i++)
    {
      if(color[i] != BLACK && d[i] < mincost)
        {
          mincost = d[i];
          u = i;
        }
    }

      // Find the vertex with the smallest distance that is not yet black.

      if(mincost == INF) break;

      // If no more vertices can be reached, break the loop.

      color[u] = BLACK;

      // Mark the current vertex as black.

      for(v=0; v<n; v++)
    {
      if(color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1)
        {
          pi[v] = u;
          d[v] = G[u][v];
        }
    }

      // Update the distances and predecessors for the neighboring vertices that are not black and have a valid edge weight.
    }

  for(i=0; i<n; i++)
    {
      if(d[i] != INF) sum += d[i];
    }

  // Calculate the total cost of the Minimum Spanning Tree by summing up the distances of all vertices.

  return sum;
}
