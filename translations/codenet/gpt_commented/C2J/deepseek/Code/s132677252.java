import java.util.*;

public class Main {
    // Define types for 32-bit and 64-bit integers
    static class Edge {
        int vertex; // The destination vertex of the edge
        int next;   // The index of the next edge in the adjacency list
    }

    static class Graph {
        Edge[] edge;          // Array of edges
        int[] start;          // Array to store the starting index of edges for each vertex
        int pointer;          // Current number of edges in the graph
        int vertexNum;        // Number of vertices in the graph
        int edgeMaxSize;      // Maximum size of the edges array
    }

    static final int mod = 1000000007;

    // Function to create a new directed graph with a specified number of vertices
    static Graph newGraph(int vertexNum) {
        Graph g = new Graph();
        g.edge = new Edge[1];
        g.start = new int[vertexNum];
        g.pointer = 0; // Initialize edge count to 0
        g.vertexNum = vertexNum; // Set the number of vertices
        g.edgeMaxSize = 1; // Initialize maximum edge size
        // Initialize the start array to -1 (indicating no edges)
        for (int i = 0; i < vertexNum; ++i) {
            g.start[i] = -1;
        }
        return g; // Return the created graph
    }

    // Function to add a directed edge from 'from' to 'to' in the graph
    static void addEdge(Graph g, int from, int to) {
        // Check if the edges array needs to be resized
        if (g.pointer == g.edgeMaxSize) {
            g.edgeMaxSize *= 2; // Double the maximum size
            g.edge = Arrays.copyOf(g.edge, g.edgeMaxSize);
        }
        // Add the edge to the graph
        g.edge[g.pointer] = new Edge();
        g.edge[g.pointer].vertex = to;
        g.edge[g.pointer].next = g.start[from];
        g.start[from] = g.pointer++; // Update the start index for 'from'
    }

    // Function to compute modular exponentiation
    static int modPow(int r, int n) {
        int t = 1; // Result variable
        int s = r; // Base
        // Loop until the exponent is zero
        while (n > 0) {
            if ((n & 1) != 0) t = (int) ((long) t * s % mod); // If n is odd, multiply the result by the base
            s = (int) ((long) s * s % mod); // Square the base
            n >>= 1; // Divide n by 2
        }
        return t; // Return the result
    }

    // Structure to represent a node in dynamic programming
    static class Node {
        int one;  // Count of paths ending with 1
        int zero; // Count of paths ending with 0
    }

    // Function to merge multiple dp nodes
    static Node merge(Node[] a, int n) {
        long one = 0; // Initialize count of paths ending with 1
        long zero = 1; // Initialize count of paths ending with 0
        long total = 1; // Initialize total paths
        // Iterate through the nodes to merge their counts
        for (int i = 0; i < n; ++i) {
            one = (one * a[i].zero + zero * a[i].one) % mod; // Update count of paths ending with 1
            zero = zero * a[i].zero % mod; // Update count of paths ending with 0
            total = total * (a[i].zero + a[i].one) % mod; // Update total paths
        }
        Node result = new Node();
        result.one = (int) one;
        result.zero = (int) ((total + mod - one) % mod);
        return result; // Return merged node
    }

    // Define a type for deque values
    static class DequeVal {
        Node node;
    }

    // Structure to represent a deque (double-ended queue)
    static class Deque {
        DequeVal[] array; // Array to store deque values
        int front;        // Index of the front element
        int last;         // Index of the last element
        int mask;         // Mask for circular indexing
    }

    // Function to create a new deque
    static Deque newDeque() {
        Deque d = new Deque();
        d.array = new DequeVal[2];
        d.front = d.last = 0; // Initialize front and last indices
        d.mask = 1; // Set the mask for circular indexing
        return d; // Return the created deque
    }

    // Function to free the memory allocated for a deque
    static void freeDeque(Deque d) {
        d.array = null; // Free the array
    }

    // Function to get the size of the deque
    static int getSize(Deque d) {
        return (d.last + (~d.front + 1)) & d.mask; // Calculate the size using circular indexing
    }

    // Function to reallocate memory for the deque when it is full
    static void dequeRealloc(Deque d) {
        // Allocate a new array with double the size
        DequeVal[] array = new DequeVal[2 * (d.mask + 1)];
        int k = 0; // Index for the new array
        // Copy elements from the old array to the new array
        for (int i = d.front; i != d.last; i = (i + 1) & d.mask) {
            array[k++] = d.array[i];
        }
        d.array = array; // Update the deque's array to the new array
        d.front = 0; // Reset front index
        d.last = k; // Update last index
        d.mask = 2 * d.mask + 1; // Update the mask for the new size
    }

    // Function to get the value at a specific index in the deque
    static DequeVal getAt(Deque d, int x) {
        return d.array[(d.front + x) & d.mask]; // Return the value using circular indexing
    }

    // Function to assign a value at a specific index in the deque
    static void assignAt(Deque d, int x, DequeVal v) {
        d.array[(d.front + x) & d.mask] = v; // Assign the value using circular indexing
    }

    // Function to push a value to the front of the deque
    static void pushFront(Deque d, DequeVal v) {
        // Check if the deque is full
        if (((d.last + 1) & d.mask) == d.front) {
            dequeRealloc(d); // Reallocate if full
        }
        d.front = (d.front + d.mask) & d.mask; // Move front index backwards
        d.array[d.front] = v; // Assign the value at the front
    }

    // Comparison function for sorting deques based on their size
    static int cmpDequeSize(Deque[] a, Deque[] b) {
        int d = getSize(a[0]) - getSize(b[0]); // Calculate the size difference
        return d == 0 ? 0 : d > 0 ? -1 : 1; // Return comparison result
    }

    // Main function to run the algorithm
    static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of vertices
        // Allocate memory for parent, depth, and count arrays
        int[] p = new int[n + 1];
        int[] depth = new int[n + 1];
        int[] cnt = new int[n + 1];
        cnt[0] = 1; // Initialize count for depth 0
        Graph g = newGraph(n + 1); // Create a new graph
        // Read edges and build the graph
        for (int i = 1; i <= n; ++i) {
            p[i] = scanner.nextInt(); // Read parent for vertex i
            addEdge(g, p[i], i); // Add edge from parent to current vertex
            depth[i] = depth[p[i]] + 1; // Update depth of current vertex
            cnt[depth[i]]++; // Increment count for the current depth
        }
        // Allocate memory for dynamic programming arrays
        Deque[] dp = new Deque[n + 1];
        Deque[] child = new Deque[n + 1];
        Node[] lst = new Node[n + 1];
        // Process vertices in reverse order
        for (int i = n; i >= 0; --i) {
            int v = i; // Current vertex
            // If the vertex has no outgoing edges
            if (g.start[v] == -1) {
                dp[v] = newDeque(); // Create a new deque for this vertex
                pushFront(dp[v], new DequeVal()); // Initialize with base case
                continue; // Move to the next vertex
            }
            int len = 0; // Length of child deques
            // Collect child deques for the current vertex
            for (int p = g.start[v]; p != -1; p = g.edge[p].next) {
                int u = g.edge[p].vertex; // Get child vertex
                child[len++] = dp[u]; // Store child deque
            }
            // If there are multiple child deques, merge them
            if (len > 1) {
                Arrays.sort(child, 0, len, (a, b) -> getSize(a) - getSize(b)); // Sort child deques by size
                // Merge the child deques
                for (int d = 0; d < getSize(child[1]); ++d) {
                    int j = 0;
                    for (; j < len && d < getSize(child[j]); ++j) {
                        lst[j] = getAt(child[j], d); // Get nodes from child deques
                    }
                    assignAt(child[0], d, merge(lst, j)); // Merge and assign to the first child
                }
                // Free the other child deques
                for (int j = 1; j < len; ++j) {
                    freeDeque(child[j]);
                }
            }
            dp[v] = child[0]; // Assign the merged deque to the current vertex
            pushFront(dp[v], new DequeVal()); // Add the base case to the front
        }
        long ans = 0; // Variable to store the final answer
        // Calculate the final answer based on the dp values
        for (int i = 0; i < getSize(dp[0]); ++i) {
            ans += (long) modPow(2, n + 1 - cnt[i]) * getAt(dp[0], i).node.one % mod; // Update answer
        }
        System.out.println(ans % mod); // Print the final answer
    }

    // Main function to execute the program
    public static void main(String[] args) {
        run(); // Call the run function
    }
}
