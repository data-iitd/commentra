
import java.io.PrintWriter ; 
import java.util.HashMap ; 
import java.util.Map ; 
import java.util.Scanner ; 

public class Main { 
    long MOD = 998244353L ; 
    long [][] dp = new long[3001][3001] ; 

    // This method solves the problem using dynamic programming
    void solve(Scanner sc, PrintWriter pw) { 
        // Read the input values for A, B, C, and D
        int A = sc.nextInt(); 
        int B = sc.nextInt(); 
        int C = sc.nextInt(); 
        int D = sc.nextInt(); 

        // Initialize the dp array for the starting point (A, B)
        dp[A][B] = 1; 

        // Iterate over the range from A to C and from B to D
        for (int c = A; c <= C; c++) { 
            for (int d = B; d <= D; d++) { 
                // Skip the starting point (A, B)
                if (c == A && d == B) { 
                    continue; 
                } 

                // Calculate the answer based on previous states
                long ans = 0; 
                if (c > A) { 
                    long part = dp[c - 1][d]; 
                    ans = (part * d) % MOD; 
                } 
                if (d > B) { 
                    long part = dp[c][d - 1]; 
                    ans = (ans + (part * c) % MOD) % MOD; 
                } 
                if (c > A && d > B) { 
                    ans = (ans - (dp[c - 1][d - 1] * (c - 1) * (d - 1) % MOD) + MOD) % MOD; 
                } 

                // Store the result in dp array
                dp[c][d] = ans; 
            } 
        } 

        // Output the result for the final state (C, D)
        pw.println(dp[C][D]); 
    } 

    // Main method to set up input/output and call the solve method
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in); 
        PrintWriter pw = new PrintWriter(System.out); 
        new Main().solve(sc, pw); 
        pw.flush(); 
        pw.close(); 
        sc.close(); 
    } 
}
