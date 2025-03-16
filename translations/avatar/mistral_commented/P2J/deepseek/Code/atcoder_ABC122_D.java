import java.util.*;

public class Main {
    // This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
    // It returns false if it does, and true otherwise.
    // Input: last4 (a list of 4 nucleotides)
    // Output: A boolean value
    public static boolean ok(List<Character> last4) {
        // Iterate through the last 4 nucleotides in reverse order
        for (int i = 0; i < 4; i++) {
            // Swap the positions of the current and previous nucleotides
            List<Character> t = new ArrayList<>(last4);
            if (i >= 1) {
                Collections.swap(t, i, i - 1);
            }
            
            // Check if the swapped sequence contains "AGC"
            if (String.valueOf(t).contains("AGC")) {
                // If yes, return false and exit the function
                return false;
            }
        }
        
        // If no "AGC" sequence is found, return true
        return true;
    }

    // This function performs Depth-First Search (DFS) to find the number of valid sequences
    // Input: cur (the current index), last3 (the last 3 nucleotides)
    // Output: An integer value representing the number of valid sequences
    public static int dfs(int cur, String last3) {
        // Memoization table to store the results of subproblems
        if (memo.containsKey(cur) && memo.get(cur).containsKey(last3)) {
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
            if (ok(Arrays.asList(last3.charAt(1), last3.charAt(2), last3.charAt(3), c))) {
                // If yes, recursively call dfs with the updated last 3 nucleotides and the new current index
                ret = (ret + dfs(cur + 1, last3.substring(1) + c)) % mod;
            }
        }
        
        // Store the result in the memoization table and return it
        if (!memo.containsKey(cur)) {
            memo.put(cur, new HashMap<>());
        }
        memo.get(cur).put(last3, ret);
        return ret;
    }

    // Read the input: the number of nucleotides (n)
    public static int n;

    // Initialize the memoization table with empty dictionaries
    public static Map<Integer, Map<String, Integer>> memo = new HashMap<>();

    // Initialize the modulus value
    public static int mod = (int) Math.pow(10, 9) + 7;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        
        // Perform DFS and print the result
        System.out.println(dfs(0, "TTT"));
    }
}
