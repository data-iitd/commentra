import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variable N to hold the number of elements
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        
        // Declare variables for iteration, sum, weighted sum, and arrays
        long sum = 0; // To store the total sum of elements
        long wa = 0;  // To store the weighted sum (1 + 2 + ... + N)
        int[] A = new int[N]; // Array to hold the input elements
        int[] sa = new int[N]; // Array to hold the adjusted differences
        int ans = 0; // Variable to store the final answer (0 or 1)
        int shou; // Variable to store the average value
        long min = 1123456789; // A large number for comparison (not used in this code)
        
        // Read the elements into array A and calculate the total sum and weighted sum
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt(); // Read each element into the array A
            sum += A[i]; // Accumulate the sum of elements
            wa += (i + 1); // Accumulate the weighted sum
        }
        
        // Check if the total sum is divisible by the weighted sum
        if (sum % wa != 0) {
            ans = 0; // If not divisible, set answer to 0 (NO)
        } else {
            // Calculate the average value (shou)
            shou = (int)(sum / wa);
            
            // Calculate the adjusted differences and store them in array sa
            for (int i = 0; i < N; i++) {
                sa[i] = A[(i + 1) % N] - A[i] - shou; // Adjusted difference for circular array
            }
            
            // Check the conditions for the adjusted differences
            for (int i = 0; i < N - 1; i++) {    
                // If the adjusted difference is non-positive and divisible by N
                if (sa[i] <= 0 && sa[i] % N == 0) {
                    ans = 1; // Set answer to 1 (YES)
                } else {
                    ans = 0; // If any condition fails, set answer to 0 (NO)
                    break;   // Exit the loop early
                }
            }
        }  
        
        // Output the final result based on the answer
        if (ans == 1) {
            System.out.println("YES"); // Print YES if conditions are met
        } else {
            System.out.println("NO");  // Print NO if conditions are not met
        }
        
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
