import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements 'N' from the user
        int N = scanner.nextInt();
        
        // Read 'N' integers from the user and store them in an array 'A'
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }
        
        // Initialize the result variable to zero
        long result = 0;
        
        // Iterate through each bit position 'b' from 0 to 59
        for (int b = 0; b < 60; b++) {
            
            // Calculate the sum of bits in position 'b' in all numbers of 'A'
            long bs = 0;
            for (int i = 0; i < N; i++) {
                bs += (A[i] >> b) & 1;
            }
            
            // Calculate the contribution of this bit position 'b' to the result
            long contribution = bs * (N - bs) * (1L << b);
            
            // Add this contribution to the result
            result = (result + contribution) % 1000000007;
        }
        
        // Print the final result
        System.out.println(result);
    }
}

