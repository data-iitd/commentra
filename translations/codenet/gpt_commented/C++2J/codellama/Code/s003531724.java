
// Java:

// Import the required libraries
import java.util.*;
import java.io.*;

// Class to represent an edge in the graph
class edge {
    int to, pre, c; // 'to' is the destination, 'pre' is the previous edge, 'c' is the color
}

// Class to represent the graph
class graph {
    // Array to store the head of each vertex's adjacency list
    int u[];
    // Array to store the edges
    edge e[];
    // Number of vertices and edges
    int n, m;
    // Array to store the color of each vertex
    int d[];
    // Total number of vertices in the current connected component
    int T;
    // Count of vertices in each of the three color classes
    long cnt[];
    // Variable to store the final answer
    long ans;

    // Constructor to initialize the graph
    graph(int n, int m) {
        this.n = n;
        this.m = m;
        u = new int[n + 1];
        e = new edge[m + 1];
        d = new int[n + 1];
        cnt = new long[3];
        ans = 0;
    }

    // Function to insert an edge into the graph
    void ins(int a, int b, int c) {
        e[++m] = new edge();
        e[m].to = b;
        e[m].pre = u[a];
        e[m].c = c;
        u[a] = m;
    }

    // Macros for accessing edge properties
    #define v e[i].to
    #define ec e[i].c
    #define reg(i,a) for(int i = u[a]; i; i = e[i].pre)

    // Function to traverse the graph
    void dfs(int x, int l) {
        d[x] = l; // Assign the color to the current vertex
        cnt[l]++; // Increment the count for the current color class
        vis[x] = true; // Mark the current vertex as visited
        T++; // Increment the total count for the current connected component

        // Iterate through all edges of the current vertex
        reg(i,x) {
            if (!vis[v]) // If the adjacent vertex has not been visited
                dfs(v, (l + ec) % 3); // Recursively visit it with the new color
            else if ((l + ec) % 3 != d[v]) // If the adjacent vertex is visited but has a different color
                ok = false; // Mark the component as invalid
        }
    }

    // Variable to store the visited vertices
    boolean vis[];
    // Variable to store if the component is valid
    boolean ok;

    // Function to solve the problem
    void solve() {
        // Initialize the visited vertices
        vis = new boolean[n + 1];

        // Iterate through all vertices
        for (int i = 1; i <= n; i++)
            if (!vis[i]) { // If the vertex has not been visited
                T = 0; // Reset the total count for the new component
                for (int j = 0; j < 3; j++)
                    cnt[j] = 0; // Reset color counts
                ok = true; // Assume the component is valid
                dfs(i, 0); // Start DFS from the current vertex with color 0

                // Calculate the size of the current component
                long s = cnt[0] + cnt[1] + cnt[2];

                // If the component is invalid, add the square of its size to the answer
                if (!ok)
                    ans += s * s;
                else {
                    // If all three color classes are present, calculate combinations
                    if (cnt[0] && cnt[1] && cnt[2])
                        ans += cnt[0] * cnt[1] + cnt[1] * cnt[2] + cnt[2] * cnt[0];
                    else
                        ans += T / 2; // If not all color classes are present, add half of the total vertices
                }
            }

        // Output the final answer
        System.out.println(ans);
    }
}

// Main function
public class Main {
    public static void main(String[] args) {
        // Read the number of vertices and edges
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Read edges and construct the graph
        graph g = new graph(n, m);
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            g.ins(a, b, 1); // Insert edge from a to b with color 1
            g.ins(b, a, 2); // Insert edge from b to a with color 2
        }

        // Solve the problem
        g.solve();
    }
}

