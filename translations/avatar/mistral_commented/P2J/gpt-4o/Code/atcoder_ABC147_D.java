import java.util.Scanner;

public class BitContribution {
    public static void main(String[] args) {
        // Create a Scanner object for reading input
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements 'N' from the user
        int N = scanner.nextInt();
        
        // Initialize an array to store the integers
        long[] A = new long[N];
        
        // Read 'N' integers from the user and store them in the array 'A'
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }
        
        // Initialize the result variable to zero
        long result = 0;
        final long MOD = 1000000007;
        
        // Iterate through each bit position 'b' from 0 to 59
        for (int b = 0; b < 60; b++) {
            // Calculate the sum of bits in position 'b' in all numbers of 'A'
            long bs = 0;
            for (long num : A) {
                bs += (num >> b) & 1; // Count the number of 1s in the b-th bit position
            }
            
            // Calculate the contribution of this bit position 'b' to the result
            long contribution = bs * (N - bs) % MOD * (1L << b) % MOD;
            
            // Add this contribution to the result
            result = (result + contribution) % MOD;
        }
        
        // Print the final result
        System.out.println(result);
        
        // Close the scanner
        scanner.close();
    }
}
// <END-OF-CODE>
