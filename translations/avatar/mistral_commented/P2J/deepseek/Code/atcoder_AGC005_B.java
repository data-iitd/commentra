import java.util.*;

public class Main {
    // Define the parent and rank arrays
    static int[] par;
    static int[] rank;
    static int[] size;

    // Define the root function which returns the root of a tree node
    static int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return root(par[x]);
        }
    }

    // Define the same function which checks if two nodes have the same root
    static boolean same(int x, int y) {
        return root(x) == root(y);
    }

    // Define the unite function which merges two trees into one
    static void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (rank[x] < rank[y]) {
                par[x] = y;
                size[y] += size[x];
            } else {
                par[y] = x;
                size[x] += size[y];
                if (rank[x] == rank[y]) {
                    rank[x]++;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize parent and rank arrays with given size
        par = new int[n];
        rank = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        Arrays.fill(rank, 1);
        Arrays.fill(size, 1);

        // Initialize a list b to store the indices of elements in the input array a
        int[] b = new int[n];
        // Iterate through the input array and store the indices of elements in list b
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;
        }

        // Initialize a variable c to store the result
        long c = 0;

        // Iterate through the list b from the second element to the first
        for (int k : b) {
            // Initialize variables l and r to store the sizes of the left and right subtrees
            int l = 1, r = 1;

            // Check if the current node k has a larger element to its left
            if (k > 0 && a[k - 1] > a[k]) {
                // If yes, update l with the size of the left subtree
                l += size[root(k - 1)];
                // Merge the left and current subtrees
                unite(k - 1, k);
            }

            // Check if the current node k has a larger element to its right
            if (k < n - 1 && a[k + 1] > a[k]) {
                // If yes, update r with the size of the right subtree
                r += size[root(k + 1)];
                // Merge the right and current subtrees
                unite(k + 1, k);
            }

            // Update the result variable c with the product of the sizes of the left and right subtrees
            // and the value of the current element
            c += (long) l * r * a[k];
        }

        // Print the result
        System.out.println(c);
    }
}
