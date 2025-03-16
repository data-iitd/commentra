import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Io io = new Io();
        int n = io.nextInt();

        int[] aa = new int[n];
        for (int i = 0; i < n; i++) {
            aa[i] = io.nextInt();
        }

        int[] cumsum = cumSum(aa);
        int ans = 2020202020;

        for (int i = 1; i < cumsum.length - 1; i++) {
            int diff1 = Math.abs(cumsum[cumsum.length - 1] - cumsum[i]);
            int diff2 = cumsum[i] - cumsum[0];
            ans = Math.min(ans, Math.min(diff1, diff2));
        }

        System.out.println(ans);
    }

    static class Io {
        private BufferedReader reader;
        private BufferedWriter writer;
        private StringTokenizer tokenizer;

        public Io() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new BufferedWriter(new OutputStreamWriter(System.out));
            tokenizer = new StringTokenizer("");
        }

        public String next() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public void flush() throws IOException {
            writer.flush();
        }
    }

    public static int[] cumSum(int[] nums) {
        int[] sums = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return sums;
    }
}
