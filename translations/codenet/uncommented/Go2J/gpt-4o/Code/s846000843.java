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
            ans = Math.min(ans, Math.abs(cumsum[cumsum.length - 1] - cumsum[i] - (cumsum[i] - cumsum[0])));
        }

        System.out.println(ans);
    }

    static class Io {
        private BufferedReader reader;
        private PrintWriter writer;
        private StringTokenizer tokenizer;

        public Io() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            writer = new PrintWriter(System.out);
        }

        public void flush() {
            writer.flush();
        }

        public String nextLine() throws IOException {
            return reader.readLine();
        }

        public String next() throws IOException {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(nextLine());
            }
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public void printLn(Object... a) {
            for (Object obj : a) {
                writer.print(obj + " ");
            }
            writer.println();
        }
    }

    static int[] cumSum(int[] nums) {
        int[] sums = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        return sums;
    }

    static int abs(int a) {
        return a >= 0 ? a : -a;
    }

    static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("Function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int lcm(int a, int b) {
        if (a == 0 && b == 0) {
            return 0;
        }
        return a * b / gcd(a, b);
    }

    static int[] sortAsc(int[] a) {
        Arrays.sort(a);
        return a;
    }

    static int[] sortDesc(int[] a) {
        Integer[] boxedArray = Arrays.stream(a).boxed().toArray(Integer[]::new);
        Arrays.sort(boxedArray, Collections.reverseOrder());
        return Arrays.stream(boxedArray).mapToInt(Integer::intValue).toArray();
    }

    static List<Integer> divisors(int n) {
        Set<Integer> divisors = new HashSet<>();
        for (int i = 1; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                divisors.add(i);
                if (i != n / i) {
                    divisors.add(n / i);
                }
            }
        }
        return new ArrayList<>(divisors);
    }
}

// <END-OF-CODE>
