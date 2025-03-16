import java.util.*;

public class DirectedGraph {
    // Define types for 32-bit and 64-bit integers
    static final int MOD = 1000000007;

    // Structure to represent a directed edge in the graph
    static class GraphEdge {
        int vertex; // The destination vertex of the edge
        int next;   // The index of the next edge in the adjacency list

        GraphEdge(int vertex, int next) {
            this.vertex = vertex;
            this.next = next;
        }
    }

    // Structure to represent a directed graph
    static class Graph {
        GraphEdge[] edge;          // Array of edges
        int[] start;               // Array to store the starting index of edges for each vertex
        int pointer;               // Current number of edges in the graph
        int vertexNum;             // Number of vertices in the graph
        int edgeMaxSize;           // Maximum size of the edges array

        Graph(int vertexNum) {
            this.vertexNum = vertexNum;
            this.edge = new GraphEdge[1];
            this.start = new int[vertexNum];
            Arrays.fill(this.start, -1);
            this.pointer = 0;
            this.edgeMaxSize = 1;
        }

        // Function to add a directed edge from 'from' to 'to' in the graph
        void addEdge(int from, int to) {
            if (pointer == edgeMaxSize) {
                edgeMaxSize *= 2; // Double the maximum size
                edge = Arrays.copyOf(edge, edgeMaxSize);
            }
            edge[pointer] = new GraphEdge(to, start[from]);
            start[from] = pointer++; // Update the start index for 'from'
        }
    }

    // Function to compute modular exponentiation
    static int modPow(int r, int n) {
        long t = 1; // Result variable
        long s = r; // Base
        while (n > 0) {
            if ((n & 1) != 0) t = (t * s) % MOD; // If n is odd, multiply the result by the base
            s = (s * s) % MOD; // Square the base
            n >>= 1; // Divide n by 2
        }
        return (int) t; // Return the result
    }

    // Structure to represent a node in dynamic programming
    static class Node {
        int one;  // Count of paths ending with 1
        int zero; // Count of paths ending with 0

        Node(int one, int zero) {
            this.one = one;
            this.zero = zero;
        }
    }

    // Function to merge multiple dp nodes
    static Node merge(Node[] a, int n) {
        long one = 0; // Initialize count of paths ending with 1
        long zero = 1; // Initialize count of paths ending with 0
        long total = 1; // Initialize total paths
        for (int i = 0; i < n; ++i) {
            one = (one * a[i].zero + zero * a[i].one) % MOD; // Update count of paths ending with 1
            zero = (zero * a[i].zero) % MOD; // Update count of paths ending with 0
            total = (total * (a[i].zero + a[i].one)) % MOD; // Update total paths
        }
        return new Node((int) one, (int) ((total + MOD - one) % MOD)); // Return merged node
    }

    // Structure to represent a deque (double-ended queue)
    static class Deque {
        Node[] array; // Array to store deque values
        int front;    // Index of the front element
        int last;     // Index of the last element
        int mask;     // Mask for circular indexing

        Deque() {
            int len = 2; // Initial length of the deque
            this.array = new Node[len];
            this.front = this.last = 0; // Initialize front and last indices
            this.mask = len - 1; // Set the mask for circular indexing
        }

        // Function to get the size of the deque
        int getSize() {
            return (last + (~front + 1)) & mask; // Calculate the size using circular indexing
        }

        // Function to reallocate memory for the deque when it is full
        void reallocate() {
            Node[] newArray = new Node[2 * (mask + 1)];
            int k = 0; // Index for the new array
            for (int i = front; i != last; i = (i + 1) & mask) {
                newArray[k++] = array[i];
            }
            array = newArray; // Update the deque's array to the new array
            front = 0; // Reset front index
            last = k; // Update last index
            mask = 2 * mask + 1; // Update the mask for the new size
        }

        // Function to push a value to the front of the deque
        void pushFront(Node v) {
            if (((last + 1) & mask) == front) {
                reallocate(); // Reallocate if full
            }
            front = (front + mask) & mask; // Move front index backwards
            array[front] = v; // Assign the value at the front
        }

        // Function to get the value at a specific index in the deque
        Node getAt(int x) {
            return array[(front + x) & mask]; // Return the value using circular indexing
        }

        // Function to assign a value at a specific index in the deque
        void assignAt(int x, Node v) {
            array[(front + x) & mask] = v; // Assign the value using circular indexing
        }
    }

    // Main function to run the algorithm
    static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Number of vertices
        int[] p = new int[n + 1];
        int[] depth = new int[n + 1];
        int[] cnt = new int[n + 1];
        cnt[0] = 1; // Initialize count for depth 0
        Graph g = new Graph(n + 1); // Create a new graph

        // Read edges and build the graph
        for (int i = 1; i <= n; ++i) {
            p[i] = scanner.nextInt(); // Read parent for vertex i
            g.addEdge(p[i], i); // Add edge from parent to current vertex
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
                dp[v] = new Deque(); // Create a new deque for this vertex
                dp[v].pushFront(new Node(1, 1)); // Initialize with base case
                continue; // Move to the next vertex
            }
            int len = 0; // Length of child deques
            // Collect child deques for the current vertex
            for (int pIndex = g.start[v]; pIndex != -1; pIndex = g.edge[pIndex].next) {
                int u = g.edge[pIndex].vertex; // Get child vertex
                child[len++] = dp[u]; // Store child deque
            }
            // If there are multiple child deques, merge them
            if (len > 1) {
                Arrays.sort(child, 0, len, (a, b) -> Integer.compare(b.getSize(), a.getSize())); // Sort child deques by size
                // Merge the child deques
                for (int d = 0; d < child[0].getSize(); ++d) {
                    int j = 0;
                    for (; j < len && d < child[j].getSize(); ++j) {
                        lst[j] = child[j].getAt(d); // Get nodes from child deques
                    }
                    child[0].assignAt(d, merge(lst, j)); // Merge and assign to the first child
                }
                // Free the other child deques
                for (int j = 1; j < len; ++j) {
                    child[j] = null; // Allow garbage collection
                }
            }
            dp[v] = child[0]; // Assign the merged deque to the current vertex
            dp[v].pushFront(new Node(1, 1)); // Add the base case to the front
        }

        long ans = 0; // Variable to store the final answer
        // Calculate the final answer based on the dp values
        for (int i = 0; i < dp[0].getSize(); ++i) {
            ans += (long) modPow(2, n + 1 - cnt[i]) * dp[0].getAt(i).one % MOD; // Update answer
        }
        System.out.println(ans % MOD); // Print the final answer
    }

    // Main function to execute the program
    public static void main(String[] args) {
        run(); // Call the run function
    }
}

// <END-OF-CODE>
