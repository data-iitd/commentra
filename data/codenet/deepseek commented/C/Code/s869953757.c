
#define M 100
#define whi 0
#define gra 1
#define bla 2

int n; // Number of nodes in the graph
int T[M][M]; // Adjacency matrix to represent the graph
int color[M], d[M]; // Arrays to keep track of colors and distances
int Q[M], head = 0, tail = 0; // Queue for BFS and pointers for queue operations

// Function to enqueue an element into the queue
void enqueue(int x) {
  Q[tail] = x;
  tail = (tail + 1) % M;
}

// Function to dequeue an element from the queue
int dequeue(void) {
  int x = Q[head];
  head = (head + 1) % M;
  return x;
}

// Function to perform Breadth-First Search (BFS) starting from node s
void bfs(int s) {
  int i, u, v;

  // Initialize all nodes to white, set distance to infinity
  for (i = 0; i < n; i++) {
    color[i] = whi;
    d[i] = 1000000;
  }

  // Set the color and distance of the source node
  color[s] = gra;
  d[s] = 0;
  enqueue(s);

  // Continue BFS until the queue is empty
  while (head != tail) {
    u = dequeue(); // Dequeue the front node
    // Explore all adjacent nodes
    for (v = 0; v < n; v++) {
      if (T[u][v] == 1 && color[v] == whi) {
        color[v] = gra; // Mark as gray
        d[v] = d[u] + 1; // Update distance
        enqueue(v); // Enqueue the node
      }
    }
    color[u] = bla; // Mark as black
  }
}

// Main function to read the graph, execute BFS, and print distances
int main() {
  int i, j;
  int u, k, v;

  scanf("%d", &n); // Read the number of nodes

  // Initialize the adjacency matrix with zeros
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      T[i][j] = 0;
    }
  }

  // Read the edges and construct the adjacency matrix
  for (i = 0; i < n; i++) {
    scanf("%d %d", &u, &k);
    u--; // Convert to 0-based index
    for (j = 0; j < k; j++) {
      scanf("%d", &v);
      v--; // Convert to 0-based index
      T[u][v] = 1; // Set the edge in the adjacency matrix
    }
  }

  bfs(0); // Execute BFS starting from node 0

  // Print the distances from the source node to all other nodes
  for (i = 0; i < n; i++) {
    if (d[i] == 1000000) d[i] = -1; // If unreachable, set distance to -1
    printf("%d %d\n", i + 1, d[i]); // Print node number and distance
  }

  return 0;
}