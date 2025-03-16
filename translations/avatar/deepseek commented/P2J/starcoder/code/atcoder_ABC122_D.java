import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mod = 1000000007;
        // Initialize the memo dictionary for storing computed results
        Map<Integer, Map<String, Integer>> memo = new HashMap<>();
        for (int i = 0; i <= n; i++) {
            memo.put(i, new HashMap<>());
        }
        // Print the result of the dfs function starting with last3 as "TTT"
        System.out.println(dfs(0, "TTT", n, memo));
    }

    public static int dfs(int cur, String last3, int n, Map<Integer, Map<String, Integer>> memo) {
        // Check if the result for the current state (cur, last3) is already computed
        if (memo.get(cur).containsKey(last3)) {
            return memo.get(cur).get(last3);
        }
        if (cur == n) {
            // Base case: if current length equals n, return 1 (valid sequence)
            return 1;
        }
        int ret = 0;
        for (char c : "ACGT".toCharArray()) {
            // Check if adding the character c to last3 forms a valid sequence
            if (ok(last3 + c)) {
                // Recursively call dfs with the next character
                ret = (ret + dfs(cur + 1, last3.substring(1) + c, n, memo)) % mod;
            }
        }
        memo.get(cur).put(last3, ret);
        return ret;
    }

    // Check if the last4 string contains "AGC" more than once
    public static boolean ok(String last4) {
        for (int i = 0; i < 4; i++) {
            char[] t = last4.toCharArray();
            if (i >= 1) {
                // Swap the current and previous character
                char tmp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = tmp;
            }
            if (new String(t).contains("AGC")) {
                // If "AGC" is found, return False
                return false;
            }
        }
        return true;
    }
}

