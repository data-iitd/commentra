
import java.util.*;
import java.io.*;

public class Main {
    // Type definitions for convenience
    static class edge {
        int to, pre, c; // 'to' is the destination, 'pre' is the previous edge, 'c' is the color
    }

    // Array to store the head of each vertex's adjacency list
    static int u[] = new int[N];
    static int l = 0;

    // Function to insert an edge into the graph
    static void ins(int a, int b, int c) { 
        e[++l] = (edge){b, u[a], c}; // Create a new edge
        u[a] = l; // Update the head of the adjacency list for vertex 'a'
    }

    // Macros for accessing edge properties
    static int v(int i) { return e[i].to; }
    static int ec(int i) { return e[i].c; }
    static void reg(int i, int a) { for(int j = u[a]; j; j = e[j].pre) i = e[j].to; }

    // Global variables
    static int n, m; // Number of vertices and edges
    static boolean vis[] = new boolean[N]; // vis[i] indicates if vertex i has been visited
    static long cnt[] = new long[3]; // Count of vertices in each of the three color classes
    static int d[] = new int[N]; // Array to store the color of each vertex
    static int T; // Total number of vertices in the current connected component
    static boolean ok; // ok indicates if the graph is valid
    static edge e[] = new edge[N << 1]; // Array to store edges

    // Depth-first search function to traverse the graph
    static void dfs(int x, int l) {
        vis[x] = true; // Mark the current vertex as visited
        cnt[l]++; // Increment the count for the current color class
        d[x] = l; // Assign the color to the current vertex

        // Iterate through all edges of the current vertex
        reg(i,x) {
            T++; // Increment the total count of vertices in the component
            if (!vis[v(i)]) // If the adjacent vertex has not been visited
                dfs(v(i), (l + ec(i)) % 3); // Recursively visit it with the new color
            else if ((l + ec(i)) % 3!= d[v(i)]) // If the adjacent vertex is visited but has a different color
                ok = false; // Mark the component as invalid
        }
    }

    public static void main(String[] args) {
        // Read the number of vertices and edges
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        
        // Read edges and construct the graph
        rep(i,1,m) {
            int a, b; 
            a = sc.nextInt();
            b = sc.nextInt(); // Read each edge
            ins(a, b, 1); // Insert edge from a to b with color 1
            ins(b, a, 2); // Insert edge from b to a with color 2
        }

        long ans = 0; // Variable to store the final answer

        // Iterate through all vertices
        rep(i,1,n) 
            if (!vis[i]) { // If the vertex has not been visited
                T = 0; // Reset the total count for the new component
                rep(j,0,2) cnt[j] = 0; // Reset color counts
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

