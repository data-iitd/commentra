import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    static int n;
    static final int MOD = 1000000007;
    static Map<String, Integer>[] memo;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        memo = new HashMap[n + 1];
        for (int i = 0; i <= n; i++) {
            memo[i] = new HashMap<>();
        }
        System.out.println(dfs(0, "TTT"));
    }

    static boolean ok(String last4) {
        for (int i = 0; i < 4; i++) {
            char[] t = last4.toCharArray();
            if (i >= 1) {
                // Swap the current character with the previous one
                char temp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = temp;
            }
            // Check if 'AGC' is found in the modified string
            if (new String(t).contains("AGC")) {
                return false;
            }
        }
        return true;
    }

    static int dfs(int cur, String last3) {
        // Check if the result for the current state is already computed
        if (memo[cur].containsKey(last3)) {
            return memo[cur].get(last3);
        }
        // If we have reached the end of the sequence, return 1 (valid sequence found)
        if (cur == n) {
            return 1;
        }
        int ret = 0;
        // Iterate through each possible character 'A', 'C', 'G', 'T'
        for (char c : "ACGT".toCharArray()) {
            // Check if adding the current character keeps the sequence valid
            if (ok(last3 + c)) {
                // Recursively call dfs for the next position with the updated last3
                ret = (ret + dfs(cur + 1, last3.substring(1) + c)) % MOD;
            }
        }
        // Store the computed result in the memoization table
        memo[cur].put(last3, ret);
        return ret;
    }
}

// <END-OF-CODE>
