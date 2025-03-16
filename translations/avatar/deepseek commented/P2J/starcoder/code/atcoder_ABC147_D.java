import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the size of the array
        int N = sc.nextInt();
        
        // Create a numpy array from the input values
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }
        
        // Initialize the result variable to 0
        long result = 0;
        
        // Loop over each bit position from 0 to 59
        for (int b = 0; b < 60; b++) {
            // Count the number of set bits at the current bit position
            int bs = 0;
            for (int i = 0; i < N; i++) {
                bs += (A[i] >> b) & 1;
            }
            
            // Calculate the contribution of the current bit position to the result
            result = (result + bs * (N - bs) * (1 << b)) % 1000000007;
        }
        
        // Print the final result
        System.out.println(result);
    }
}
