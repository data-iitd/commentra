import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.IOException;

public class Main {
    static class Scanner {
        private BufferedReader br;
        private StreamTokenizer st;

        public Scanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
            st = new StreamTokenizer(br);
        }

        public String next() throws IOException {
            st.nextToken();
            return st.sval;
        }

        public int nextInt() throws IOException {
            st.nextToken();
            return (int) st.nval;
        }
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner();
        PrintWriter writer = new PrintWriter(System.out);

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

        writer.println(dp[1][n]);
        writer.flush();
    }
}
