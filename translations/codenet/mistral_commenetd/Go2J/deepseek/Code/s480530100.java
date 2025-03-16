import java.util.Scanner;

public class Main {
    // A helper function to print output
    public static void out(Object... x) {
        for (Object obj : x) {
            System.out.println(obj);
        }
    }

    // Main function
    public static void main(String[] args) {
        // Initialize the scanner for reading input
        Scanner sc = new Scanner(System.in);

        // Read the number of elements 'n' and the number of queries 'q' from the standard input
        int n = sc.nextInt();
        int q = sc.nextInt();

        // Initialize a Fenwick Tree of size 'n'
        BIT fw = new BIT(n);

        // Iterate through each element and add it to the Fenwick Tree
        for (int i = 0; i < n; i++) {
            // Read an integer 'a' from the standard input and add it to the Fenwick Tree at index 'i'
            int a = sc.nextInt();
            fw.add(i, a);
        }

        // Iterate through each query
        for (int i = 0; i < q; i++) {
            // Read an integer 't' from the standard input to determine the type of query
            int t = sc.nextInt();

            // If the query is of type 0, read two integers 'p' and 'x' from the standard input and add 'x' to the Fenwick Tree at index 'p'
            if (t == 0) {
                int p = sc.nextInt();
                int x = sc.nextInt();
                fw.add(p, x);
            } else { // If the query is of type 1, read two integers 'l' and 'r' from the standard input and print the sum of elements in the range [l, r]
                int l = sc.nextInt();
                int r = sc.nextInt();
                // Call the Sum function of the Fenwick Tree to get the sum of elements in the range [l, r]
                out(fw.sum(l, r));
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

    // BIT :
    static class BIT {
        int n;
        int[] data;

        // FenwickTree :
        public BIT(int n) {
            this.n = n;
            this.data = new int[n];
        }

        // Add :
        public void add(int p, int x) {
            p++;
            while (p <= n) {
                data[p - 1] += x;
                p += p & -p;
            }
        }

        // Sum :
        public int sum(int l, int r) {
            return sum(r) - sum(l);
        }

        private int sum(int r) {
            int s = 0;
            while (r > 0) {
                s += data[r - 1];
                r -= r & -r;
            }
            return s;
        }
    }
