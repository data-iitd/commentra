import java.util.*;

public class Main {
    static int n; // Variable to store the number of nodes

    // Function to calculate a unique identifier for a pair of nodes
    static int p(int a, int b) {
        if (a < b) {
            return a + b * n; // Return a unique index based on the order of a and b
        } else {
            return b + a * n; // Return a unique index based on the order of a and b
        }
    }

    static int[][] a = new int[1000][999]; // Adjacency list representation of the graph

    // Arrays to store edges and distances
    static int[] e1 = new int[1000000];
    static int[] e2 = new int[1000000];
    static int[] d = new int[1000000]; // Array to store computed distances
    static boolean[] b = new boolean[1000000]; // Visited flag for nodes

    // Recursive function to compute the maximum distance from a given node
    static int f(int from) {
        if (b[from]) return -1; // Return -1 if the node has already been visited (cycle detected)
        if (d[from] != 0) return d[from]; // Return the computed distance if already calculated
        b[from] = true; // Mark the node as visited
        int to;
        to = e1[from]; // Get the first edge
        int max = 0; // Variable to track the maximum distance
        if (to != 0) {
            int now = f(to); // Recursively compute distance for the first edge
            if (now < 0) return now; // Return if a cycle is detected
            if (now > max) max = now; // Update max if a longer distance is found
        }
        to = e2[from]; // Get the second edge
        if (to != 0) {
            int now = f(to); // Recursively compute distance for the second edge
            if (now < 0) return now; // Return if a cycle is detected
            if (now > max) max = now; // Update max if a longer distance is found
        }
        b[from] = false; // Unmark the node as visited for future calls
        return d[from] = max + 1; // Store and return the computed distance
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt(); // Read the number of nodes
        // Read the adjacency list from input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                a[i][j] = scanner.nextInt() - 1; // Store edges, adjusting for 0-based indexing
            }
        }
        // Build the edge representation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 2; j++) {
                int from = p(i, a[i][j]); // Get unique index for the current edge
                int to = p(i, a[i][j + 1]); // Get unique index for the next edge
                // Store the edges in e1 and e2
                if (e1[from] == 0) {
                    e1[from] = to; // Assign the first edge
                } else if (e2[from] == 0) {
                    e2[from] = to; // Assign the second edge
                } else {
                    System.out.println(-1); // Output -1 if more than two edges are found
                    return; // Exit the program
                }
            }
        }
        int ans = 0; // Variable to store the final answer
        // Compute the maximum distance for each node
        for (int i = 0; i < n; i++) {
            int from = p(i, a[i][0]); // Get unique index for the starting edge
            int now = f(from); // Compute the distance
            if (now < 0) {
                ans = -1; // Set answer to -1 if a cycle is detected
                break; // Exit the loop
            }
            if (now > ans) ans = now; // Update the answer if a longer distance is found
        }
        System.out.println(ans); // Output the final answer
    }
}
