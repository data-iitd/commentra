
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class s546282715{
    private static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static final PrintWriter writer = new PrintWriter(System.out);
    private static final int MODULO = 1000000007;

    public static void main(String[] args) throws IOException {
        int n = nextInt();
        int m = nextInt();
        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 1 <= n && a[j]!= i + 1) {
                    dp[i + 1] += dp[i];
                    dp[i + 1] %= MODULO;
                }
                if (i + 2 <= n && a[j]!= i + 2) {
                    dp[i + 2] += dp[i];
                    dp[i + 2] %= MODULO;
                }
            }
        }
        writer.println(dp[n]);
        writer.close();
    }

    private static StringTokenizer stringTokenizer;

    private static String next() throws IOException {
        while (stringTokenizer == null ||!stringTokenizer.hasMoreTokens()) {
            stringTokenizer = new StringTokenizer(reader.readLine());
        }
        return stringTokenizer.nextToken();
    }

    private static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}

