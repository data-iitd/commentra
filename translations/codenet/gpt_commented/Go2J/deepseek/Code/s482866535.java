import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(InputStream stream) {
            try {
                br = new BufferedReader(new InputStreamReader(stream));
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = scanner.nextInt();
        int[] mm = new int[n + 1];
        int[][] dp = new int[n + 1][n + 1];

        for (int i = 0; i < n; i++) {
            mm[i] = scanner.nextInt();
            mm[i + 1] = scanner.nextInt();
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i; k <= j - 1; k++) {
                    int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                    if (dp[i][j] > d) {
                        dp[i][j] = d;
                    }
                }
            }
        }

        out.println(dp[1][n]);
        out.flush();
    }
}
