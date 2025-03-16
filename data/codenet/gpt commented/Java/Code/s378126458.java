import java.util.*;

public class Main {

    /*
     * 122C
     * 
     * This problem requires a prefix sum array to efficiently count occurrences
     * of the substring "AC" in the given string.
     * Let's define a boolean array k[i] where:
     * k[i] = true when s[i] == 'A' and s[i+1] == 'C'.
     * We will create a prefix sum array based on this boolean array and use it for querying.
     * 
     * COMMON MISTAKE: MAKE SURE YOU DO R-1 BECAUSE S[R+1] GOES OVER THE RANGE.
     * COMMON MISTAKE: THIS IS A ONE-INDEXED STRING.
     * 
     * Time Complexity: O(N), Memory Complexity: O(N)
     */
    
    public static void main(String[] args) {
        // Initialize scanner to read input
        Scanner sc = new Scanner(System.in);
        
        // Read the number of characters in the string (N) and the number of queries (Q)
        int N = sc.nextInt(), Q = sc.nextInt();
        
        // Read the input string
        String s = sc.next();
        
        // Initialize the prefix sum array with an extra space for easier calculations
        int pre[] = new int[N + 1];
        
        // Build the prefix sum array based on the occurrences of "AC"
        for (int i = 1; i < N; i++) {
            // Check if the current character is 'A' and the next character is 'C'
            if (s.charAt(i - 1) == 'A' && s.charAt(i) == 'C') {
                pre[i] = 1; // Mark this position in the prefix sum array
            }
        }
        
        // Construct the prefix sum array by accumulating counts
        for (int i = 1; i < N; i++) {
            pre[i] += pre[i - 1]; // Add the previous value to the current position
        }
        
        // Process each query
        while (Q-- > 0) {
            // Read the left and right indices for the query
            int l = sc.nextInt(), r = sc.nextInt();
            r--; // Adjust r to be zero-indexed
            
            // Output the number of occurrences of "AC" in the range [l, r]
            System.out.println(pre[r] - pre[l - 1]);
        }
    }
}
