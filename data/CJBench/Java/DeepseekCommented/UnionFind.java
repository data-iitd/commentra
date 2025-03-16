import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    private final int[] p; // Array to store the parent of each element
    private final int[] r; // Array to store the rank of each element

    // Constructor to initialize the parent and rank arrays
    public Main(int n) {
        p = new int[n];
        r = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i; // Each element is its own parent initially
        }
    }

    // Method to find the root of a given element using path compression
    public int find(int i) {
        int parent = p[i];
        if (i == parent) {
            return i; // If i is the root, return i
        }
        final int result = find(parent); // Recursively find the root
        p[i] = result; // Path compression: set the parent of i to the root
        return result;
    }

    // Method to union two sets represented by x and y
    public void union(int x, int y) {
        int r0 = find(x); // Find the root of x
        int r1 = find(y); // Find the root of y
        if (r1 == r0) {
            return; // If they are already in the same set, do nothing
        }
        if (r[r0] > r[r1]) {
            p[r1] = r0; // If rank of r0 is greater, make r0 the parent of r1
        } else if (r[r1] > r[r0]) {
            p[r0] = r1; // If rank of r1 is greater, make r1 the parent of r0
        } else {
            p[r1] = r0; // If ranks are equal, make r0 the parent of r1 and increment rank of r0
            r[r0]++;
        }
    }

    // Method to count the number of distinct sets
    public int count() {
        List<Integer> parents = new ArrayList<>();
        for (int i = 0; i < p.length; i++) {
            int root = find(i); // Find the root of each element
            if (!parents.contains(root)) {
                parents.add(root); // Add the root to the list if not already present
            }
        }
        return parents.size(); // Return the number of unique roots
    }

    // Method to print the parent and rank arrays
    @Override
    public String toString() {
        return "p " + Arrays.toString(p) + " r " + Arrays.toString(r) + "\n";
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Read the number of elements
        Main uf = new Main(n);
        int unionOps = scanner.nextInt(); // Read the number of union operations
        for (int i = 0; i < unionOps; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            uf.union(x, y); // Perform union operations
        }
        int findOps = scanner.nextInt(); // Read the number of find operations
        for (int i = 0; i < findOps; i++) {
            int x = scanner.nextInt();
            System.out.println("Find(" + x + ") -> Root: " + uf.find(x)); // Perform find operations and print results
        }
        System.out.println("Number of disjoint sets: " + uf.count()); // Print the number of disjoint sets
        scanner.close();
    }
}
