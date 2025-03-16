#include<stdio.h>

#define M 100 // Maximum number of vertices in the graph
#define whi 0  // Color code for white (unvisited)
#define gra 1  // Color code for gray (visited but not fully explored)
#define bla 2  // Color code for black (fully explored)

int n; // Number of vertices in the graph
int T[M][M]; // Adjacency matrix to represent the graph
int color[M], d[M]; // Arrays to store the color and distance of each vertex
int Q[M], head=0, tail=0; // Queue for BFS implementation

// Function to add an element to the queue
void enqueue(int x){
  Q[tail] = x; // Add element x to the queue
  tail = (tail+1)%M; // Update tail index in a circular manner
}

// Function to remove and return an element from the queue
int dequeue(void){
  int x;
  x = Q[head]; // Get the front element of the queue
  head = (head+1)%M; // Update head index in a circular manner
  return x; // Return the dequeued element
}

// Function to perform Breadth-First Search (BFS) starting from vertex s
void bfs(int s){
  int i, u, v;

  // Initialize all vertices as unvisited and set their distances to a large value
  for(i=0; i<n; i++){
    color[i] = whi; // Set color to white (unvisited)
    d[i] = 1000000; // Set distance to a large number (infinity)
  }

  // Start BFS from the source vertex s
  color[s] = gra; // Mark the source vertex as gray (visited)
  d[s] = 0; // Distance to source vertex is 0
  enqueue(s); // Enqueue the source vertex

  // Continue BFS until the queue is empty
  while(head != tail){
    u = dequeue(); // Dequeue a vertex from the queue
    // Explore all adjacent vertices of u
    for(v=0; v<n; v++){
      // If there is an edge from u to v and v is unvisited
      if(T[u][v] == 1 && color[v] == whi){
        color[v] = gra; // Mark v as gray (visited)
        d[v] = d[u]+1; // Update distance to v
        enqueue(v); // Enqueue vertex v for further exploration
      }
    }
    color[u] = bla; // Mark u as black (fully explored)
  }
}

// Main function
int main(){
  int i, j;
  int u, k, v;

  // Read the number of vertices
  scanf("%d", &n);

  // Initialize the adjacency matrix to zero (no edges)
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      T[i][j] = 0; // No edge between vertices i and j
    }
  }

  // Read the edges of the graph
  for(i=0; i<n; i++){
    scanf("%d %d", &u, &k); // Read vertex u and number of edges k
    u--; // Convert to zero-based index
    for(j=0; j<k; j++){
      scanf("%d", &v); // Read each adjacent vertex v
      v--; // Convert to zero-based index
      T[u][v] = 1; // Set the edge from u to v in the adjacency matrix
    }
  }

  // Perform BFS starting from vertex 0
  bfs(0);

  // Output the distance from the source vertex to each vertex
  for(i=0; i<n; i++){
    if(d[i] == 1000000) d[i] = -1; // If distance is still infinity, set it to -1
    printf("%d %d\n", i+1, d[i]); // Print vertex number and its distance
  }

  return 0; // Return success
}
