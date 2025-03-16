import java.util.*;

public class UnionFind {
    static int[] par, rank, size;

    // Function to find the root of an element using path compression
    static int root(int x) {
        if (par[x] != x) {
            par[x] = root(par[x]);
        }
        return par[x];
    }

    // Function to check if two elements belong to the same set
    static boolean same(int x, int y) {
        return root(x) == root(y);
    }

    // Function to unite two sets containing elements z
    static void unite(int... z) {
        int x = root(z[0]);
        int y = root(z[1]);

        // If the roots are different, unite the sets
        if (x != y) {
            // Union by rank: attach the smaller tree under the larger tree
            if (rank[x] < rank[y]) {
                par[x] = y;  // Make y the parent of x
                size[y] += size[x];  // Update the size of the new root
            } else {
                par[y] = x;  // Make x the parent of y
                size[x] += size[y];  // Update the size of the new root

                // If ranks are equal, increment the rank of the new root
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values: first value is n, followed by n integers
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize the parent array where each element is its own parent
        par = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        // Initialize rank and size arrays for union-find structure
        rank = new int[n];  // All elements start with rank 0
        size = new int[n];  // All elements start with size 1
        Arrays.fill(size, 1); // Set size to 1 for all elements

        // Create an array to store the indices of elements in a
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;  // Store the index of each element in b
        }

        // Initialize a counter for the final result
        long c = 0;

        // Iterate through the array b in reverse order
        for (int k = n - 1; k >= 0; k--) {
            int index = b[k];
            int l = 1, r = 1;  // Initialize left and right sizes

            // Check if the left neighbor exists and is greater
            if (index > 0 && a[index - 1] > a[index]) {
                l += size[root(index - 1)];  // Add the size of the left component
                unite(index - 1, index);  // Unite the left neighbor with the current element
            }

            // Check if the right neighbor exists and is greater
            if (index + 1 < n && a[index + 1] > a[index]) {
                r += size[root(index + 1)];  // Add the size of the right component
                unite(index + 1, index);  // Unite the right neighbor with the current element
            }

            // Update the counter with the product of left size, right size, and the current element's value
            c += (long) l * r * a[index];
        }

        // Print the final result
        System.out.println(c);
    }
}
// <END-OF-CODE>
