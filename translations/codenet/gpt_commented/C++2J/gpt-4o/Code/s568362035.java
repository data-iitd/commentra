import java.util.Scanner;

public class Main {
    static final int MAXN = 100010; // Define a constant for the maximum size of arrays

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt(); // Number of elements
        int m = scanner.nextInt(); // Maximum value
        int Q = scanner.nextInt(); // Number of queries
        
        int[] a = new int[Q + 1]; // Array to store the queries
        int[] b = new int[MAXN], id = new int[MAXN]; // Array b to store unique values and id to map values to their indices
        boolean[] vis = new boolean[MAXN]; // Boolean array to track which values have been seen
        int[] cnt = new int[MAXN]; // Array to count occurrences of values

        // Read the queries into array a
        for (int i = 1; i <= Q; ++i) {
            a[i] = scanner.nextInt();
        }

        // Process the queries to fill array b with unique values from a
        int k = 0;
        for (int j = Q; j > 0; --j) {
            if (!vis[a[j]]) { // If the value has not been seen yet
                b[++k] = a[j]; // Add it to b
                vis[a[j]] = true; // Mark it as seen
            }
        }

        // Fill the remaining positions in b with the largest unused values up to m
        for (int j = k; j < m; ++j) {
            for (int i = m; i > 0; --i) {
                if (!vis[i]) { // If the value i has not been seen
                    b[j++] = i; // Add it to b
                }
            }
            break; // Exit after filling
        }

        // Map each value in b to its index in id
        for (int i = 1; i <= m; ++i) {
            id[b[i]] = i;
        }

        boolean flag = true; // Initialize a flag to track the validity of the sequence
        cnt[0] = n; // Initialize the count of the first value to n

        // Process the queries in reverse order
        for (int i = Q; i > 0; --i) {
            int t = id[a[i]]; // Get the index of the current query value
            if (cnt[t - 1] > 0) { // If there are available counts for the previous index
                --cnt[t - 1]; // Decrease the count for the previous index
                ++cnt[t]; // Increase the count for the current index
                vis[t] = true; // Mark the current index as seen
            } else if (!vis[t]) { // If the current index has not been seen
                flag = false; // Set the flag to false, indicating an invalid sequence
                break; // Exit the loop
            }
        }

        // Find the first index l where count is non-zero
        int l;
        for (l = 0; cnt[l] == 0; ++l);

        // Check if the remaining values in b are in increasing order
        for (int i = l + 1; i < m; ++i) {
            flag &= b[i] < b[i + 1]; // Update flag based on the order of values in b
        }

        // Output the result based on the flag
        System.out.println(flag ? "Yes" : "No");
        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
