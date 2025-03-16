import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    static class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner();
        PrintWriter writer = new PrintWriter(System.out);

        int n = scanner.nextInt();
        int m = scanner.nextInt();

        HashSet<Integer> aa = new HashSet<>();
        for (int i = 0; i < m; i++) {
            aa.add(scanner.nextInt());
        }

        int[] dp = new int[n + 1];
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
                if (aa.contains(i + ii)) {
                    continue;
                }
                dp[i + ii] += dp[i];
                dp[i + ii] %= 1000000007;
            }
        }

        writer.println(dp[n]);
        writer.flush();
    }
}
