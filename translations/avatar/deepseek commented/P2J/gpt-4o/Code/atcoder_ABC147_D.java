import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the size of the array
        int N = scanner.nextInt();
        
        // Create an array to hold the input values
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }
        
        // Initialize the result variable to 0
        long result = 0;
        final long MOD = 1000000007;

        // Loop over each bit position from 0 to 59
        for (int b = 0; b < 60; b++) {
            // Count the number of set bits at the current bit position
            long bs = 0;
            for (long value : A) {
                bs += (value >> b) & 1;
            }
            
            // Calculate the contribution of the current bit position to the result
            result = (result + bs * (N - bs) * (1L << b)) % MOD;
        }

        // Print the final result
        System.out.println(result);
        
        scanner.close();
    }
}

// <END-OF-CODE>
