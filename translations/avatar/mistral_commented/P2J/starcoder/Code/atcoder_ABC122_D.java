
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read the input: the number of nucleotides (n)
        int n = sc.nextInt();
        
        // Initialize the memoization table with empty dictionaries
        Map<Integer, Map<String, Integer>> memo = new HashMap<>();
        for (int i = 0; i <= n; i++) {
            memo.put(i, new HashMap<>());
        }
        
        // Initialize the modulus value
        int mod = (int) Math.pow(10, 9) + 7;
        
        // Perform DFS and print the result
        System.out.println(dfs(0, "TTT", memo, mod));
    }
    
    // This function performs Depth-First Search (DFS) to find the number of valid sequences
    // Input: cur (the current index), last3 (the last 3 nucleotides), memo (the memoization table), mod (the modulus value)
    // Output: An integer value representing the number of valid sequences
    public static int dfs(int cur, String last3, Map<Integer, Map<String, Integer>> memo, int mod) {
        // Memoization table to store the results of subproblems
        if (memo.get(cur).containsKey(last3)) {
            // If the subproblem has already been solved, return the stored result
            return memo.get(cur).get(last3);
        }
        
        // Base case: If we have reached the end of the sequence, return 1
        if (cur == n) {
            return 1;
        }
        
        // Initialize the result to 0
        int ret = 0;
        
        // Iterate through all possible nucleotides (A, C, G, T)
        for (char c : "ACGT".toCharArray()) {
            // Check if the next nucleotide can be added to the last 3 nucleotides
            if (ok(last3 + c)) {
                // If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
                ret = (ret + dfs(cur + 1, last3.substring(1) + c, memo, mod)) % mod;
            }
        }
        
        // Store the result in the memoization table and return it
        memo.get(cur).put(last3, ret);
        return ret;
    }
    
    // This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
    // It returns False if it does, and True otherwise.
    // Input: last4 (a list of 4 nucleotides)
    // Output: A boolean value
    public static boolean ok(String last4) {
        // Iterate through the last 4 nucleotides in reverse order
        for (int i = 0; i < 4; i++) {
            // Swap the positions of the current and previous nucleotides
            char[] t = last4.toCharArray();
            if (i >= 1) {
                char tmp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = tmp;
            }
            
            // Check if the swapped sequence contains "AGC"
            if (new String(t).contains("AGC")) {
                // If yes, return False and exit the function
                return false;
            }
        }
        
        // If no "AGC" sequence is found, return True
        return true;
    }
}

