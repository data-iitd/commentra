import java.util.Scanner;

public class BitwisePairs {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements in the array
        int N = scanner.nextInt();
        
        // Read the input values and create an array of integers
        long[] A = new long[N];
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextLong();
        }
        
        // Initialize the result variable to store the final answer
        long result = 0;
        
        // Iterate over each bit position from 0 to 59 (assuming 60 bits for integers)
        for (int b = 0; b < 60; b++) {
            // Count how many numbers have the b-th bit set (1)
            long bs = 0;
            for (long num : A) {
                if ((num & (1L << b)) != 0) {
                    bs++;
                }
            }
            
            // Calculate the contribution of the b-th bit to the result
            // bs * (N - bs) gives the number of pairs with different b-th bits
            // (1 << b) gives the value of the b-th bit
            result = (result + bs * (N - bs) * (1L << b)) % 1000000007;
        }
        
        // Print the final result
        System.out.println(result);
        
        scanner.close();
    }
}
// <END-OF-CODE>
