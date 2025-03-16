import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements (n) and the maximum value (m)
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        // Read the number of queries (Q)
        int Q = sc.nextInt();
        
        // Read the queries into array a
        int[] a = new int[Q + 1];
        for (int i = 1; i <= Q; ++i)
            a[i] = sc.nextInt();
        
        // Process the queries to fill array b with unique values from a
        int k = 0;
        for (int j = Q; j > 0; --j) {
            int t = a[j];
            if (k == 0 || t!= b[k])
                b[++k] = t;
        }
        
        // Fill the remaining positions in b with the largest unused values up to m
        for (int j = m, i = m; i > 0; --i)
            if (i!= b[j])
                b[j--] = i;
        
        // Map each value in b to its index in id
        int[] id = new int[m + 1];
        for (int i = 1; i <= m; ++i)
            id[b[i]] = i;

        boolean flag = true; // Initialize a flag to track the validity of the sequence
        int[] cnt = new int[m + 1]; // Initialize the count of each value to 0
        cnt[0] = n; // Initialize the count of the first value to n
        
        // Process the queries in reverse order
        for (int i = Q; i > 0; --i) {
            int t = id[a[i]]; // Get the index of the current query value
            if (cnt[t - 1] > 0) { // If there are available counts for the previous index
                --cnt[t - 1]; // Decrease the count for the previous index
                ++cnt[t]; // Increase the count for the current index
            }
            else if (cnt[t] == 0) { // If the current index has not been seen
                flag = false; // Set the flag to false, indicating an invalid sequence
                break; // Exit the loop
            }
        }

        // Find the first index l where count is non-zero
        int l;
        for (l = 0; cnt[l] == 0; ++l);
        
        // Check if the remaining values in b are in increasing order
        for (int i = l + 1; i < m; ++i)
            flag &= b[i] < b[i + 1]; // Update flag based on the order of values in b
        
        // Output the result based on the flag
        System.out.println(flag? "Yes" : "No");
    }
}

