import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of elements (n) and the number of comparisons (m)
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Create an array to hold the heights and a boolean array to track which elements are "good"
        int[] h = new int[n];
        boolean[] good = new boolean[n];

        // Read the heights and initialize the good array to true
        for (int i = 0; i < n; i++) {
            h[i] = sc.nextInt(); // Read height for each element
            good[i] = true;      // Initially, all elements are considered "good"
        }

        // Process each comparison
        for (int i = 0; i < m; i++) {
            int ai = sc.nextInt() - 1; // Read the first index (0-based)
            int bi = sc.nextInt() - 1; // Read the second index (0-based)

            // Compare the heights and update the good array accordingly
            if (h[ai] > h[bi]) {
                good[bi] = false; // If ai is taller, bi is not "good"
            } else if (h[ai] < h[bi]) {
                good[ai] = false; // If bi is taller, ai is not "good"
            } else {
                // If heights are equal, mark both as not "good"
                good[ai] = false;
                good[bi] = false;
            }
        }

        // Count the number of "good" elements
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (good[i]) {
                ans++; // Increment count for each "good" element
            }
        }

        // Print the result: the number of "good" elements
        System.out.println(ans);
    }
}
// <END-OF-CODE>
