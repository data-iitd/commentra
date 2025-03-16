import java.util.*;

public class GraphColoring {
    // Structure to represent an edge in the graph
    static class Edge {
        int to, pre, c; // 'to' is the destination, 'pre' is the previous edge, 'c' is the color
        Edge(int to, int pre, int c) {
            this.to = to;
            this.pre = pre;
            this.c = c;
        }
    }

    static final int N = 100010; // Constants
    static Edge[] e = new Edge[N << 1]; // Array to store edges
    static int[] u = new int[N]; // Array to store the head of each vertex's adjacency list
    static int l = 0; // Edge counter
    static boolean[] vis = new boolean[N]; // vis[i] indicates if vertex i has been visited
    static boolean ok; // Indicates if the graph is valid
    static long[] cnt = new long[3]; // Count of vertices in each of the three color classes
    static int[] d = new int[N]; // Array to store the color of each vertex
    static int T; // Total number of vertices in the current connected component

    // Function to insert an edge into the graph
    static void ins(int a, int b, int c) {
        e[++l] = new Edge(b, u[a], c); // Create a new edge
        u[a] = l; // Update the head of the adjacency list for vertex 'a'
    }

    // Depth-first search function to traverse the graph
    static void dfs(int x, int l) {
        vis[x] = true; // Mark the current vertex as visited
        cnt[l]++; // Increment the count for the current color class
        d[x] = l; // Assign the color to the current vertex

        // Iterate through all edges of the current vertex
        for (int i = u[x]; i > 0; i = e[i].pre) {
            T++; // Increment the total count of vertices in the component
            int v = e[i].to; // Get the destination vertex
            int ec = e[i].c; // Get the color of the edge
            if (!vis[v]) // If the adjacent vertex has not been visited
                dfs(v, (l + ec) % 3); // Recursively visit it with the new color
            else if ((l + ec) % 3 != d[v]) // If the adjacent vertex is visited but has a different color
                ok = false; // Mark the component as invalid
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of vertices and edges
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read edges and construct the graph
        for (int i = 1; i <= m; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt(); // Read each edge
            ins(a, b, 1); // Insert edge from a to b with color 1
            ins(b, a, 2); // Insert edge from b to a with color 2
        }

        long ans = 0; // Variable to store the final answer

        // Iterate through all vertices
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) { // If the vertex has not been visited
                T = 0; // Reset the total count for the new component
                Arrays.fill(cnt, 0); // Reset color counts
                ok = true; // Assume the component is valid
                dfs(i, 0); // Start DFS from the current vertex with color 0
                
                // Calculate the size of the current component
                long s = cnt[0] + cnt[1] + cnt[2];
                
                // If the component is invalid, add the square of its size to the answer
                if (!ok) 
                    ans += s * s;
                else {
                    // If all three color classes are present, calculate combinations
                    if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) 
                        ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
                    else 
                        ans += T / 2; // If not all color classes are present, add half of the total vertices
                }
            }
        }
        
        // Output the final answer
        System.out.println(ans);
        scanner.close();
    }
}

// <END-OF-CODE>
