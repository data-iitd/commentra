import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

// Class definition for the Disjoint Set Union (DSU) data structure
public class Main {

    // Initialize the parent array and rank array for the DSU
    private final int[] p; 
    private final int[] r; 

    // Constructor for the DSU with a given size
    public Main(int n) {
        p = new int[n];
        r = new int[n];

        // Initialize the parent array with the index of each element
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    // Find the root of the given element in the DSU
    public int find(int i) {
        int parent = p[i];

        // Base case: if the given element is its own parent, return it
        if (i == parent) {
            return i;
        }

        // Recursive call to find the root of the parent element
        final int result = find(parent);
        p[i] = result; // Update the parent of the given element
        return result;
    }

    // Merge two disjoint sets in the DSU
    public void union(int x, int y) {
        int r0 = find(x); // Find the root of set x
        int r1 = find(y); // Find the root of set y

        // Base case: if the two roots are already the same, return
        if (r1 == r0) {
            return;
        }

        // Update the parent of the smaller rank set to point to the root of the larger rank set
        if (r[r0] > r[r1]) {
            p[r1] = r0;
        } else if (r[r1] > r[r0]) {
            p[r0] = r1;
        } else {
            p[r1] = r0; // Update the parent of the smaller rank set
            r[r0]++; // Increment the rank of the larger rank set
        }
    }

    // Count the number of disjoint sets in the DSU
    public int count() {
        List<Integer> parents = new ArrayList<>(); // Initialize an empty list to store unique parents

        // Iterate through the parent array and find the unique parents
        for (int i = 0; i < p.length; i++) {
            int root = find(i); // Find the root of the current element
            if (!parents.contains(root)) { // If the parent is not already in the list, add it
                parents.add(root);
            }
        }

        // Return the size of the list, which represents the number of disjoint sets
        return parents.size();
    }

    // Override the toString method to print the parent and rank arrays for debugging purposes
    @Override
    public String toString() {
        return "p " + Arrays.toString(p) + " r " + Arrays.toString(r) + "\n";
    }

    // Main method to read input and test the DSU implementation
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Initialize a Scanner to read input from the console

        int n = scanner.nextInt(); // Read the number of elements in the DSU
        Main uf = new Main(n); // Create a new instance of the DSU with the given size

        int unionOps = scanner.nextInt(); // Read the number of union operations
        for (int i = 0; i < unionOps; i++) { // Iterate through the union operations
            int x = scanner.nextInt(); // Read the first element
            int y = scanner.nextInt(); // Read the second element
            uf.union(x, y); // Perform the union operation
        }

        int findOps = scanner.nextInt(); // Read the number of find operations
        for (int i = 0; i < findOps; i++) { // Iterate through the find operations
            int x = scanner.nextInt(); // Read the element to find the root of
            System.out.println("Find(" + x + ") -> Root: " + uf.find(x)); // Print the root of the given element
        }

        System.out.println("Number of disjoint sets: " + uf.count()); // Print the number of disjoint sets in the DSU
        scanner.close(); // Close the Scanner to free up resources
    }
}
