import java.util.*;

public class Main {
    static boolean ok(String last4) {
        for (int i = 0; i < 4; i++) {
            char[] t = last4.toCharArray();
            if (i >= 1) {
                char temp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = temp;
            }
            if (new String(t).contains("AGC")) {
                return false;
            }
        }
        return true;
    }

    static long dfs(int cur, String last3, long[][] memo) {
        if (memo[cur][0] != -1) {
            return memo[cur][0];
        }
        if (cur == n) {
            return 1;
        }
        long ret = 0;
        for (char c : "ACGT".toCharArray()) {
            if (ok(last3 + c)) {
                ret = (ret + dfs(cur + 1, last3.substring(1) + c, memo)) % mod;
            }
        }
        memo[cur][0] = ret;
        return ret;
    }

    static int n;
    static long mod = 1000000007;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        long[][] memo = new long[n + 1][1];
        for (long[] row : memo) {
            Arrays.fill(row, -1);
        }
        System.out.println(dfs(0, "TTT", memo));
    }
}
