
import java.io.*;
import java.util.*;

public class s134430594{
    // Constants for limits and size
    static final int LIM = 20; 
    static final int N = 200007;

    // Sparse table for range minimum queries
    static int mn[][];
    // Precomputed powers of 2
    static int pw[];

    // Function to initialize the sparse table
    static void init(int a[]) {
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

    public static void main(String[] args) throws IOException {
        // Optimize input/output
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        // Read the number of elements
        int n = Integer.parseInt(br.readLine());
        int a[] = new int[n];
        // Read the elements into the array
        String[] tokens = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(tokens[i]);
        }

        // Vector to store the difference between index and value
        int dl[] = new int[n];
        for (int i = 0; i < n; i++) {
            // Check if the value exceeds its index
            if (a[i] > i) {
                bw.write("-1\n"); // Output -1 if the condition fails
                bw.flush();
                return;
            }
            // Calculate the difference and store it
            dl[i] = i - a[i];
        }

        // Initialize answer and vector to store ranges
        int ans = 0;
        List<int[]> bans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int r = i;
            // Extend the range while the next value is consecutive
            while (r + 1 < n && a[r] + 1 == a[r + 1]) {
                r++;
            }
            // Update the answer with the maximum value in the range
            ans += a[r];
            i = r; // Move to the end of the current range
            // Store the range in the bans vector
            bans.add(new int[]{r - a[r], r, r - a[r]});
        }

        // Initialize the sparse table with the difference vector
        mn = new int[LIM][N];
        pw = new int[N];
        init(dl);
        // Check each range for validity
        for (int[] t : bans) {
            // If the minimum value in the range exceeds the stored value, output -1
            if (get(t[0], t[1]) > t[2]) {
                bw.write("-1\n");
                bw.flush();
                return;
            }
        }
        // Output the final answer
        bw.write(ans + "\n");
        bw.flush();
    }
}

