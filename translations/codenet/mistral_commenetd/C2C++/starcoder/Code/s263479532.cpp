
#include<bits/stdc++.h>
#define MAX 100
#define INF 999999
#define NIL -1
#define WHITE 0
#define BLACK 2

using namespace std;

int prim(); // Function to implement Prim's Algorithm

int n, G[MAX][MAX]; // n is the number of vertices and G is the adjacency matrix

int main()
{
  int i, j; // Loop variables

  scanf("%d", &n); // Read the number of vertices from the user
  for(i=0; i<n; i++) // Initialize the 2D array G with input values
  {
    for(j=0; j<n; j++)
    {
      scanf("%d", &G[i][j]);
    }
  }

  printf("%d\n", prim()); // Call the prim function and print the result

  return 0;
}

int prim() // Function to implement Prim's Algorithm
{
  int u, i, v, mincost, d[n], pi[n], color[n], sum=0; // Declare and initialize variables

  for(u=0; u<n; u++) // Initialize the arrays d, pi, and color with initial values
  {
    d[u] = INF;
    pi[u] = NIL;
    color[u] = WHITE;
  }

  d[0] = 0; // Set the initial distance of the first vertex to 0

  while(1) // The main loop of Prim's Algorithm
  {
    mincost = INF; // Initialize mincost to the maximum possible value

    for(i=0; i<n; i++) // Find the unvisited vertex with the minimum distance
    {
      if(color[i]!= BLACK && d[i] < mincost)
      {
        mincost = d[i];
        u = i;
      }
    }

    if(mincost == INF) break; // If all vertices have been visited, break the loop

    color[u] = BLACK; // Mark the current vertex as visited

    for(v=0; v<n; v++) // Update the distances of adjacent vertices
    {
      if(color[v]!= BLACK && G[u][v] < d[v] && G[u][v]!= -1)
      {
        pi[v] = u;
        d[v] = G[u][v];
      }
    }
  }

  for(i=0; i<n; i++) // Calculate and print the total weight of the MST
  {
    if(d[i]!= INF) sum += d[i];
  }

  return sum;
}

