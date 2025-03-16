import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class NucleotideSequences {
    // Memoization table to store the results of subproblems
    private static Map<String, Integer>[] memo;
    private static int n;
    private static final int MOD = 1000000007;

    // This function checks if the last 4 nucleotides (last4) contain the sequence "AGC" or not.
    // It returns False if it does, and True otherwise.
    public static boolean ok(String last4) {
        // Iterate through the last 4 nucleotides in reverse order
        for (int i = 0; i < 4; i++) {
            // Create a character array from the string
            char[] t = last4.toCharArray();
            // Swap the positions of the current and previous nucleotides
            if (i >= 1) {
                char temp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = temp;
            }
            // Check if the swapped sequence contains "AGC"
            if (new String(t).contains("AGC")) {
                // If yes, return False
                return false;
            }
        }
        // If no "AGC" sequence is found, return True
        return true;
    }

    // This function performs Depth-First Search (DFS) to find the number of valid sequences
    public static int dfs(int cur, String last3) {
        // Check if the subproblem has already been solved
        if (memo[cur].containsKey(last3)) {
            return memo[cur].get(last3);
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
                ret = (ret + dfs(cur + 1, last3.substring(1) + c)) % MOD;
            }
        }

        // Store the result in the memoization table and return it
        memo[cur].put(last3, ret);
        return ret;
    }

    public static void main(String[] args) {
        // Read the input: the number of nucleotides (n)
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();

        // Initialize the memoization table with empty HashMaps
        memo = new HashMap[n + 1];
        for (int i = 0; i <= n; i++) {
            memo[i] = new HashMap<>();
        }

        // Perform DFS and print the result
        System.out.println(dfs(0, "TTT"));
        scanner.close();
    }
}

// <END-OF-CODE>
