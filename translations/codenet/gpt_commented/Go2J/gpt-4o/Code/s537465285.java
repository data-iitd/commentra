import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    // Initialize buffered reader and writer for input and output
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

    // Function to read the next line from standard input
    private static String nextLine() throws IOException {
        return reader.readLine();
    }

    // Function to read the next integer from standard input
    private static int nextInt() throws IOException {
        return Integer.parseInt(nextLine());
    }

    // Function to write output to standard output
    private static void write(Object s) throws IOException {
        writer.write(s.toString());
        writer.newLine();
    }

    // Function to flush the buffered writer to output
    private static void output() throws IOException {
        writer.flush();
    }

    // Function to check if the graph is bipartite
    private static boolean isBipartite(String[] S) {
        int N = S.length; // Get the number of nodes
        int[] D = new int[N]; // Distance array to store levels of nodes
        D[0] = 1; // Start with the first node at level 1
        Queue<Integer> Q = new LinkedList<>(); // Queue for BFS
        Q.add(0); // Start BFS from the first node
        boolean ret = true; // Variable to track if the graph is bipartite

        // Perform BFS to check for bipartiteness
        while (!Q.isEmpty() && ret) {
            int q = Q.poll(); // Current node
            for (int j = 0; j < N; j++) {
                char s = S[q].charAt(j);
                if (s == '0') {
                    continue; // Skip if there is no edge
                }
                if (D[j] == 0) {
                    // Assign level to the adjacent node
                    D[j] = D[q] + 1;
                    Q.add(j); // Add to queue
                } else {
                    // Check if the adjacent node has the same level
                    if (D[j] % 2 == D[q] % 2) {
                        ret = false; // Not bipartite
                        break;
                    }
                }
            }
        }
        return ret; // Return the result of bipartiteness check
    }

    // Function to perform the Floyd-Warshall algorithm to find the longest shortest path
    private static int warshallFloyd(String[] S) {
        int N = S.length; // Get the number of nodes
        int[][] G = new int[N][N]; // Initialize the graph matrix

        // Initialize the graph with distances
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    G[i][j] = 0; // Distance to self is 0
                } else if (S[i].charAt(j) == '0') {
                    G[i][j] = N; // No edge, set to a large value
                } else {
                    G[i][j] = 1; // Edge exists, set distance to 1
                }
            }
        }

        // Floyd-Warshall algorithm to find shortest paths
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (G[i][k] + G[k][j] < G[i][j]) {
                        G[i][j] = G[i][k] + G[k][j]; // Update shortest path
                    }
                }
            }
        }

        // Find the maximum distance in the graph
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (ans < G[i][j] && G[i][j] < N) {
                    ans = G[i][j]; // Update maximum distance
                }
            }
        }
        return ans + 1; // Return the maximum distance found
    }

    // Main function to execute the program
    public static void main(String[] args) throws IOException {
        int N = nextInt(); // Read the number of nodes
        String[] S = new String[N]; // Initialize the adjacency matrix
        for (int i = 0; i < N; i++) {
            S[i] = nextLine(); // Read each line of the adjacency matrix
        }

        // Check if the graph is bipartite and process accordingly
        if (!isBipartite(S)) {
            write(-1); // Output -1 if not bipartite
        } else {
            write(warshallFloyd(S)); // Output the longest shortest path if bipartite
        }

        output(); // Flush the output
    }
}
// <END-OF-CODE>
