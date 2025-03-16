import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.*;
import java.lang.Math;

public class Main {
    public static void main(String[] args) throws IOException {
        Io io = new Io();
        try {
            int n = io.Int();
            int[] aa = new int[n];
            for (int i = 0; i < n; i++) {
                aa[i] = io.Int();
            }
            int[] cumsum = CumSum(aa);
            int ans = Integer.MAX_VALUE;
            for (int i = 1; i < cumsum.length - 1; i++) {
                ans = Math.min(ans, Math.abs(cumsum[cumsum.length - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
            }
            io.PrintLn(ans);
        } finally {
            io.Flush();
        }
    }

    static class Io {
        private BufferedReader reader;
        private BufferedWriter writer;
        private StringTokenizer tokenizer;

        public Io() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new BufferedWriter(new OutputStreamWriter(System.out));
        }

        public void Flush() throws IOException {
            writer.flush();
        }

        public String NextLine() throws IOException {
            return reader.readLine();
        }

        public String Next() throws IOException {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(NextLine());
            }
            return tokenizer.nextToken();
        }

        public int Int() throws IOException {
            return Integer.parseInt(Next());
        }

        public double Double() throws IOException {
            return Double.parseDouble(Next());
        }

        public void PrintLn(Object... a) throws IOException {
            for (Object o : a) {
                writer.write(o.toString());
                writer.write(" ");
            }
            writer.newLine();
        }

        public void Printf(String format, Object... a) throws IOException {
            writer.write(String.format(format, a));
        }

        public void PrintIntLn(int[] a) throws IOException {
            for (int x : a) {
                writer.write(x);
                writer.write(" ");
            }
            writer.newLine();
        }

        public void PrintStringLn(String[] a) throws IOException {
            for (String x : a) {
                writer.write(x);
                writer.write(" ");
            }
            writer.newLine();
        }
    }

    public static int[] CumSum(int[] nums) {
        int[] sums = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return sums;
    }

    public static int Abs(int a) {
        return a >= 0 ? a : -a;
    }

    public static int Min(int... nums) {
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    public static int Max(int... nums) {
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    public static int[] SortAsc(int[] a) {
        Arrays.sort(a);
        return a;
    }

    public static int[] SortDesc(int[] a) {
        Arrays.sort(a);
        int n = a.length;
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
        return a;
    }

    public static int GCD(int a, int b) {
        if (b == 0) {
            return a;
        }
        return GCD(b, a % b);
    }

    public static int LCM(int a, int b) {
        if (a == 0 && b == 0) {
            return 0;
        }
        return a * b / GCD(a, b);
    }

