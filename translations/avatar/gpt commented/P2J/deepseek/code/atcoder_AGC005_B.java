import java.util.*;

public class Main {
    // Define a function to find the root of an element using path compression
    static int root(int[] par, int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = root(par, par[x]);
        }
    }

    // Define a function to check if two elements belong to the same set
    static boolean same(int[] par, int x, int y) {
        return root(par, x) == root(par, y);
    }

    // Define a function to unite two sets containing elements z
    static void unite(int[] par, int[] rank, int[] size, int x, int y) {
        // Find the roots of the elements x and y
        x = root(par, x);
        y = root(par, y);

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
        int[] par = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        // Initialize rank and size arrays for union-find structure
        int[] rank = new int[n];  // All elements start with rank 1
        int[] size = new int[n];  // All elements start with size 1
        for (int i = 0; i < n; i++) {
            size[i] = 1;
        }

        // Create an array to store the indices of elements in a
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;  // Store the index of each element in b
        }

        // Initialize a counter for the final result
        long c = 0;

        // Iterate through the array b in reverse order
        for (int k : b) {
            int l = 1, r = 1;  // Initialize left and right sizes

            // Check if the left neighbor exists and is greater
            if (k > 0 && a[k - 1] > a[k]) {
                l += size[root(par, k - 1)];  // Add the size of the left component
                unite(par, rank, size, k - 1, k);  // Unite the left neighbor with the current element
            }

            // Check if the right neighbor exists and is greater
            if (k + 1 < n && a[k + 1] > a[k]) {
                r += size[root(par, k + 1)];  // Add the size of the right component
                unite(par, rank, size, k + 1, k);  // Unite the right neighbor with the current element
            }

            // Update the counter with the product of left size, right size, and the current element's value
            c += l * r * (long) a[k];
        }

        // Print the final result
        System.out.println(c);
    }
}
