import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    // Define a constant size for the buffered reader
    private static final int SIZE = 1000000;

    // Declare global variables for union-find structure
    private static int[] par, rank;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        
        // Read the number of elements (n) and number of unions (m)
        String[] firstLine = reader.readLine().split(" ");
        int n = Integer.parseInt(firstLine[0]);
        int m = Integer.parseInt(firstLine[1]);
        
        // Read the array of integers
        int[] p = Arrays.stream(reader.readLine().split(" "))
                        .mapToInt(Integer::parseInt)
                        .toArray();
        
        // Initialize the union-find structure
        initialize(n);
        
        // Process each union operation
        for (int i = 0; i < m; i++) {
            String[] unionLine = reader.readLine().split(" ");
            int x = Integer.parseInt(unionLine[0]) - 1; // Convert to zero-based index
            int y = Integer.parseInt(unionLine[1]) - 1; // Convert to zero-based index
            unite(x, y);
        }
        
        // Count the number of elements that are in the same set as their corresponding value in p
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (same(i, p[i] - 1)) { // Check if the element is in the same set (convert p[i] to zero-based index)
                s++;
            }
        }
        
        // Print the result
        System.out.println(s);
    }

    // Function to initialize the union-find structure
    private static void initialize(int n) {
        par = new int[n]; // Create parent array
        rank = new int[n]; // Create rank array
        
        // Set each element's parent to itself
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    // Function to find the root of the element with path compression
    private static int root(int i) {
        if (par[i] == i) {
            return i; // Return the root if it is its own parent
        }
        par[i] = root(par[i]); // Path compression
        return par[i]; // Return the root
    }

    // Function to check if two elements are in the same set
    private static boolean same(int i, int j) {
        return root(i) == root(j); // Check if their roots are the same
    }

    // Function to unite two elements into the same set
    private static void unite(int i, int j) {
        i = root(i); // Find the root of the first element
        j = root(j); // Find the root of the second element
        
        if (i == j) {
            return; // If they are already in the same set, do nothing
        }
        
        // Union by rank
        if (rank[i] < rank[j]) {
            par[i] = j; // Make j the parent of i
        } else {
            par[j] = i; // Make i the parent of j
            if (rank[i] == rank[j]) {
                rank[i]++; // Increment rank if they were the same
            }
        }
    }
}
// <END-OF-CODE>
