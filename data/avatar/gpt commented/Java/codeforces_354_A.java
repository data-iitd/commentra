import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner in = new Scanner(System.in);
        
        // Read the number of elements (N) and the values for L, R, QL, QR
        int N = in.nextInt(); // Number of elements
        int L = in.nextInt(); // Cost for left elements
        int R = in.nextInt(); // Cost for right elements
        int QL = in.nextInt(); // Additional cost for left excess
        int QR = in.nextInt(); // Additional cost for right excess
        
        // Initialize an array to hold the weights and a prefix sum array
        int[] W = new int[N]; // Array to store weights
        int[] sum = new int[N + 1]; // Prefix sum array
        
        // Read weights and compute the prefix sum
        for (int n = 0; n < N; n++) {
            W[n] = in.nextInt(); // Read weight for each element
            sum[n + 1] = sum[n] + W[n]; // Update prefix sum
        }
        
        // Initialize a variable to track the minimum cost
        long min = Long.MAX_VALUE; // Start with the maximum possible value
        
        // Iterate over possible counts of elements assigned to the left side
        for (int firstR = 0; firstR <= N; firstR++) {
            int lCount = firstR; // Count of elements on the left
            int rCount = N - lCount; // Count of elements on the right
            
            // Calculate the candidate cost based on current left and right counts
            long cand = sum[lCount] * L + (sum[N] - sum[lCount]) * R;
            
            // Calculate excess counts for left and right
            int llCount = Math.max(0, lCount - rCount - 1); // Excess left count
            int rrCount = Math.max(0, rCount - lCount - 1); // Excess right count
            
            // Add additional costs for excess elements
            cand += llCount * QL; // Add cost for excess left elements
            cand += rrCount * QR; // Add cost for excess right elements
            
            // Update the minimum cost found
            min = Math.min(cand, min); // Keep track of the minimum cost
        }
        
        // Output the minimum cost
        System.out.println(min); // Print the result
    }
}
