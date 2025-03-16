#include<stdio.h>

#define M 100
#define whi 0
#define gra 1
#define bla 2

int n;
int T[M][M];
int color[M],d[M];
int Q[M],head=0,tail=0; // Queue for BFS algorithm

// Function to add an element to the queue
void enqueue(int x){
  Q[tail] = x;
  tail = (tail+1)%M;
}

// Function to remove an element from the queue
int dequeue(void){
  int x;
  x = Q[head];
  head = (head+1)%M;
  return x;
}

// Breadth First Search Algorithm
void bfs(int s){
  int i,u,v; // i is a counter, u and v are vertices

  // Initialize all vertices with white color and infinite distance
  for(i=0; i<n; i++){
    color[i] = whi;
    d[i] = 1000000;
  }

  // Initialize source vertex with gray color and zero distance
  color[s] = gra;
  d[s] = 0;
  enqueue(s); // Enqueue source vertex

  // Traverse the queue until it is empty
  while(head != tail){
    u = dequeue(); // Dequeue a vertex
    for(v=0; v<n; v++){ // Iterate through all adjacent vertices
      if(T[u][v] == 1 && color[v] == whi){ // If the adjacent vertex is unvisited
	color[v] = gra; // Mark it as visited
	d[v] = d[u]+1; // Update its distance
	enqueue(v); // Enqueue the adjacent vertex
      }
    }
    color[u] = bla; // Mark the current vertex as black
  }
}

// Main function
int main(){
  int i,j; // i and j are counters
  int u,k,v; // u is a vertex, k is the number of neighbors, and v is a neighbor

  // Read the number of vertices
  scanf("%d",&n);

  // Initialize the adjacency matrix with zeros
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      T[i][j] = 0;
    }
  }

  // Read the edges and add them to the adjacency matrix
  for(i=0; i<n; i++){
    scanf("%d %d",&u,&k);
    u--; // Decrease the index of the source vertex by 1
    for(j=0; j<k; j++){
      scanf("%d",&v);
      v--; // Decrease the index of the neighbor vertex by 1
      T[u][v] = 1; // Add an edge between the vertices
    }
  }

  // Perform BFS algorithm starting from the source vertex 0
  bfs(0);

  // Print the results
  for(i=0; i<n; i++){
    if(d[i] == 1000000) d[i] = -1; // Set the distance to -1 if it is unreachable
    printf("%d %d\n",i+1,d[i]); // Print the vertex index and its distance from the source
  }

  return 0;
}

