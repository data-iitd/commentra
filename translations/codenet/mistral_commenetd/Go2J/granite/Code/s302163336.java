

import java.util.Scanner;

public class s302163336{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements n and m from the standard input
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Initialize h array with n elements and good array with n boolean values
        int[] h = new int[n];
        boolean[] good = new boolean[n];

        // Read n integers from the standard input and initialize h and good arrays
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt();
            // Set good[i] to true initially
            good[i] = true;
        }

        // Process m queries
        for (int i = 0; i < m; i++) {
            // Read two integers ai and bi from the standard input
            int ai = sc.nextInt() - 1;
            int bi = sc.nextInt() - 1;

            // Compare the heights of h[ai] and h[bi]
            if (h[ai] > h[bi]) {
                // If h[ai] is greater than h[bi], mark good[bi] as false
                good[bi] = false;
            } else if (h[ai] < h[bi]) {
                // If h[ai] is less than h[bi], mark good[ai] as false
                good[ai] = false;
            } else {
                // If heights are equal, mark both good[ai] and good[bi] as false
                good[ai] = false;
                good[bi] = false;
            }
        }

        // Initialize answer variable ans to 0
        int ans = 0;

        // Count the number of good elements in the h array
        for (int i = 0; i < n; i++) {
            if (good[i]) {
                // Increment ans if good[i] is true
                ans++;
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}

