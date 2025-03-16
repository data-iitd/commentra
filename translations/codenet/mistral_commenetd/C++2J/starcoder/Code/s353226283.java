
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        // Read input values for n and k
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();

        // Initialize vector'vec' with size 'n'
        int[] vec = new int[n];
        for (int i = 0; i < n; i++) {
            // Read input value for 't' and add it to the vector
            vec[i] = sc.nextInt();
        }

        // Sort the vector'vec' in ascending order
        Arrays.sort(vec);

        // Iterate through the vector with a sliding window of size 'k'
        for (int i = 0; i + k -1 < n; i++) {
            // Calculate the difference between the last and first element of the current window
            int diff = vec[i+k-1] - vec[i];

            // Update the answer if the current difference is smaller than the previous one
            if (diff < ans) {
                ans = diff;
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}

