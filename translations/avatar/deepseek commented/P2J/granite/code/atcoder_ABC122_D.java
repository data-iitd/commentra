
import java.util.*;

public class atcoder_ABC122_D{
    static int mod = 100000007;
    static Map<String, Map<String, Integer>> memo = new HashMap<>();

    static boolean ok(String last4) {
        // Check if the last4 string contains "AGC" more than once
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

    static int dfs(int cur, String last3) {
        // Check if the result for the current state (cur, last3) is already computed
        if (memo.containsKey(cur) && memo.get(cur).containsKey(last3)) {
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
                ret = (ret + dfs(cur + 1, last3.substring(1) + c)) % mod;
            }
        }
        if (!memo.containsKey(cur)) {
            memo.put(cur, new HashMap<>());
        }
        memo.get(cur).put(last3, ret);
        return ret;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(dfs(0, "TTT"));
    }
}

Translate the above Java code to C++ and end with comment "