
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class s541050824{
    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    private static BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
    private static StringTokenizer tokenizer = new StringTokenizer("");

    private static String next() throws Exception {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    private static int nextInt() throws Exception {
        return Integer.parseInt(next());
    }

    private static long nextLong() throws Exception {
        return Long.parseLong(next());
    }

    private static void solve() throws Exception {
        int n = nextInt();
        long[] t = new long[n];
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            t[i] = nextLong();
            a[i] = nextLong();
        }
        long T = t[0];
        long A = a[0];
        for (int i = 1; i < n; i++) {
            long r = Math.max((T + t[i] - 1) / t[i], (A + a[i] - 1) / a[i]);
            T = r * t[i];
            A = r * a[i];
        }
        writer.write(String.valueOf(T + A));
        writer.newLine();
    }

    public static void main(String[] args) throws Exception {
        solve();
        writer.flush();
    }
}

