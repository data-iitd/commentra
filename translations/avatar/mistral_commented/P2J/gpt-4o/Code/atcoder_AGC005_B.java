import java.util.*;

public class Main {
    static int[] par, rank, size;

    // Define the root function which returns the root of a tree node
    // This function uses recursion to find the root of a node by traversing up the tree
    // until it reaches the root node or a node with the same parent
    static int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return root(par[x]);
        }
    }

    // Define the same function which checks if two nodes have the same root
    // This function is used to check if two nodes belong to the same tree
    static boolean same(int x, int y) {
        return root(x) == root(y);
    }

    // Define the unite function which merges two trees into one
    // This function sets the parent of the smaller tree to the root of the larger tree
    // and updates the size of the root node accordingly
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

        // Initialize parent and rank lists with given size
        par = new int[n];
        rank = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 1;
            size[i] = 1;
        }

        // Initialize a list b to store the indices of elements in the input list a
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;
        }

        // Initialize a variable c to store the result
        long c = 0;

        // Iterate through the list b from the second element to the first
        for (int k = n - 1; k >= 0; k--) {
            int index = b[k];
            long l = 1, r = 1;

            // Check if the current node index has a larger element to its left
            if (index > 0 && a[index - 1] > a[index]) {
                l += size[root(index - 1)];
                unite(index - 1, index);
            }

            // Check if the current node index has a larger element to its right
            if (index + 1 < n && a[index + 1] > a[index]) {
                r += size[root(index + 1)];
                unite(index + 1, index);
            }

            // Update the result variable c with the product of the sizes of the left and right subtrees
            // and the value of the current element
            c += l * r * a[index];
        }

        // Print the result
        System.out.println(c);
    }
}
// <END-OF-CODE>
