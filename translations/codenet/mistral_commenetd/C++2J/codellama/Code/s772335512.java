
import java.util.Scanner; // Import the Scanner class for input and output operations
import java.util.Vector; // Import the Vector class for creating dynamic arrays

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for input and output operations
        int N = sc.nextInt(); // Read the number of vertices from the standard input
        Vector<Integer>[] G = new Vector[100000]; // Declare an adjacency list named G with a maximum size of 100000
        boolean[] used = new boolean[100000]; // Declare a boolean array named used to keep track of visited vertices
        int[] grundy = new int[100000]; // Declare an array named grundy to store the Grundy numbers of vertices

        for (int i = 0; i < N - 1; i++) { // Iterate through all the edges except the last one
            int x = sc.nextInt(); // Read the first endpoint of an edge from the standard input
            int y = sc.nextInt(); // Read the second endpoint of an edge from the standard input
            x--; y--; // Decrease the indices of x and y by 1 to make them zero-indexed
            if (G[x] == null) { // If the adjacency list of the first endpoint is empty
                G[x] = new Vector<Integer>(); // Create a new adjacency list for the first endpoint
            }
            G[x].add(y); // Add an edge from the first endpoint to the second endpoint to the adjacency list
            if (G[y] == null) { // If the adjacency list of the second endpoint is empty
                G[y] = new Vector<Integer>(); // Create a new adjacency list for the second endpoint
            }
            G[y].add(x); // Add a reciprocal edge from the second endpoint to the first endpoint to the adjacency list
        }

        dfs(0, G, used, grundy); // Call the dfs function starting from vertex 0
        if (grundy[0] != 0) { // Check if the Grundy number of the root vertex is non-zero
            System.out.println("Alice"); // If so, print "Alice" to the standard output
        } else { // Otherwise
            System.out.println("Bob"); // Print "Bob" to the standard output
        }
    }

    public static void dfs(int v, Vector<Integer>[] G, boolean[] used, int[] grundy) {
        used[v] = true; // Set the visited status of the current vertex to true
        grundy[v] = 0; // Initialize the Grundy number of the current vertex to 0
        for (int i = 0; i < G[v].size(); i++) { // Iterate through all the neighbors of the current vertex
            int w = G[v].get(i); // Assign the neighbor to a temporary variable w
            if (!used[w]) { // If the neighbor has not been visited yet
                dfs(w, G, used, grundy); // Recursively call the dfs function for the neighbor
                grundy[v] ^= (grundy[w] + 1); // Update the Grundy number of the current vertex based on the neighbor's Grundy number
            }
        }
    }
}

