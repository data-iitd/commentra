
import java.util.Scanner ;

// Initialize scanner to read input from the standard input
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object

        // Read the first two integers from the standard input
        int N = sc.nextInt(); // Read the number of elements in the array
        int K = sc.nextInt(); // Read the size of the sliding window

        // Allocate an integer array of size N to store the input elements
        int S[] = new int[N];

        // Read the remaining elements of the array from the standard input
        for (int i = 0; i < N; i++) {
            S[i] = sc.nextInt(); // Read the next integer and store it in the array
        }

        // Initialize variables for calculating the answer
        int temp = 0;
        int ans = 1000000000;

        // Check the special case when the size of the sliding window is 1
        if (K == 1) {
            // Iterate through the array to find the minimum absolute value
            for (int i = 0; i < N; i++) {
                temp = S[i]; // Read the current element
                ans = Math.min(Math.abs(temp), ans); // Update the answer if necessary
            }

            // Print the answer
            System.out.println(ans);
        } else if (N - K != 0) { // Check the case when the size of the sliding window is not equal to the size of the array
            // Initialize variables for calculating the minimum and maximum elements in the sliding window
            int min, max;

            // Iterate through all possible positions of the sliding window
            for (int i = 0; i <= N - K; i++) {
                // Find the minimum and maximum elements in the current sliding window
                min = S[i];
                max = S[i + K - 1];

                // Calculate the sum of the absolute values of the minimum and maximum elements
                // and update the answer if necessary
                if (min < 0 && max > 0) {
                    temp = 2 * (Math.abs(min)) + max;
                } else {
                    temp = Math.max(Math.abs(min), Math.abs(max));
                }
                ans = Math.min(ans, temp);
            }

            // Print the answer
            System.out.println(ans);
        } else { // Check the case when the size of the sliding window is equal to the size of the array
            // Find the minimum and maximum elements in the array
            min = S[0];
            max = S[N - 1];

            // Calculate the sum of the absolute values of the minimum and maximum elements
            // and print the answer directly
            if (min < 0 && max > 0) {
                System.out.println(Math.min(2 * (Math.abs(min)) + max, (Math.abs(min)) + 2 * max));
            } else {
                System.out.println(Math.max(Math.abs(min), Math.abs(max)));
            }
        }

        // Close the scanner to release the system resources
        sc.close();
    }
}

