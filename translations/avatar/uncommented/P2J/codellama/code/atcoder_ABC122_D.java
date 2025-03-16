public class Main {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int mod = 1000000007;
        int[][] memo = new int[n + 1][4];
        for (int i = 0; i < memo.length; i++) {
            for (int j = 0; j < memo[i].length; j++) {
                memo[i][j] = -1;
            }
        }
        System.out.println(dfs(0, "TTT", memo));
    }

    public static int dfs(int cur, String last3, int[][] memo) {
        if (memo[cur][last3.charAt(0) - 'A'] != -1) {
            return memo[cur][last3.charAt(0) - 'A'];
        }
        if (cur == n) {
            return 1;
        }
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            if (ok(last3.charAt(1) - 'A', last3.charAt(2) - 'A', i)) {
                ret = (ret + dfs(cur + 1, last3.substring(1) + (char)('A' + i), memo)) % mod;
            }
        }
        memo[cur][last3.charAt(0) - 'A'] = ret;
        return ret;
    }

    public static boolean ok(int a, int b, int c) {
        if (a == b || b == c || a == c) {
            return false;
        }
        if (a == 0 && b == 1 && c == 2) {
            return false;
        }
        if (a == 0 && b == 2 && c == 1) {
            return false;
        }
        if (a == 1 && b == 0 && c == 2) {
            return false;
        }
        if (a == 1 && b == 2 && c == 0) {
            return false;
        }
        if (a == 2 && b == 0 && c == 1) {
            return false;
        }
        if (a == 2 && b == 1 && c == 0) {
            return false;
        }
        return true;
    }
}

