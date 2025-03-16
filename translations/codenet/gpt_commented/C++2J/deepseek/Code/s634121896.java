import java.util.*;
import java.io.*;

public class Main {
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
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

    static class FastWriter {
        private final BufferedWriter bw;

        public FastWriter() {
            this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void print(Object object) throws IOException {
            bw.append("" + object);
        }

        public void println(Object object) throws IOException {
            print(object);
            bw.append("\n");
        }

        public void close() throws IOException {
            bw.close();
        }
    }

    static final int INF = (int) 1e9 + 228;
    static final long INFLL = (long) 1e18;
    static final int MOD = (int) 1e9 + 7;
    static final double eps = 1e-6;
    static final double eps2 = 1e-9;
    static final int MOD2 = 998244353;
    static final int dosz = 500000;
    static final int SZ = 1 << 18;
    static final double PI = Math.atan2(0, -1);

    public static void main(String[] args) throws IOException {
        FastReader fr = new FastReader();
        FastWriter fw = new FastWriter();
        int q = 1;
        while (q-- > 0) {
            solve(fr, fw);
        }
        fw.close();
    }

    public static void solve(FastReader fr, FastWriter fw) throws IOException {
        int n = fr.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = fr.nextInt();
        }

        int[] dp = new int[n + 1];
        dp[0] = 1;
        Map<Integer, Integer> kek = new HashMap<>();
        Map<Integer, Integer> prev = new HashMap<>();

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + (prev.getOrDefault(nums[i - 1], i - 1) != i - 1 ? kek.getOrDefault(nums[i - 1], 0) : 0);
            dp[i] %= MOD;
            kek.put(nums[i - 1], dp[i]);
            prev.put(nums[i - 1], i);
        }

        fw.println(dp[n]);
    }
}
