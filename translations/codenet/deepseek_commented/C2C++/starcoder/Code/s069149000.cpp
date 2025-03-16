#include<bits/stdc++.h>
#define INF 100000
#define MAX 101
#define NIL -6
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

int G[MAX][MAX]; // 2D array to represent the graph
int n; // Number of vertices in the graph

// Prim's algorithm to find the Minimum Spanning Tree (MST)
void prim(){
  int i,j;
  int d[MAX]; // Array to store the minimum distance from the tree to each vertex
  int pi[MAX]; // Array to store the parent of each vertex in the MST
  int color[MAX]; // Array to keep track of the color of each vertex (WHITE, GRAY, BLACK)
  int min,u,v,sum=0; // Variables to find the minimum distance vertex and to store the sum of MST weights

  // Initialize all distances to infinity, parents to NIL, and colors to WHITE
  for(i=0;i<n;i++){
    d[i] = INF;
    pi[i] = NIL;
    color[i] = WHITE;
  }

  // Distance of the first vertex is set to 0
  d[0] = 0;

  // Continue until all vertices are processed
  while(1){
    min = INF;
    u = NIL;
    // Find the vertex with the minimum distance that is not BLACK
    for(i=0;i<n;i++){
      if(color[i]!= BLACK && d[i] < min){
        min = d[i];
        u = i;
      }
    }
    // If no such vertex is found, break the loop
    if(u == NIL){
      break;
    }
    // Mark the selected vertex as BLACK
    color[u] = BLACK;
    // Update the distances and parents of adjacent vertices
    for(v=0;v<n;v++){
      if(color[v]!= BLACK && G[u][v]!= INF){
        if(d[v] > G[u][v]){
          d[v] = G[u][v];
          pi[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }
  // Calculate the sum of the weights of the edges in the MST
  for(i=0;i<n;i++){
    if(pi[i]!= NIL) sum += G[i][pi[i]];
  }
  // Print the sum of the weights of the MST
  cout<<sum<<endl;
}

// Main function to read the graph and call Prim's algorithm
int main(){
  int e;
  int i,j;

  cin>>n; // Read the number of vertices

  // Read the adjacency matrix of the graph
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin>>e;
      if(e == -1){
        G[i][j] = INF; // If no edge, set weight to INF
      }else{
        G[i][j] = e; // Otherwise, set the weight of the edge
      }
    }
  }

  prim(); // Call Prim's algorithm to find and print the sum of the MST
  return 0;
}

