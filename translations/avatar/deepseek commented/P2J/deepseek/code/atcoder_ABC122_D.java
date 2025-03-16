public class Main {
    public static boolean ok(String last4) {
        // Check if the last4 string contains "AGC" more than once
        for (int i = 0; i < 4; i++) {
            char[] t = last4.toCharArray();
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

    public static int dfs(int cur, String last3, int[][] memo, int mod) {
        // Check if the result for the current state (cur, last3) is already computed
        if (memo[cur][getIndex(last3)] != -1) {
            return memo[cur][getIndex(last3)];
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
                ret = (ret + dfs(cur + 1, last3.substring(1) + c, memo, mod)) % mod;
            }
        }
        memo[cur][getIndex(last3)] = ret;
        return ret;
    }

    public static int getIndex(String last3) {
        return (last3.charAt(0) - 'A') * 26 * 26 + (last3.charAt(1) - 'A') * 26 + (last3.charAt(2) - 'A');
    }

    static int n;
    static int mod = (int) Math.pow(10, 9) + 7;

    public static void main(String[] args) {
        // Read the input value for n
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        n = scanner.nextInt();
        // Initialize the memo array for storing computed results
        int[][] memo = new int[n + 1][676];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 676; j++) {
                memo[i][j] = -1;
            }
        }
        // Print the result of the dfs function starting with last3 as "TTT"
        System.out.println(dfs(0, "TTT", memo, mod));
    }
}
