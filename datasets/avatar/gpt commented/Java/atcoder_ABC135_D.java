import java.io.PrintWriter; 
import java.util.ArrayList; 
import java.util.Arrays; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create an instance of Main and run the main logic
        new Main().run(); 
    } 
    
    // Define a constant for the modulo operation
    final long MOD = (long) 1e9 + 7; 
    
    void run() { 
        // Initialize a scanner to read input
        Scanner sc = new Scanner(System.in); 
        
        // Read the input string and convert it to a character array
        char[] cs = sc.next().toCharArray(); 
        
        // Initialize a 2D array for dynamic programming to store results
        long[][] dp = new long[cs.length][13]; 
        
        // Variable to keep track of the base value for calculations
        int base = 1; 
        
        // Iterate through the characters of the input from the last to the first
        for (int i = 0; i < cs.length; ++i) { 
            // Check if the current character is a '?', which can be any digit
            if (cs[cs.length - 1 - i] == '?') { 
                // Loop through all possible previous remainders
                for (int pre = 0; pre < 13; ++pre) { 
                    // Loop through all possible next digits (0-9)
                    for (int next = 0; next < 10; ++next) { 
                        // Update the dp array for the current position and remainder
                        dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0)); 
                        // Ensure the result stays within the MOD limit
                        dp[i][(base * next + pre) % 13] %= MOD; 
                    } 
                } 
            } else { 
                // If the character is a digit, convert it to an integer
                int next = cs[cs.length - 1 - i] - '0'; 
                // Loop through all possible previous remainders
                for (int pre = 0; pre < 13; ++pre) { 
                    // Update the dp array for the current position and remainder
                    dp[i][(base * next + pre) % 13] += (i > 0 ? dp[i - 1][pre] : (pre == 0 ? 1 : 0)); 
                    // Ensure the result stays within the MOD limit
                    dp[i][(base * next + pre) % 13] %= MOD; 
                } 
            } 
            // Update the base value for the next iteration (moving to the next digit)
            base = base * 10 % 13; 
        } 
        
        // Output the result, which is the number of ways to form a number divisible by 13
        System.out.println(dp[dp.length - 1][5]); 
    } 
    
    // Utility function to print debug information
    void tr(Object... objects) { 
        System.out.println(Arrays.deepToString(objects)); 
    } 
}
