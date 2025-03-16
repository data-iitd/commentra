import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of elements (N) and the size of the subset (K)
        int N = sc.nextInt();
        int K = sc.nextInt();
        
        // Initialize an array to store the input integers
        int S[] = new int[N];
        
        // Read N integers into the array S
        for (int i = 0; i < N; i++) {
            S[i] = sc.nextInt();
        }
        
        // Initialize temporary variable and answer variable with a large number
        int temp = 0;
        int ans = 1000000000;

        // Case when K is 1: Find the minimum absolute value in the array
        if (K == 1) {
            for (int i = 0; i < N; i++) {
                temp = S[i];
                ans = Math.min(Math.abs(temp), ans); // Update ans with the minimum absolute value
            }
            // Output the result
            System.out.println(ans);
        } 
        // Case when K is not equal to N: Calculate the minimum value based on subsets of size K
        else if (N - K != 0) {
            for (int i = 0; i <= N - K; i++) {
                int min = S[i]; // Minimum value in the current subset
                int max = S[i + K - 1]; // Maximum value in the current subset
                
                // Calculate temp based on the values of min and max
                if (min < 0 && max > 0) {
                    // If the subset contains both negative and positive values
                    temp = Math.min(2 * (-min) + max, (-min) + 2 * max);
                } else {
                    // If the subset contains only negative or only positive values
                    temp = Math.max(Math.abs(min), Math.abs(max));
                }
                
                // Update the answer with the minimum value found
                ans = Math.min(ans, temp);
            }
            // Output the result
            System.out.println(ans);
        } 
        // Case when K is equal to N: Handle the entire array as a single subset
        else {
            int min = S[0]; // Minimum value in the array
            int max = S[N - 1]; // Maximum value in the array
            
            // Check if the array contains both negative and positive values
            if (min < 0 && max > 0) {
                // Calculate and print the minimum value based on the formula
                System.out.println(Math.min(2 * (-min) + max, (-min) + 2 * max));
            } else {
                // Print the maximum absolute value
                System.out.println(Math.max(Math.abs(min), Math.abs(max)));
            }
        }
        
        // Close the scanner to prevent resource leaks
        sc.close();
    }
}
