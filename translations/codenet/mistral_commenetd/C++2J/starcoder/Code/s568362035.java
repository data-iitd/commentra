import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int Q = sc.nextInt();
        int[] a = new int[Q + 1];
        for (int i = 1; i <= Q; ++i)
            a[i] = sc.nextInt(); // Read queries

        // Initialize variables
        int k = 0, j = Q;
        boolean[] vis = new boolean[n + 1];
        for (int j = Q; j > 0; --j) {
            // Find unvisited elements and add them to the output array
            if (!vis[a[j]]) {
                vis[a[j]] = true; // Mark it as visited
                ++k;
            }
        }

        // Fill the output array with the remaining unvisited elements
        int[] b = new int[m + 1];
        for (int j = m, i = m; i > 0; --i) {
            if (!vis[i]) {
                b[j--] = i; // Add the element to the output array
            }
        }

        // Assign indices to the output array elements
        int[] id = new int[n + 1];
        for (int i = 1; i <= m; ++i)
            id[b[i]] = i; // Assign index i to the element b[i]

        // Process queries
        boolean flag = true;
        int[] cnt = new int[m + 1];
        cnt[0] = n; // Initialize counter array with the number of elements in the input array
        for (int i = Q; i > 0; --i) {
            int t = id[a[i]]; // Get the index of the element a[i] in the output array
            if (cnt[t - 1] > 0) { // If the previous element is still present in the input array
                --cnt[t - 1]; // Decrease its counter
                ++cnt[t]; // Increase the counter of the current element
                vis[t] = true; // Mark it as visited
            }
            else if (!vis[t]) { // If the current element is not present in the input array
                flag = false; // Set the flag to false and break the loop
                break;
            }
        }

        // Check the result
        int l;
        for (l = 0; cnt[l] == 0; ++l); // Find the last element that was present in the input array
        for (int i = l + 1; i < m; ++i)
            flag &= b[i] < b[i + 1]; // Check if the output array is sorted in ascending order after the last present element

        // Print the result
        System.out.println(flag? "Yes" : "No");
    }
}

