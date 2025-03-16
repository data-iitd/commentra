
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        in.close();

        int mod = 1000000007;
        int[][] memo = new int[n+1][4];

        System.out.println(dfs(0, "TTT", memo, mod));
    }

    public static int dfs(int cur, String last3, int[][] memo, int mod) {
        if (cur == n) {
            return 1;
        }

        if (memo[cur][last3.charAt(0) - 'A'] != 0) {
            return memo[cur][last3.charAt(0) - 'A'];
        }

        int ret = 0;
        for (int i = 0; i < 4; i++) {
            if (ok(last3.charAt(0), last3.charAt(1), last3.charAt(2), (char)('A' + i))) {
                ret = (ret + dfs(cur + 1, last3.substring(1) + (char)('A' + i), memo, mod)) % mod;
            }
        }

        memo[cur][last3.charAt(0) - 'A'] = ret;
        return ret;
    }

    public static boolean ok(char a, char b, char c, char d) {
        if (a == 'A' && b == 'G' && c == 'C') {
            return false;
        }
        if (b == 'A' && c == 'G' && d == 'C') {
            return false;
        }
        if (c == 'A' && d == 'G' && a == 'C') {
            return false;
        }
        return true;
    }
}

