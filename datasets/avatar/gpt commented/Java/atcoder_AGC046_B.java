import java.io.PrintWriter; 
import java.util.HashMap; 
import java.util.Map; 
import java.util.Scanner; 

public class Main {
    // Define a constant for the modulo operation
    long MOD = 998244353L; 
    // Create a 2D array for dynamic programming
    long[][] dp = new long[3001][3001]; 

    // Method to solve the problem
    void solve(Scanner sc, PrintWriter pw) {
        // Read input values A, B, C, D from the scanner
        int A = sc.nextInt(); 
        int B = sc.nextInt(); 
        int C = sc.nextInt(); 
        int D = sc.nextInt(); 
        
        // Initialize the starting point in the dp array
        dp[A][B] = 1; 
        
        // Iterate over the range from A to C and B to D
        for (int c = A; c <= C; c++) { 
            for (int d = B; d <= D; d++) { 
                // Skip the initial point
                if (c == A && d == B) { 
                    continue; 
                } 
                
                // Variable to store the current answer
                long ans = 0; 
                
                // If moving down (increasing c)
                if (c > A) { 
                    long part = dp[c - 1][d]; 
                    ans = (part * d); // Calculate contribution from the previous row
                } 
                
                // If moving right (increasing d)
                if (d > B) { 
                    long part = dp[c][d - 1]; 
                    ans = (ans + (part * c)); // Calculate contribution from the previous column
                } 
                
                // If moving diagonally (increasing both c and d)
                if (c > A && d > B) { 
                    ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1))); // Adjust for double counting
                } 
                
                // Store the result in the dp array with modulo adjustment
                dp[c][d] = ((ans % MOD) + MOD) % MOD; 
            } 
        } 
        
        // Output the final result for dp[C][D]
        pw.println(dp[C][D]); 
    } 

    // Main method to execute the program
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); // Initialize scanner for input
        PrintWriter pw = new PrintWriter(System.out); // Initialize PrintWriter for output
        new Main().solve(sc, pw); // Create an instance of Main and call solve method
        pw.flush(); // Flush the output
        pw.close(); // Close the PrintWriter
        sc.close(); // Close the scanner
    } 
}
