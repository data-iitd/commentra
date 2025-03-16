import java.util.*;

public class DisjointSet {
    static int[] par, rank, size;

    // Define the root function to find the root of a given element in a disjoint set
    static int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            par[x] = root(par[x]); // Path compression
            return par[x];
        }
    }

    // Define the same function to check if two elements are in the same set
    static boolean same(int x, int y) {
        return root(x) == root(y);
    }

    // Define the unite function to merge two sets containing the given elements
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

        par = new int[n];
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        rank = new int[n];
        Arrays.fill(rank, 1);
        size = new int[n];
        Arrays.fill(size, 1);
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[a[i] - 1] = i;
        }
        long c = 0;

        // Process the array in reverse order to calculate the result
        for (int k = n - 1; k >= 0; k--) {
            int l = 1, r = 1;
            if (k > 0 && a[k - 1] > a[k]) {
                l += size[root(k - 1)];
                unite(k - 1, k);
            }
            if (k + 1 < n && a[k + 1] > a[k]) {
                r += size[root(k + 1)];
                unite(k + 1, k);
            }
            c += l * r * a[k];
        }

        // Print the final result
        System.out.println(c);
        scanner.close();
    }
}
// <END-OF-CODE>
