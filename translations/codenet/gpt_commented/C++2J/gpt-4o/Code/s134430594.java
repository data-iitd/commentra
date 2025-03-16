import java.util.*;

public class Main {
    // Define a class to represent a range with a value
    static class Ban {
        int l; // Left index of the range
        int r; // Right index of the range
        int val; // Value associated with the range

        // Parameterized constructor
        Ban(int l_, int r_, int val_) {
            l = l_;
            r = r_;
            val = val_;
        }
    }

    static class Sp {
        // Constants for limits and size
        static final int LIM = 20; 
        static final int N = 200007;

        // Sparse table for range minimum queries
        static int[][] mn = new int[LIM][N];
        // Precomputed powers of 2
        static int[] pw = new int[N];

        // Function to initialize the sparse table
        static void init(int[] a) {
            int n = a.length;
            // Fill the first row of the sparse table
            for (int i = 0; i < n; i++) {
                mn[0][i] = a[i]; 
            }
            // Build the sparse table for range maximum queries
            for (int i = 0; i + 1 < LIM; i++) {
                for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                    mn[i + 1][j] = Math.max(mn[i][j], mn[i][j + (1 << i)]);
                }
            }
            // Precompute powers of 2 for later use
            pw[1] = 0;
            for (int i = 2; i < N; i++) {
                pw[i] = pw[i / 2] + 1;
            }
        } 

        // Function to get the minimum value in the range [l, r]
        static int get(int l, int r) {
            r++;
            int p = pw[r - l];
            return Math.min(mn[p][l], mn[p][r - (1 << p)]);
        }
    }

    public static void main(String[] args) {
        // Optimize input/output
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements
        int n = scanner.nextInt();
        int[] a = new int[n];
        // Read the elements into the array
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Array to store the difference between index and value
        int[] dl = new int[n];
        for (int i = 0; i < n; i++) {
            // Check if the value exceeds its index
            if (a[i] > i) {
                System.out.println(-1); // Output -1 if the condition fails
                return;
            }
            // Calculate the difference and store it
            dl[i] = i - a[i];
        }

        // Initialize answer and list to store ranges
        long ans = 0;
        List<Ban> bans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int r = i;
            // Extend the range while the next value is consecutive
            while (r + 1 < n && a[r] + 1 == a[r + 1]) {
                r++;
            }
            // Update the answer with the maximum value in the range
            ans += a[r];
            i = r; // Move to the end of the current range
            // Store the range in the bans list
            bans.add(new Ban(r - a[r], r, r - a[r]));
        }

        // Initialize the sparse table with the difference array
        Sp.init(dl);
        // Check each range for validity
        for (Ban t : bans) {
            // If the minimum value in the range exceeds the stored value, output -1
            if (Sp.get(t.l, t.r) > t.val) {
                System.out.println(-1);
                return;
            }
        }
        // Output the final answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
