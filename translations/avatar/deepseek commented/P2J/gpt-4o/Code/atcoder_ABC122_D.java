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
        scanner.close();
    }

    static boolean ok(String last3) {
        // Check if the last3 string contains "AGC" more than once
        for (int i = 0; i < 4; i++) {
            char[] t = last3.toCharArray();
            if (i >= 1) {
                // Swap the current and previous character
                char temp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = temp;
            }
            if (new String(t).contains("AGC")) {
                // If "AGC" is found, return false
                return false;
            }
        }
        return true;
    }

    static int dfs(int cur, String last3) {
        // Check if the result for the current state (cur, last3) is already computed
        if (memo[cur].containsKey(last3)) {
            return memo[cur].get(last3);
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
                ret = (ret + dfs(cur + 1, last3.substring(1) + c)) % MOD;
            }
        }
        memo[cur].put(last3, ret);
        return ret;
    }
}
// <END-OF-CODE>
