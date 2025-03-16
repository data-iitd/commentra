import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Arrays to hold the parent and rank of each element
    private final int[] p; 
    private final int[] r; 

    // Constructor to initialize the union-find structure
    public Main(int n) {
        p = new int[n]; // Initialize parent array
        r = new int[n]; // Initialize rank array
        // Each element is its own parent initially
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    // Find the root of the element 'i' with path compression
    public int find(int i) {
        int parent = p[i]; // Get the parent of the current element
        // If the current element is its own parent, return it
        if (i == parent) {
            return i;
        }
        // Recursively find the root and apply path compression
        final int result = find(parent);
        p[i] = result; // Update the parent of 'i' to its root
        return result; // Return the root
    }

    // Union operation to connect two elements x and y
    public void union(int x, int y) {
        int r0 = find(x); // Find the root of x
        int r1 = find(y); // Find the root of y
        // If both elements have the same root, they are already connected
        if (r1 == r0) {
            return;
        }
        // Union by rank to keep the tree flat
        if (r[r0] > r[r1]) {
            p[r1] = r0; // Make r0 the parent of r1
        } else if (r[r1] > r[r0]) {
            p[r0] = r1; // Make r1 the parent of r0
        } else {
            p[r1] = r0; // Make r0 the parent of r1
            r[r0]++; // Increase the rank of r0
        }
    }

    // Count the number of disjoint sets
    public int count() {
        List<Integer> parents = new ArrayList<>(); // List to hold unique roots
        // Iterate through all elements to find their roots
        for (int i = 0; i < p.length; i++) {
            int root = find(i); // Find the root of the current element
            // Add the root to the list if it's not already present
            if (!parents.contains(root)) {
                parents.add(root);
            }
        }
        // Return the number of unique roots, which is the number of disjoint sets
        return parents.size();
    }

    // Override toString method for easy debugging
    @Override
    public String toString() {
        return "p " + Arrays.toString(p) + " r " + Arrays.toString(r) + "\n";
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        int n = scanner.nextInt(); // Read the number of elements
        Main uf = new Main(n); // Initialize the union-find structure
        int unionOps = scanner.nextInt(); // Read the number of union operations
        // Perform union operations based on user input
        for (int i = 0; i < unionOps; i++) {
            int x = scanner.nextInt(); // Read first element for union
            int y = scanner.nextInt(); // Read second element for union
            uf.union(x, y); // Perform the union operation
        }
        int findOps = scanner.nextInt(); // Read the number of find operations
        // Perform find operations based on user input
        for (int i = 0; i < findOps; i++) {
            int x = scanner.nextInt(); // Read element to find
            System.out.println("Find(" + x + ") -> Root: " + uf.find(x)); // Output the root
        }
        // Output the number of disjoint sets
        System.out.println("Number of disjoint sets: " + uf.count());
        scanner.close(); // Close the scanner
    }
}
