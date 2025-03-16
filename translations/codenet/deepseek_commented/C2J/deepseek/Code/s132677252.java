import java.util.*;

public class Main {
    static class DirectedEdge {
        int vertex; // The destination vertex of the edge
        int next;   // The index of the next edge in the adjacency list

        DirectedEdge(int vertex, int next) {
            this.vertex = vertex;
            this.next = next;
        }
    }

    static class DirectedGraph {
        List<DirectedEdge> edge;       // List of edges
        int[] start;         // Array of start pointers for each vertex
        int pointer;        // Current number of edges
        int vertexNum;     // Number of vertices
        int edgeMaxSize;  // Maximum size of the edge list

        DirectedGraph(int vertexNum) {
            this.edge = new ArrayList<>(vertexNum);
            this.start = new int[vertexNum];
            Arrays.fill(this.start, -1); // Initialize all start pointers to -1 (no edges initially)
            this.pointer = 0;
            this.vertexNum = vertexNum;
            this.edgeMaxSize = 1;
        }
    }

    static final int mod = 1000000007;

    static int modPow(int r, int n) {
        int t = 1;
        int s = r;
        while (n > 0) {
            if ((n & 1) != 0) t = (int) ((long) t * s % mod); // If n is odd, multiply t by s
            s = (int) ((long) s * s % mod); // Square s
            n >>= 1; // Halve n
        }
        return t;
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
            one = (one * a[i].zero + zero * a[i].one) % mod; // Calculate the number of ways to have exactly one edge
            zero = zero * a[i].zero % mod; // Calculate the number of ways to have exactly zero edges
            total = total * (a[i].zero + a[i].one) % mod; // Calculate the total number of ways
        }
        return new Node((int) one, (int) ((total + mod - one) % mod)); // Return the merged node
    }

    static class Deque {
        Node[] array;
        int front;
        int last;
        int mask;

        Deque(int size) {
            this.array = new Node[size];
            this.front = 0;
            this.last = 0;
            this.mask = size - 1;
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

        int size() {
            return (last + (~front + 1)) & mask;
        }
    }

    static void run() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of vertices
        int[] p = new int[n + 1]; // Array to store parent pointers
        int[] depth = new int[n + 1]; // Array to store depths of vertices
        int[] cnt = new int[n + 1]; // Array to count vertices at each depth
        cnt[0] = 1; // There is one way to have zero edges (the root itself)
        DirectedGraph g = new DirectedGraph(n + 1); // Initialize the graph
        for (int i = 1; i <= n; ++i) {
            p[i] = scanner.nextInt(); // Read the parent of each vertex
            addEdge(g, p[i], i); // Add the edge to the graph
            depth[i] = depth[p[i]] + 1; // Calculate the depth of each vertex
            cnt[depth[i]]++; // Increment the count of vertices at the current depth
        }
        Deque[] dp = new Deque[n + 1]; // Array to store dynamic programming results
        Deque[] child = new Deque[n + 1]; // Array to store child deques
        Node[] lst = new Node[n + 1]; // Array to store merged nodes
        for (int i = n; i >= 0; --i) {
            int v = i;
            if (g.start[v] == -1) {
                dp[v] = new Deque(1);
                dp[v].pushFront(new Node(1, 1)); // Initialize the dp array for leaf nodes
                continue;
            }
            int len = 0;
            for (int p = g.start[v]; p != -1; p = g.edge.get(p).next) {
                int u = g.edge.get(p).vertex;
                child[len++] = dp[u]; // Collect child deques
            }
            if (len > 1) {
                Arrays.sort(child, 0, len, (a, b) -> Integer.compare(a.size(), b.size())); // Sort child deques by size
                for (int d = 0; d < child[1].size(); ++d) {
                    int j = 0;
                    for (; j < len && d < child[j].size(); ++j) {
                        lst[j] = child[j].getAt(d); // Get nodes at the current depth
                    }
                    child[0].pushFront(merge(lst, j)); // Merge nodes and assign to the first child deque
                }
                for (int j = 1; j < len; ++j) {
                    child[j] = null; // Free memory of unused child deques
                }
            }
            dp[v] = child[0]; // Assign the merged deque to the current vertex
            dp[v].pushFront(new Node(1, 1)); // Add the current node to the dp array
        }
        long ans = 0;
        for (int i = 0; i < dp[0].size(); ++i) {
            ans += (long) modPow(2, n + 1 - cnt[i]) * dp[0].getAt(i).one % mod; // Calculate the answer
        }
        System.out.println(ans % mod); // Print the result
    }

    static void addEdge(DirectedGraph g, int from, int to) {
        if (g.pointer == g.edgeMaxSize) {
            g.edgeMaxSize *= 2;
            g.edge.ensureCapacity(g.edgeMaxSize);
        }
        g.edge.add(new DirectedEdge(to, g.start[from])); // Set the new edge and update the start pointer
        g.start[from] = g.pointer++; // Update the start pointer to the new edge
    }

    public static void main(String[] args) {
        run();
    }
}
