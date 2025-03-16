import java.util.*;
import java.io.*;

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

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = sc.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = sc.nextInt();
        }

        Arrays.sort(c);
        long ans = 0;
        final long mod = 1000000007;

        for (int i = 0; i < n; i++) {
            ans = (ans + (n + 1 - i) * c[i] % mod) % mod;
        }

        out.println(ans * modPow(4, n - 1, mod) % mod);
        out.flush();
    }

    public static long modPow(long a, int n, long mod) {
        long res = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                res = res * a % mod;
            }
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }
}
