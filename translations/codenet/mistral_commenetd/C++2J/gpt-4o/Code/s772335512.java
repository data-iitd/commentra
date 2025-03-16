import java.util.ArrayList; // Import the ArrayList class for dynamic arrays
import java.util.List; // Import the List interface
import java.util.Scanner; // Import the Scanner class for input operations

public class Main { // Define the main class
    static List<Integer>[] G; // Declare an adjacency list named G
    static boolean[] used; // Declare a boolean array named used to keep track of visited vertices
    static int[] grundy; // Declare an array named grundy to store the Grundy numbers of vertices

    static void dfs(int v) { // Define a recursive depth-first search function named dfs
        used[v] = true; // Set the visited status of the current vertex to true
        grundy[v] = 0; // Initialize the Grundy number of the current vertex to 0
        for (int w : G[v]) { // Iterate through all the neighbors of the current vertex
            if (!used[w]) { // If the neighbor has not been visited yet
                dfs(w); // Recursively call the dfs function for the neighbor
                grundy[v] ^= (grundy[w] + 1); // Update the Grundy number of the current vertex based on the neighbor's Grundy number
            }
        }
    }

    public static void main(String[] args) { // Define the main function
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int N = scanner.nextInt(); // Read the number of vertices from the standard input
        G = new ArrayList[N]; // Initialize the adjacency list
        for (int i = 0; i < N; i++) {
            G[i] = new ArrayList<>(); // Create an ArrayList for each vertex
        }
        used = new boolean[N]; // Initialize the used array
        grundy = new int[N]; // Initialize the grundy array

        for (int i = 0; i < N - 1; i++) { // Iterate through all the edges except the last one
            int x = scanner.nextInt(); // Read the first endpoint of an edge
            int y = scanner.nextInt(); // Read the second endpoint of an edge
            x--; // Decrease the index of x by 1 to make it zero-indexed
            y--; // Decrease the index of y by 1 to make it zero-indexed
            G[x].add(y); // Add an edge from x to y to the adjacency list
            G[y].add(x); // Add a reciprocal edge from y to x to the adjacency list
        }
        dfs(0); // Call the dfs function starting from vertex 0
        if (grundy[0] != 0) { // Check if the Grundy number of the root vertex is non-zero
            System.out.println("Alice"); // If so, print "Alice" to the standard output
        } else { // Otherwise
            System.out.println("Bob"); // Print "Bob" to the standard output
        }
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
