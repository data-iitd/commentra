import java.util.*; 
import java.io.*; 

public class Main {
    // Number of characters to generate
    int N; 
    // Modulus value for large number calculations
    long MOD = 1000000007L; 
    // Possible tokens (characters) to use
    String[] TOKENS = { "A", "C", "G", "T" }; 
    // Memoization array to store computed results
    Map<String, Long>[] memo; 

    // Constructor to initialize the class
    Main() { 
        // Create a scanner to read input
        Scanner in = new Scanner(System.in); 
        // Read the number of characters to generate
        N = in.nextInt(); 
        // Close the scanner
        in.close(); 
        // Initialize the memoization array
        this.memo = new Map[N + 1]; 
        for (int i = 0; i < this.memo.length; ++i) { 
            // Initialize each entry in the memoization array with a new HashMap
            this.memo[i] = new HashMap<String, Long>(); 
        } 
    } 

    // Method to calculate the total valid sequences
    long calc() { 
        // Start the depth-first search with the initial state
        return dfs(0, "TTT"); 
    } 

    // Method to check if the last 4 characters are valid
    boolean isOK(String last4) { 
        // Check if the last 4 characters contain "AGC"
        if (last4.contains("AGC")) { 
            return false; 
        } 
        // Check all permutations of the last 4 characters
        for (int i = 0; i < 3; ++i) { 
            char[] vals = last4.toCharArray(); 
            // Swap characters to create a new permutation
            vals[i] = last4.charAt(i + 1); 
            vals[i + 1] = last4.charAt(i); 
            String s = new String(vals); 
            // Check if the new permutation contains "AGC"
            if (s.contains("AGC")) { 
                return false; 
            } 
        } 
        // If no invalid sequences found, return true
        return true; 
    } 

    // Depth-first search method to explore all possible sequences
    long dfs(int current, String last3) { 
        // Check if the result is already computed and stored in memo
        if (this.memo[current].containsKey(last3)) { 
            return (Long) (this.memo[current].get(last3)); 
        } 
        // Base case: if the current length equals N, return 1 (valid sequence)
        if (current == N) { 
            return 1; 
        } 
        // Variable to accumulate the result
        long result = 0; 
        // Iterate through each possible token
        for (String c : TOKENS) { 
            // Check if adding the token to the last 3 characters is valid
            if (isOK(last3 + c)) { 
                // Recursively call dfs for the next character
                result = (result + dfs(current + 1, last3.substring(1, last3.length()) + c)) % MOD; 
            } 
        } 
        // Store the computed result in memoization array
        memo[current].put(last3, result); 
        return result; 
    } 

    // Main method to execute the program
    public static void main(String[] args) { 
        // Create an instance of Main class
        Main ins = new Main(); 
        // Print the result of the calculation
        System.out.println(ins.calc()); 
    } 
}
