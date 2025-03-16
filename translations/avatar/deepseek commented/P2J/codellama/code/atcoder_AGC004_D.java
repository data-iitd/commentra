
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[][] links = new int[n][];
        for (int i = 0; i < n; i++) {
            links[i] = new int[a[i]];
            for (int j = 0; j < a[i]; j++) {
                links[i][j] = sc.nextInt();
            }
        }
        int[][] dp = new int[n][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;
            }
        }
        int ans = dfs(links, n, k, 0, 0, dp);
        System.out.println(ans);
    }

    public static int dfs(int[][] links, int n, int k, int v, int p, int[][] dp) {
        if (dp[v][k] != -1) {
            return dp[v][k];
        }
        int height_from_leaf = 0;
        int cut_count = 0;
        for (int u : links[v]) {
            if (u == 0) {
                continue;
            }
            int hgt = dfs(links, n, k, u, v, dp);
            height_from_leaf = Math.max(height_from_leaf, hgt);
            cut_count += 1;
        }
        height_from_leaf += 1;
        if (p != 0 && height_from_leaf == k) {
            height_from_leaf = 0;
            cut_count += 1;
        }
        dp[v][k] = cut_count;
        return cut_count;
    }
}

