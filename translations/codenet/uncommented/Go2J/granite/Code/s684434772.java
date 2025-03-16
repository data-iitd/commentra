
import java.util.Scanner;

public class s684434772{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        long total = 0;
        for (int i = k; i <= n + 1; i++) {
            total += combi(n, i);
            total = total % (long) Math.pow(10, 9) + 7;
        }
        System.out.println(total);
    }

    public static long combi(int n, int k) {
        long min = (long) (k - 1) * k / 2;
        long max = (long) (2 * n - k + 1) * k / 2;
        return max - min + 1;
    }

    // util
    // *   math/simple

    public static int Abs(int x) {
        if (x >= 0) {
            return x;
        }
        return -x;
    }

    public static int Min(int... values) {
        if (values.length == 0) {
            throw new RuntimeException("no values");
        }
        int min = values[0];
        for (int v : values) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    public static int Max(int... values) {
        if (values.length == 0) {
            throw new RuntimeException("no values");
        }
        int max = values[0];
        for (int v : values) {
            if (v > max) {
                max = v;
            }
        }
        return max;
    }

    public static int Pow(int base, int exponent) {
        int answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }

    public static long Abs64(long x) {
        if (x >= 0) {
            return x;
        }
        return -x;
    }

    public static long Min64(long... values) {
        if (values.length == 0) {
            throw new RuntimeException("no values");
        }
        long min = values[0];
        for (long v : values) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    public static long Max64(long... values) {
        if (values.length == 0) {
            throw new RuntimeException("no values");
        }
        long max = values[0];
        for (long v : values) {
            if (v > max) {
                max = v;
            }
        }
        return max;
    }

    public static long Pow64(long base, int exponent) {
        long answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }

    // *   io

    public static class Scanner {
        private java.util.Scanner bufScanner;

        public Scanner() {
            bufScanner = new java.util.Scanner(System.in);
            bufScanner.useDelimiter("\\s+");
        }

        public String next() {
            bufScanner.hasNext();
            return bufScanner.next();
        }

        public int nextInt() {
            bufScanner.hasNextInt();
            return bufScanner.nextInt();
        }

        public long nextLong() {
            bufScanner.hasNextLong();
            return bufScanner.nextLong();
        }
    }
}

// 