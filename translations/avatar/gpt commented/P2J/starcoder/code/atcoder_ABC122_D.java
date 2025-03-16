import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mod = 1000000007;
        int[][] memo = new int[n + 1][4];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(memo[i], -1);
        }
        System.out.println(dfs(0, "TTT", memo));
    }

    public static int dfs(int cur, String last3, int[][] memo) {
        if (memo[cur][0]!= -1) {
            return memo[cur][0];
        }
        if (cur == n) {
            return 1;
        }
        int ret = 0;
        for (char c : "ACGT".toCharArray()) {
            if (ok(last3 + c)) {
                ret = (ret + dfs(cur + 1, last3.substring(1) + c, memo)) % mod;
            }
        }
        memo[cur][0] = ret;
        return ret;
    }

    public static boolean ok(String last4) {
        for (int i = 0; i < 4; i++) {
            char[] t = last4.toCharArray();
            if (i >= 1) {
                char tmp = t[i];
                t[i] = t[i - 1];
                t[i - 1] = tmp;
            }
            if (new String(t).contains("AGC")) {
                return false;
            }
        }
        return true;
    }
}

