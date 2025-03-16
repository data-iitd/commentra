import java.util.*;

public class Main {
    static class Ban {
        int l; // left endpoint of the interval
        int r; // right endpoint of the interval
        int val; // value of the interval

        Ban(int l_, int r_, int val_) {
            l = l_;
            r = r_;
            val = val_;
        }
    }

    static class Sp {
        static final int LIM = 20; // Maximum depth of the segment tree
        static final int N = 200007; // Maximum number of elements in the array

        // An array to store the minimum value in each segment of the segment tree
        static int[][] mn = new int[LIM][N];
        static int[] pw = new int[N];

        // A function to initialize the segment tree
        static void init(int[] a) {
            int n = a.length;
            // Initialize the first level of the segment tree
            for (int i = 0; i < n; i++) {
                mn[0][i] = a[i]; // Store the value of the element at index i in the first level of the segment tree
            }
            // Build the segment tree recursively
            for (int i = 0; i + 1 < LIM; i++) {
                for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                    mn[i + 1][j] = Math.min(mn[i][j], mn[i][j + (1 << i)]); // Find the minimum value in the current segment
                }
            }
            // Calculate the power of 2 up to the maximum depth of the segment tree
            pw[1] = 0;
            for (int i = 2; i < N; i++) {
                pw[i] = pw[i / 2] + 1; // Calculate the power of 2 for each index
            }
        }

        // A function to get the minimum value in a segment of the segment tree
        static int get(int l, int r) {
            r++; // Adjust the index of the right endpoint of the segment to be one more than the actual index
            int p = pw[r - l]; // Calculate the depth of the segment tree for the given segment
            return Math.min(mn[p][l], mn[p][r - (1 << p)]); // Return the minimum value in the given segment
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        int n = scanner.nextInt();

        // Read the elements of the array
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        // Initialize some variables
        int[] dl = new int[n]; // An array to store the difference between the index and the index of the element in the array
        long ans = 0; // The answer
        List<Ban> bans = new ArrayList<>(); // A list to store some information about the intervals

        // Calculate the differences between the indices and the elements in the array
        for (int i = 0; i < n; i++) {
            if (a[i] > i) { // Check if the element is out of its position
                System.out.println(-1); // Output -1 if the element is out of its position
                return;
            }
            dl[i] = i - a[i]; // Calculate the difference between the index and the element
        }

        // Calculate the answer and store some information about the intervals in a list
        for (int i = 0; i < n; i++) {
            int r = i; // Initialize a variable to store the right endpoint of the current interval
            while (r + 1 < n && a[r] + 1 == a[r + 1]) { // Check if there is a longer interval with the same value
                r++; // Move to the next index if there is
            }
            ans += a[r]; // Add the value of the right endpoint of the current interval to the answer
            i = r; // Update the index to be the right endpoint of the current interval
            bans.add(new Ban(r - a[r], r, r - a[r])); // Store some information about the current interval in the list
        }

        // Initialize the segment tree using the differences between the indices and the elements in the array
        Sp.init(dl);

        // Check some conditions and calculate the answer if possible
        for (Ban t : bans) {
            if (Sp.get(t.l, t.r) > t.val) { // Check if the minimum value in the segment of the segment tree is greater than the value of the interval
                System.out.println(-1); // Output -1 if the condition is not satisfied
                return;
            }
        }

        // Output the answer
        System.out.println(ans);
    }
}

// <END-OF-CODE>
