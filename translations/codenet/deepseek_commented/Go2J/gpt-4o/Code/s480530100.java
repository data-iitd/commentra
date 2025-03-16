import java.util.Scanner;

// Fenwick Tree implementation
class FenwickTree {
    private int n;
    private int[] data;

    // Constructor to initialize the Fenwick Tree with a given size
    public FenwickTree(int n) {
        this.n = n;
        this.data = new int[n];
    }

    // Add updates the value at position p by adding x to it
    public void add(int p, int x) {
        p++; // Convert to 1-based index
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p; // Move to the next node
        }
    }

    // Sum calculates the sum of elements between indices l and r
    public int sum(int l, int r) {
        return sum(r) - sum(l);
    }

    // sum calculates the prefix sum up to index r
    private int sum(int r) {
        int s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r; // Move to the parent node
        }
        return s;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements (n) and the number of queries (q)
        int n = sc.nextInt();
        int q = sc.nextInt();

        // Initialize a Fenwick Tree with n elements
        FenwickTree fw = new FenwickTree(n);

        // Read n elements and add them to the Fenwick Tree
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            fw.add(i, a);
        }

        // Process q queries
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if (t == 0) {
                // Update the value at position p by adding x to it
                int p = sc.nextInt();
                int x = sc.nextInt();
                fw.add(p, x);
            } else {
                // Query the sum of elements between indices l and r
                int l = sc.nextInt();
                int r = sc.nextInt();
                System.out.println(fw.sum(l, r));
            }
        }

        sc.close();
    }
}

// <END-OF-CODE>
