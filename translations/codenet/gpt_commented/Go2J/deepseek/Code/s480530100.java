import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int q = scanner.nextInt();

        // Initialize a new Fenwick Tree with n elements.
        FenwickTree fw = new FenwickTree(n);

        // Read n integers and add them to the Fenwick Tree.
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            fw.add(i, a);
        }

        // Process q queries.
        for (int i = 0; i < q; i++) {
            int t = scanner.nextInt(); // Read the type of query.
            if (t == 0) {
                // For update queries, read position (p) and value (x) and update the Fenwick Tree.
                int p = scanner.nextInt();
                int x = scanner.nextInt();
                fw.add(p, x);
            } else {
                // For sum queries, read the range (l, r) and output the sum from l to r.
                int l = scanner.nextInt();
                int r = scanner.nextInt();
                System.out.println(fw.sum(l, r));
            }
        }
    }
}

// ** copy from here to your source code **
//
// fenwick tree
//  1. go lang have no generics, so implement int(long long)
//  data type only.
//  2. do not care overflow
//

class FenwickTree {
    private int n;
    private int[] data;

    // Constructor to initialize the Fenwick Tree with n elements.
    public FenwickTree(int n) {
        this.n = n;
        this.data = new int[n];
    }

    // Method to add x to the element at position p.
    public void add(int p, int x) {
        p++; // Increment p to match the 1-based index used in Fenwick Tree
        while (p <= n) {
            data[p - 1] += x; // Update the tree data
            p += p & -p; // Move to the next index
        }
    }

    // Method to calculate the sum of elements in the range [l, r).
    public int sum(int l, int r) {
        return sumRange(r) - sumRange(l); // Return the difference of sums
    }

    // Helper method to calculate the prefix sum from the start to index r.
    private int sumRange(int r) {
        int s = 0; // Initialize sum
        while (r > 0) {
            s += data[r - 1]; // Add the value at index r-1
            r -= r & -r; // Move to the parent index
        }
        return s; // Return the calculated sum
    }
}
