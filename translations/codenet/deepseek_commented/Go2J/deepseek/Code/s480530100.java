import java.util.Scanner;

public class Main {
    // out is a helper function to print output.
    public static void out(Object... x) {
        for (Object o : x) {
            System.out.println(o);
        }
    }

    // main function is the entry point of the program.
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements (n) and the number of queries (q).
        int n = sc.nextInt();
        int q = sc.nextInt();

        // Initialize a Fenwick Tree with n elements.
        FenwickTree fw = new FenwickTree(n);

        // Read n elements and add them to the Fenwick Tree.
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            fw.add(i, a);
        }

        // Process q queries.
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if (t == 0) {
                // Update the value at position p by adding x to it.
                int p = sc.nextInt();
                int x = sc.nextInt();
                fw.add(p, x);
            } else {
                // Query the sum of elements between indices l and r.
                int l = sc.nextInt();
                int r = sc.nextInt();
                out(fw.sum(l, r));
            }
        }
    }

    // Fenwick Tree implementation

    // BIT represents the Fenwick Tree data structure.
    static class BIT {
        int n;
        int[] data;

        // FenwickTree initializes and returns a new Fenwick Tree with a given size.
        public BIT(int n) {
            this.n = n;
            this.data = new int[n];
        }

        // Add updates the value at position p by adding x to it.
        public void add(int p, int x) {
            p++; // Convert to 1-based index
            for (; p <= n; p += p & -p) {
                data[p - 1] += x;
            }
        }

        // Sum calculates the sum of elements between indices l and r.
        public int sum(int l, int r) {
            return sum(r) - sum(l);
        }

        // sum calculates the prefix sum up to index r.
        public int sum(int r) {
            int s = 0;
            for (; r > 0; r -= r & -r) {
                s += data[r - 1];
            }
            return s;
        }
    }

    static class FenwickTree {
        private BIT bit;

        public FenwickTree(int n) {
            bit = new BIT(n);
        }

        public void add(int p, int x) {
            bit.add(p, x);
        }

        public int sum(int l, int r) {
            return bit.sum(l, r);
        }
    }
}
