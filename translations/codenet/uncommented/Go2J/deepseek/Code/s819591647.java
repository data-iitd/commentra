import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class ProblemB {
    private static final int MOD = (int) (1e9 + 7);

    private static class FastScanner {
        BufferedReader reader;
        StringTokenizer tokenizer;

        FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }

        String next() throws Exception {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        int nextInt() throws Exception {
            return Integer.parseInt(next());
        }

        long nextLong() throws Exception {
            return Long.parseLong(next());
        }

        double nextDouble() throws Exception {
            return Double.parseDouble(next());
        }

        String nextLine() throws Exception {
            return reader.readLine();
        }

        int[] nextIntArray(int n) throws Exception {
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(next());
            }
            return arr;
        }

        long[] nextLongArray(int n) throws Exception {
            long[] arr = new long[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Long.parseLong(next());
            }
            return arr;
        }
    }

    private static class FastWriter {
        PrintWriter writer;

        FastWriter() {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        }

        void print(Object object) {
            writer.print(object);
        }

        void println(Object object) {
            writer.println(object);
        }

        void close() {
            writer.close();
        }
    }

    private static int numAbs(int x) {
        if (x < 0) {
            return -x;
        }
        return x;
    }

    private static int numModPow(int a, int n, int m) {
        int result = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            n >>= 1;
        }
        return result;
    }

    private static int numGcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return numGcd(b, a % b);
    }

    private static int numLcm(int a, int b) {
        return a * b / numGcd(a, b);
    }

    private static int numModInv(int a, int p) {
        if (a == 1) {
            return 1;
        }
        return p - numModInv(p % a, p) * (p / a) % p;
    }

    private static List<Integer> numModFrac(int n) {
        List<Integer> frac = new ArrayList<>();
        frac.add(1);
        for (int i = 1; i <= n; i++) {
            frac.add(i * frac.get(i - 1) % MOD);
        }
        return frac;
    }

    private static int numModConb(int n, int r) {
        List<Integer> frac = numModFrac(n);
        return (frac.get(n) / ((frac.get(n - r) * frac.get(r)) % MOD)) % MOD;
    }

    private static void solve() throws Exception {
        FastScanner scanner = new FastScanner();
        FastWriter writer = new FastWriter();

        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] a = scanner.nextIntArray(n);

        int sum = 0;
        for (int v : a) {
            sum += v;
        }

        int count = 0;
        for (int v : a) {
            double rate = (double) sum / (4 * m);
            if ((double) v >= rate) {
                count++;
            }
        }

        if (count >= m) {
            writer.println("Yes");
        } else {
            writer.println("No");
        }

        writer.close();
    }

    public static void main(String[] args) throws Exception {
        solve();
    }
}
