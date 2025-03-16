
import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object
        int N = sc.nextInt(); // Read the value of N
        int K = sc.nextInt(); // Read the value of K
        int S[] = new int[N]; // Create an array S of size N
        
        // Read the elements of the array S
        for (int i = 0; i < N; i++) {
            S[i] = sc.nextInt();
        }
        
        int temp = 0; // Initialize temp to store intermediate results
        int ans = 1000000000; // Initialize ans to store the minimum difference
        
        // Check if K is equal to 1
        if (K == 1) {
            for (int i = 0; i < N; i++) {
                temp = S[i]; // Store the current element in temp
                ans = Math.min(Math.abs(temp), ans); // Update ans with the minimum absolute value
            }
            System.out.println(ans); // Print the minimum absolute value
        } else if (N - K != 0) { // Check if the length of the subarray is not zero
            for (int i = 0; i <= N - K; i++) {
                int min = S[i]; // Initialize min with the first element of the subarray
                int max = S[i + K - 1]; // Initialize max with the last element of the subarray
                
                // Check if the subarray contains both positive and negative numbers
                if (min < 0 && max > 0) {
                    temp = Math.min(2 * (-min) + max, (-min) + 2 * max); // Calculate the minimum difference
                } else {
                    temp = Math.max(Math.abs(min), Math.abs(max)); // Calculate the maximum absolute value
                }
                
                ans = Math.min(ans, temp); // Update ans with the minimum difference
            }
            System.out.println(ans); // Print the minimum difference
        } else { // If the length of the subarray is zero
            int min = S[0]; // Initialize min with the first element
            int max = S[N - 1]; // Initialize max with the last element
            
            // Check if the array contains both positive and negative numbers
            if (min < 0 && max > 0) {
                System.out.println(Math.min(2 * (-min) + max, (-min) + 2 * max)); // Print the minimum difference
            } else {
                System.out.println(Math.max(Math.abs(min), Math.abs(max))); // Print the maximum absolute value
            }
        }
        
        sc.close(); // Close the Scanner object
    }
}

