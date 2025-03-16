
import java.util.*; // Include the Scanner and ArrayList classes for reading from standard input and creating dynamic arrays

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for reading from standard input
        int N = sc.nextInt(); // Read the number of vertices from the standard input
        int[][] G = new int[N][N]; // Declare a 2D array named G to store the adjacency list
        boolean[] used = new boolean[N]; // Declare a boolean array named used to keep track of visited vertices
        int[] grundy = new int[N]; // Declare an array named grundy to store the Grundy numbers of vertices
        for(int i = 0; i < N-1; i++){ // Iterate through all the edges except the last one
            int x = sc.nextInt(); // Read the first endpoint of an edge from the standard input
            int y = sc.nextInt(); // Read the second endpoint of an edge from the standard input
            x--; y--; // Decrease the indices of x and y by 1 to make them zero-indexed
            G[x][G[x].length] = y; // Add an edge from x to y to the adjacency list
            G[y][G[y].length] = x; // Add a reciprocal edge from y to x to the adjacency list
        }
        dfs(G, 0, used, grundy); // Call the dfs function starting from vertex 0
        if(grundy[0]!= 0){ // Check if the Grundy number of the root vertex is non-zero
            System.out.println("Alice"); // If so, print "Alice" to the standard output
        }else{ // Otherwise
            System.out.println("Bob"); // Print "Bob" to the standard output
        }
    }

    public static void dfs(int[][] G, int v, boolean[] used, int[] grundy){ // Define a recursive depth-first search function named dfs
        used[v] = true; // Set the visited status of the current vertex to true
        grundy[v] = 0; // Initialize the Grundy number of the current vertex to 0
        for(int i = 0; i < G[v].length; i++){ // Iterate through all the neighbors of the current vertex
            int w = G[v][i]; // Assign the neighbor to a temporary variable w
            if(!used[w]){ // If the neighbor has not been visited yet
                dfs(G, w, used, grundy); // Recursively call the dfs function for the neighbor
                grundy[v] ^= (grundy[w]+1); // Update the Grundy number of the current vertex based on the neighbor's Grundy number
            }
        }
    }
}

