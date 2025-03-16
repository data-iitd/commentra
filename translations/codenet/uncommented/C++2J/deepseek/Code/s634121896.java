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
    }

    public static void main(String[] args) {
        FastScanner scanner = new FastScanner(System.in);
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
