import java.util.*;

public class DirectedGraph {
    static final int MOD = 1000000007;

    static class GraphEdge {
        int vertex; // The destination vertex of the edge
        int next;   // The index of the next edge in the adjacency list

        GraphEdge(int vertex, int next) {
            this.vertex = vertex;
            this.next = next;
        }
    }

    static class DirectedGraph {
        GraphEdge[] edge;       // Array of edges
        int[] start;            // Array of start pointers for each vertex
        int pointer;            // Current number of edges
        int vertexNum;          // Number of vertices
        int edgeMaxSize;        // Maximum size of the edge array

        DirectedGraph(int vertexNum) {
            this.vertexNum = vertexNum;
            this.edge = new GraphEdge[1];
            this.start = new int[vertexNum];
            Arrays.fill(this.start, -1); // Initialize all start pointers to -1 (no edges initially)
            this.pointer = 0;
            this.edgeMaxSize = 1;
        }

        void addEdge(int from, int to) {
            if (pointer == edgeMaxSize) {
                edgeMaxSize *= 2;
                edge = Arrays.copyOf(edge, edgeMaxSize);
            }
            edge[pointer] = new GraphEdge(to, start[from]); // Set the new edge and update the start pointer
            start[from] = pointer++; // Update the start pointer to the new edge
        }
    }

    static int modPow(int r, int n) {
        long t = 1;
        long s = r;
        while (n > 0) {
            if ((n & 1) != 0) t = t * s % MOD; // If n is odd, multiply t by s
            s = s * s % MOD; // Square s
            n >>= 1; // Halve n
        }
        return (int) t;
    }

    static class Node {
        int one;  // Number of ways to have exactly one edge
        int zero; // Number of ways to have exactly zero edges

        Node(int one, int zero) {
            this.one = one;
            this.zero = zero;
        }
    }

    static Node merge(Node[] a, int n) {
        long one = 0;
        long zero = 1;
        long total = 1;
        for (int i = 0; i < n; ++i) {
            one = (one * a[i].zero + zero * a[i].one) % MOD; // Calculate the number of ways to have exactly one edge
            zero = zero * a[i].zero % MOD; // Calculate the number of ways to have exactly zero edges
            total = total * (a[i].zero + a[i].one) % MOD; // Calculate the total number of ways
        }
        return new Node((int) one, (int) ((total + MOD - one) % MOD)); // Return the merged node
    }

    static class Deque {
        Node[] array;
        int front;
        int last;
        int mask;

        Deque() {
            int len = 2;
            this.array = new Node[len];
            this.front = this.last = 0;
            this.mask = len - 1;
        }

        int getSize() {
            return (last + (~front + 1)) & mask;
        }

        void realloc() {
            Node[] newArray = new Node[2 * (mask + 1)];
            int k = 0;
            for (int i = front; i != last; i = (i + 1) & mask) {
                newArray[k++] = array[i];
            }
            array = newArray;
            front = 0;
            last = k;
            mask = 2 * mask + 1;
        }

        void pushFront(Node v) {
            if (((last + 1) & mask) == front) {
                realloc();
            }
            front = (front + mask) & mask;
            array[front] = v;
        }

        Node getAt(int x) {
            return array[(front + x) & mask];
        }

        void assignAt(int x, Node v) {
            array[(front + x) & mask] = v;
        }
    }

    public static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of vertices
        int[] p = new int[n + 1]; // Array to store parent pointers
        int[] depth = new int[n + 1]; // Array to store depths of vertices
        int[] cnt = new int[n + 1]; // Array to count vertices at each depth
        cnt[0] = 1; // There is one way to have zero edges (the root itself)
        DirectedGraph g = new DirectedGraph(n + 1); // Initialize the graph

        for (int i = 1; i <= n; ++i) {
            p[i] = scanner.nextInt(); // Read the parent of each vertex
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
                dp[v].pushFront(new Node(1, 1)); // Initialize the dp array for leaf nodes
                continue;
            }
            int len = 0;
            for (int pIndex = g.start[v]; pIndex != -1; pIndex = g.edge[pIndex].next) {
                int u = g.edge[pIndex].vertex;
                child[len++] = dp[u]; // Collect child deques
            }
            if (len > 1) {
                Arrays.sort(child, 0, len, (a, b) -> Integer.compare(b.getSize(), a.getSize())); // Sort child deques by size
                for (int d = 0; d < child[1].getSize(); ++d) {
                    int j = 0;
                    for (; j < len && d < child[j].getSize(); ++j) {
                        lst[j] = child[j].getAt(d); // Get nodes at the current depth
                    }
                    child[0].assignAt(d, merge(lst, j)); // Merge nodes and assign to the first child deque
                }
                for (int j = 1; j < len; ++j) {
                    child[j] = null; // Free memory of unused child deques
                }
            }
            dp[v] = child[0]; // Assign the merged deque to the current vertex
            dp[v].pushFront(new Node(1, 1)); // Add the current node to the dp array
        }

        long ans = 0;
        for (int i = 0; i < dp[0].getSize(); ++i) {
            ans += (long) modPow(2, n + 1 - cnt[i]) * dp[0].getAt(i).one % MOD; // Calculate the answer
        }
        System.out.println(ans % MOD); // Print the result
    }

    public static void main(String[] args) {
        run();
    }
}

// <END-OF-CODE>
