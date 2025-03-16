import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of elements (n) and the size of the subset (k)
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        // Read n integers from input and store them in the vector
        int[] vec = new int[n];
        for (int i = 0; i < n; i++) {
            vec[i] = sc.nextInt();
        }

        // Sort the vector in non-decreasing order
        Arrays.sort(vec);

        // Iterate through the sorted vector to find the minimum difference
        for (int i = 0; i + k - 1 < n; i++) {
            // Calculate the difference between the maximum and minimum of the current subset of size k
            int diff = vec[i + k - 1] - vec[i];

            // Update the minimum difference found so far
            if (diff < ans) {
                ans = diff; // Update ans if a smaller difference is found
            }
        }

        // Output the minimum difference found
        System.out.println(ans);
    }
}

