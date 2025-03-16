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

    public static void main(String[] args) {
        FastReader scanner = new FastReader();
        int q = scanner.nextInt();
        while (q-- > 0) {
            solve(scanner);
        }
    }

    static void solve(FastReader scanner) {
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int[] dp = new int[n + 1];
        dp[0] = 1;
        Map<Integer, Integer> kek = new HashMap<>();
        Map<Integer, Integer> prev = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + (prev.getOrDefault(nums[i - 1], i - 1) != i - 1 ? kek.getOrDefault(nums[i - 1], 0) : 0);
            dp[i] %= 1000000007;
            kek.put(nums[i - 1], dp[i]);
            prev.put(nums[i - 1], i);
        }
        System.out.println(dp[n]);
    }
}
