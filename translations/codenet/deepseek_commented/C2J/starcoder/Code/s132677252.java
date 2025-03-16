
import java.util.*;
import java.io.*;

public class Main {
  // Define a structure for a directed edge in the graph
  static class graph_edge {
    int vertex; // The destination vertex of the edge
    int next;   // The index of the next edge in the adjacency list
  }

  // Define a structure for the directed graph
  static class graph {
    graph_edge[] edge;       // Array of edges
    int[] start;         // Array of start pointers for each vertex
    int pointer;        // Current number of edges
    int vertex_num;     // Number of vertices
    int edge_max_size;  // Maximum size of the edge array
  }

  // Function to initialize a new graph with a given number of vertices
  static graph new_graph (int vertex_num) {
    graph g = new graph();
    g.edge = new graph_edge[1];
    g.start = new int[vertex_num];
    g.pointer = 0;
    g.vertex_num = vertex_num;
    g.edge_max_size = 1;
    for (int i = 0; i < vertex_num; ++i) {
      g.start[i] = -1; // Initialize all start pointers to -1 (no edges initially)
    }
    return g;
  }

  // Function to add a directed edge to the graph
  static void add_edge (graph g, int from, int to) {
    if (g.pointer == g.edge_max_size) {
      g.edge_max_size *= 2;
      graph_edge[] edge = new graph_edge[g.edge_max_size];
      for (int i = 0; i < g.pointer; ++i) {
        edge[i] = g.edge[i];
      }
      g.edge = edge;
    }
    g.edge[g.pointer] = new graph_edge();
    g.edge[g.pointer].vertex = to;
    g.edge[g.pointer].next = g.start[from];
    g.start[from] = g.pointer++;
  }

  // Define the modulo constant
  static final int mod = 1000000007;

  // Function to compute r^n % mod using exponentiation by squaring
  static int mod_pow (int r, int n) {
    int t = 1;
    int s = r;
    while (n > 0) {
      if (n % 2 == 1) t = (t * s) % mod; // If n is odd, multiply t by s
      s = (s * s) % mod; // Square s
      n /= 2; // Halve n
    }
    return t;
  }

  // Define a structure for a node in the dynamic programming array
  static class node {
    int one;  // Number of ways to have exactly one edge
    int zero; // Number of ways to have exactly zero edges
  }

  // Function to merge two nodes in the dynamic programming array
  static node merge (node[] a, int n) {
    int one = 0;
    int zero = 1;
    int total = 1;
    for (int i = 0; i < n; ++i) {
      one = (one * a[i].zero + zero * a[i].one) % mod; // Calculate the number of ways to have exactly one edge
      zero = zero * a[i].zero % mod; // Calculate the number of ways to have exactly zero edges
      total = total * (a[i].zero + a[i].one) % mod; // Calculate the total number of ways
    }
    return new node(one, (total + mod - one) % mod); // Return the merged node
  }

  // Define the type for values stored in the deque
  static class deque_val {
    int one;  // Number of ways to have exactly one edge
    int zero; // Number of ways to have exactly zero edges
  }

  // Define a structure for the deque
  static class deque {
    deque_val[] array;
    int front;
    int last;
    int mask;
  }

  // Function to initialize a new deque
  static deque new_deque () {
    deque d = new deque();
    d.array = new deque_val[2];
    d.front = d.last = 0;
    d.mask = 1;
    return d;
  }

  // Function to free the memory allocated for a deque
  static void free_deque (deque d) {
    d.array = null;
    d = null;
  }

  // Function to get the number of elements in the deque
  static int get_size (deque d) {
    return (d.last + (~d.front + 1)) & d.mask;
  }

  // Function to reallocate the deque when necessary
  static void deque_realloc (deque d) {
    deque_val[] array = new deque_val[2 * (d.mask + 1)];
    int k = 0;
    for (int i = d.front; i!= d.last; i = (i + 1) & d.mask) {
      array[k++] = d.array[i];
    }
    d.array = array;
    d.front = 0;
    d.last = k;
    d.mask = 2 * d.mask + 1;
  }

  // Function to get the value at a specific index in the deque
  static deque_val get_at (deque d, int x) {
    return d.array[(d.front + x) & d.mask];
  }

  // Function to assign a value at a specific index in the deque
  static void assign_at (deque d, int x, deque_val v) {
    d.array[(d.front + x) & d.mask] = v;
  }

  // Function to add an element to the front of the deque
  static void push_front (deque d, deque_val v) {
    if(((d.last + 1) & d.mask) == d.front) {
      deque_realloc (d);
    }
    d.front = (d.front + d.mask) & d.mask;
    d.array[d.front] = v;
  }

  // Function to compare the sizes of two deques
  static int cmp_deque_size (Object a, Object b) {
    deque p = (deque) a;
    deque q = (deque) b;
    int d = get_size (p) - get_size (q);
    return d == 0? 0 : d > 0? -1 : 1;
  }

  // Function to run the main logic of the program
  static void run () {
    int n;
    Scanner in = new Scanner(System.in);
    n = in.nextInt(); // Read the number of vertices
    int[] p = new int[n + 1]; // Array to store parent pointers
    int[] depth = new int[n + 1]; // Array to store depths of vertices
    int[] cnt = new int[n + 1]; // Array to count vertices at each depth
    cnt[0] = 1; // There is one way to have zero edges (the root itself)
    graph g = new_graph(n + 1); // Initialize the graph
    for (int i = 1; i <= n; ++i) {
      p[i] = in.nextInt(); // Read the parent of each vertex
      add_edge(g, p[i], i); // Add the edge to the graph
      depth[i] = depth[p[i]] + 1; // Calculate the depth of each vertex
      cnt[depth[i]]++; // Increment the count of vertices at the current depth
    }
    deque[] dp = new deque[n + 1]; // Array to store dynamic programming results
    deque[] child = new deque[n + 1]; // Array to store child deques
    node[] lst = new node[n + 1]; // Array to store merged nodes
    for (int i = n; i >= 0; --i) {
      int v = i;
      if (g.start[v] == -1) {
        dp[v] = new_deque();
        push_front(dp[v], new node(1, 1)); // Initialize the dp array for leaf nodes
        continue;
      }
      int len = 0;
      for (int p = g.start[v]; p!= -1; p = g.edge[p].next) {
        int u = g.edge[p].vertex;
        child[len++] = dp[u]; // Collect child deques
      }
      if (len > 1) {
        Arrays.sort(child, 0, len, new Comparator<deque>() {
          public int compare (deque p, deque q) {
            return cmp_deque_size(p, q);
          }
        }); // Sort child deques by size
        for (int d = 0; d < get_size(child[1]); ++d) {
          int j = 0;
          for (; j < len && d < get_size(child[j]); ++j) {
            lst[j] = get_at(child[j], d); // Get nodes at the current depth
          }
          assign_at(child[0], d, merge(lst, j)); // Merge nodes and assign to the first child deque
        }
        for (int j = 1; j < len; ++j) {
          free_deque(child[j]); // Free memory of unused child deques
        }
      }
      dp[v] = child[0]; // Assign the merged deque to the current vertex
      push_front(dp[v], new node(1, 1)); // Add the current node to the dp array
    }
    long ans = 0;
    for (int i = 0; i < get_size(dp[0]); ++i) {
      ans += (long) mod_pow(2, n + 1 - cnt[i]) * get_at(dp[0], i).one % mod; // Calculate the answer
    }
    System.out.println(ans % mod); // Print the result
  }

  // Main function to run the program
  public static void main (String[] args) {
    run();
  }
}

