public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int mod = 1000000007;
        int[][] memo = new int[n + 1][4];
        for (int i = 0; i < memo.length; i++) {
            Arrays.fill(memo[i], -1);
        }
        System.out.println(dfs(0, "TTT", memo));
    }

    public static int dfs(int cur, String last3, int[][] memo) {
        if (cur == n) {
            return 1;
        }
        if (memo[cur][last3.charAt(0) - 'A'] != -1) {
            return memo[cur][last3.charAt(0) - 'A'];
        }
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            if (ok(last3.charAt(i) + last3.charAt(i + 1) + last3.charAt(i + 2))) {
                ret = (ret + dfs(cur + 1, last3.substring(1) + (char)('A' + i), memo)) % mod;
            }
        }
        memo[cur][last3.charAt(0) - 'A'] = ret;
        return ret;
    }

    public static boolean ok(String last4) {
        for (int i = 0; i < 4; i++) {
            if (last4.charAt(i) == 'A' && last4.charAt(i + 1) == 'G' && last4.charAt(i + 2) == 'C') {
                return false;
            }
        }
        return true;
    }
}
