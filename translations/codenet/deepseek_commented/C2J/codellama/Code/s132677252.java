#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef int32_t i32;
typedef int64_t i64;

// Define a structure for a directed edge in the graph
class DirectedEdge {
  public int32_t vertex; // The destination vertex of the edge
  public int32_t next;   // The index of the next edge in the adjacency list
  public DirectedEdge(int32_t vertex, int32_t next) {
    this.vertex = vertex;
    this.next = next;
  }
}

// Define a structure for the directed graph
class DirectedGraph {
  public DirectedEdge[] edge;       // Array of edges
  public int32_t[] start;         // Array of start pointers for each vertex
  public int32_t pointer;        // Current number of edges
  public int32_t vertex_num;     // Number of vertices
  public int32_t edge_max_size;  // Maximum size of the edge array
  public DirectedGraph(int vertex_num) {
    edge = new DirectedEdge[1];
    start = new int32_t[vertex_num];
    pointer = 0;
    this.vertex_num = vertex_num;
    edge_max_size = 1;
    for (int32_t i = 0; i < vertex_num; ++i) {
      start[i] = -1; // Initialize all start pointers to -1 (no edges initially)
    }
  }
  public void addEdge(int32_t from, int32_t to) {
    if (pointer == edge_max_size) {
      edge_max_size *= 2;
      edge = Arrays.copyOf(edge, edge_max_size);
    }
    edge[pointer] = new DirectedEdge(to, start[from]); // Set the new edge and update the start pointer
    start[from] = pointer++; // Update the start pointer to the new edge
  }
}

// Define the modulo constant
final int mod = 1000000007;

// Function to compute r^n % mod using exponentiation by squaring
int mod_pow(int r, int n) {
  int t = 1;
  int s = r;
  while (n > 0) {
    if (n % 2 == 1) t = (int) ((long) t * s % mod); // If n is odd, multiply t by s
    s = (int) ((long) s * s % mod); // Square s
    n /= 2; // Halve n
  }
  return t;
}

// Define a structure for a node in the dynamic programming array
class Node {
  public int one;  // Number of ways to have exactly one edge
  public int zero; // Number of ways to have exactly zero edges
  public Node(int one, int zero) {
    this.one = one;
    this.zero = zero;
  }
}

// Function to merge two nodes in the dynamic programming array
Node merge(Node[] a, int n) {
  long one = 0;
  long zero = 1;
  long total = 1;
  for (int i = 0; i < n; ++i) {
    one = (one * a[i].zero + zero * a[i].one) % mod; // Calculate the number of ways to have exactly one edge
    zero = zero * a[i].zero % mod; // Calculate the number of ways to have exactly zero edges
    total = total * (a[i].zero + a[i].one) % mod; // Calculate the total number of ways
  }
  return new Node((int) one, (int) (total + mod - one) % mod); // Return the merged node
}

// Define the type for values stored in the deque
class DequeVal {
  public int one;  // Number of ways to have exactly one edge
  public int zero; // Number of ways to have exactly zero edges
  public DequeVal(int one, int zero) {
    this.one = one;
    this.zero = zero;
  }
}

// Define a structure for the deque
class Deque {
  public DequeVal[] array;
  public int front;
  public int last;
  public int mask;
  public Deque() {
    final int len = 2;
    array = new DequeVal[len];
    front = last = 0;
    mask = len - 1;
  }
  public int getSize() {
    return (last + (~front + 1)) & mask;
  }
  public void realloc() {
    DequeVal[] array = new DequeVal[2 * (mask + 1)];
    int k = 0;
    for (int i = front; i != last; i = (i + 1) & mask) {
      array[k++] = this.array[i];
    }
    this.array = array;
    front = 0;
    last = k;
    mask = 2 * mask + 1;
  }
  public DequeVal getAt(int x) {
    return array[(front + x) & mask];
  }
  public void assignAt(int x, DequeVal v) {
    array[(front + x) & mask] = v;
  }
  public void pushFront(DequeVal v) {
    if(((last + 1) & mask) == front) {
      realloc();
    }
    front = (front + mask) & mask;
    array[front] = v;
  }
  public int cmpDequeSize(Deque[] a, Deque[] b) {
    Deque p = a[0];
    Deque q = b[0];
    int d = getSize(p) - getSize(q);
    return d == 0 ? 0 : d > 0 ? -1 : 1;
  }
}

// Function to run the main logic of the program
void run() {
  int n;
  scanf("%" SCNi32, &n); // Read the number of vertices
  int[] p = new int[n + 1]; // Array to store parent pointers
  int[] depth = new int[n + 1]; // Array to store depths of vertices
  int[] cnt = new int[n + 1]; // Array to count vertices at each depth
  cnt[0] = 1; // There is one way to have zero edges (the root itself)
  DirectedGraph g = new DirectedGraph(n + 1); // Initialize the graph
  for (int i = 1; i <= n; ++i) {
    scanf("%" SCNi32, p + i); // Read the parent of each vertex
    g.addEdge(p[i], i); // Add the edge to the graph
    depth[i] = depth[p[i]] + 1; // Calculate the depth of each vertex
    cnt[depth[i]]++; // Increment the count of vertices at the current depth
  }
  Deque[] dp = new Deque[n + 1]; // Array to store dynamic programming results
  Deque[] child = new Deque[n + 1]; // Array to store child deques
  Node[] lst = new Node[n + 1]; // Array to store merged nodes
  for (int i = n; i >= 0; --i) {
    int v = i;
    if (g.start[v] == -1) {
      dp[v] = new Deque();
      dp[v].pushFront(new DequeVal(1, 1)); // Initialize the dp array for leaf nodes
      continue;
    }
    int len = 0;
    for (int p = g.start[v]; p != -1; p = g.edge[p].next) {
      int u = g.edge[p].vertex;
      child[len++] = dp[u]; // Collect child deques
    }
    if (len > 1) {
      Arrays.sort(child, (Deque[] a, Deque[] b) -> cmpDequeSize(a, b)); // Sort child deques by size
      for (int d = 0; d < getSize(child[1]); ++d) {
        int j = 0;
        for (; j < len && d < getSize(child[j]); ++j) {
          lst[j] = child[j].getAt(d); // Get nodes at the current depth
        }
        child[0].assignAt(d, merge(lst, j)); // Merge nodes and assign to the first child deque
      }
      for (int j = 1; j < len; ++j) {
        child[j] = null; // Free memory of unused child deques
      }
    }
    dp[v] = child[0]; // Assign the merged deque to the current vertex
    dp[v].pushFront(new DequeVal(1, 1)); // Add the current node to the dp array
  }
  long ans = 0;
  for (int i = 0; i < getSize(dp[0]); ++i) {
    ans += (long) mod_pow(2, n + 1 - cnt[i]) * dp[0].getAt(i).one % mod; // Calculate the answer
  }
  printf("%" PRIi64 "\n", ans % mod); // Print the result
}

// Main function to run the program
int main() {
  run();
  return 0;
}

