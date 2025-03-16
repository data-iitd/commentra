
// Define types for 32-bit and 64-bit integers
class i32 {
  public static final int MOD = 1000000007;
  public static int mod_pow (int r, int n) {
    int t = 1; // Result variable
    int s = r; // Base
    // Loop until the exponent is zero
    while (n > 0) {
      if (n & 1) t = (long) t * s % MOD; // If n is odd, multiply the result by the base
      s = (long) s * s % MOD; // Square the base
      n >>= 1; // Divide n by 2
    }
    return t; // Return the result
  }
}

// Structure to represent a directed edge in the graph
class graph_edge {
  int vertex; // The destination vertex of the edge
  int next;   // The index of the next edge in the adjacency list
}

// Structure to represent a directed graph
class graph {
  graph_edge[] edge;          // Array of edges
  int[] start;            // Array to store the starting index of edges for each vertex
  int pointer;           // Current number of edges in the graph
  int vertex_num;        // Number of vertices in the graph
  int edge_max_size;     // Maximum size of the edges array
}

// Function to create a new directed graph with a specified number of vertices
graph new_graph (int vertex_num) {
  // Allocate memory for the graph structure
  graph g = new graph();
  // Allocate memory for edges and initialize the start array
  g.edge = new graph_edge[1];
  g.start = new int[vertex_num];
  g.pointer = 0; // Initialize edge count to 0
  g.vertex_num = vertex_num; // Set the number of vertices
  g.edge_max_size = 1; // Initialize maximum edge size
  // Initialize the start array to -1 (indicating no edges)
  for (int i = 0; i < vertex_num; ++i) {
    g.start[i] = -1;
  }
  return g; // Return the created graph
}

// Function to add a directed edge from 'from' to 'to' in the graph
void add_edge (graph g, int from, int to) {
  // Check if the edges array needs to be resized
  if (g.pointer == g.edge_max_size) {
    g.edge_max_size *= 2; // Double the maximum size
    g.edge = Arrays.copyOf (g.edge, g.edge_max_size);
  }
  // Add the edge to the graph
  g.edge[g.pointer] = new graph_edge();
  g.edge[g.pointer].vertex = to;
  g.edge[g.pointer].next = g.start[from];
  g.start[from] = g.pointer++; // Update the start index for 'from'
}

// Structure to represent a node in dynamic programming
class node {
  int one;  // Count of paths ending with 1
  int zero; // Count of paths ending with 0
}

// Function to merge multiple dp nodes
node merge (node[] a, int n) {
  int one = 0; // Initialize count of paths ending with 1
  int zero = 1; // Initialize count of paths ending with 0
  int total = 1; // Initialize total paths
  // Iterate through the nodes to merge their counts
  for (int i = 0; i < n; ++i) {
    one = (one * a[i].zero + zero * a[i].one) % i32.MOD; // Update count of paths ending with 1
    zero = zero * a[i].zero % i32.MOD; // Update count of paths ending with 0
    total = total * (a[i].zero + a[i].one) % i32.MOD; // Update total paths
  }
  return new node(one, (total + i32.MOD - one) % i32.MOD); // Return merged node
}

// Define a type for deque values
class deque_val {
  int one;  // Count of paths ending with 1
  int zero; // Count of paths ending with 0
}

// Structure to represent a deque (double-ended queue)
class deque {
  deque_val[] array; // Array to store deque values
  int front;     // Index of the front element
  int last;      // Index of the last element
  int mask;      // Mask for circular indexing
}

// Function to create a new deque
deque new_deque () {
  deque d = new deque(); // Allocate memory for the deque
  d.array = new deque_val[2]; // Allocate memory for the array
  d.front = d.last = 0; // Initialize front and last indices
  d.mask = 1; // Set the mask for circular indexing
  return d; // Return the created deque
}

// Function to free the memory allocated for a deque
void free_deque (deque d) {
  d.array = null; // Free the array
  d = null; // Free the deque structure
}

// Function to get the size of the deque
int get_size (deque d) {
  return (d.last + (~d.front + 1)) & d.mask; // Calculate the size using circular indexing
}

// Function to reallocate memory for the deque when it is full
void deque_realloc (deque d) {
  // Allocate a new array with double the size
  deque_val[] array = new deque_val[2 * d.mask + 1];
  int k = 0; // Index for the new array
  // Copy elements from the old array to the new array
  for (int i = d.front; i!= d.last; i = (i + 1) & d.mask) {
    array[k++] = d.array[i];
  }
  d.array = array; // Update the deque's array to the new array
  d.front = 0; // Reset front index
  d.last = k; // Update last index
  d.mask = 2 * d.mask + 1; // Update the mask for the new size
}

// Function to get the value at a specific index in the deque
deque_val get_at (deque d, int x) {
  return d.array[(d.front + x) & d.mask]; // Return the value using circular indexing
}

// Function to assign a value at a specific index in the deque
void assign_at (deque d, int x, deque_val v) {
  d.array[(d.front + x) & d.mask] = v; // Assign the value using circular indexing
}

// Function to push a value to the front of the deque
void push_front (deque d, deque_val v) {
  // Check if the deque is full
  if(((d.last + 1) & d.mask) == d.front) {
    deque_realloc (d); // Reallocate if full
  }
  d.front = (d.front + d.mask) & d.mask; // Move front index backwards
  d.array[d.front] = v; // Assign the value at the front
}

// Comparison function for sorting deques based on their size
int cmp_deque_size (Object a, Object b) {
  deque p = (deque) a; // Get the first deque
  deque q = (deque) b; // Get the second deque
  int d = get_size (p) - get_size (q); // Calculate the size difference
  return d == 0? 0 : d > 0? -1 : 1; // Return comparison result
}

// Main function to run the algorithm
void run () {
  int n; // Number of vertices
  Scanner sc = new Scanner(System.in);
  n = sc.nextInt(); // Read the number of vertices
  // Allocate memory for parent, depth, and count arrays
  int[] p = new int[n + 1];
  int[] depth = new int[n + 1];
  int[] cnt = new int[n + 1];
  cnt[0] = 1; // Initialize count for depth 0
  graph g = new_graph(n + 1); // Create a new graph
  // Read edges and build the graph
  for (int i = 1; i <= n; ++i) {
    p[i] = sc.nextInt(); // Read parent for vertex i
    add_edge(g, p[i], i); // Add edge from parent to current vertex
    depth[i] = depth[p[i]] + 1; // Update depth of current vertex
    cnt[depth[i]]++; // Increment count for the current depth
  }
  // Allocate memory for dynamic programming arrays
  deque[] dp = new deque[n + 1];
  deque[] child = new deque[n + 1];
  node[] lst = new node[n + 1];
  // Process vertices in reverse order
  for (int i = n; i >= 0; --i) {
    int v = i; // Current vertex
    // If the vertex has no outgoing edges
    if (g.start[v] == -1) {
      dp[v] = new_deque(); // Create a new deque for this vertex
      push_front(dp[v], new node(1, 1)); // Initialize with base case
      continue; // Move to the next vertex
    }
    int len = 0; // Length of child deques
    // Collect child deques for the current vertex
    for (int p = g.start[v]; p!= -1; p = g.edge[p].next) {
      int u = g.edge[p].vertex; // Get child vertex
      child[len++] = dp[u]; // Store child deque
    }
    // If there are multiple child deques, merge them
    if (len > 1) {
      Arrays.sort(child, 0, len, new Comparator<deque>() {
        @Override
        public int compare (deque p, deque q) {
          return cmp_deque_size(p, q);
        }
      }); // Sort child deques by size
      // Merge the child deques
      for (int d = 0; d < get_size(child[1]); ++d) {
        int j = 0;
        for (; j < len && d < get_size(child[j]); ++j) {
          lst[j] = get_at(child[j], d); // Get nodes from child deques
        }
        assign_at(child[0], d, merge(lst, j)); // Merge and assign to the first child
      }
      // Free the other child deques
      for (int j = 1; j < len; ++j) {
        free_deque(child[j]);
      }
    }
    dp[v] = child[0]; // Assign the merged deque to the current vertex
    push_front(dp[v], new node(1, 1)); // Add the base case to the front
  }
  long ans = 0; // Variable to store the final answer
  // Calculate the final answer based on the dp values
  for (int i = 0; i < get_size(dp[0]); ++i) {
    ans += (long) i32.mod_pow(2, n + 1 - cnt[i]) * get_at(dp[0], i).one % i32.MOD; // Update answer
  }
  System.out.println(ans % i32.MOD); // Print the final answer
}

// Main function to execute the program
public static void main (String[] args) {
  run(); // Call the run function
}

