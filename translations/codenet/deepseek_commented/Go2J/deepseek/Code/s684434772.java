public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // Read the first integer, n.
        int k = sc.nextInt(); // Read the second integer, k.

        long total = 0; // Initialize the total sum of combinations.
        for (int i = k; i <= n + 1; i++) {
            total += combi(n, i); // Calculate the combination and add it to the total.
            total = total % (long)Math.pow(10, 9) + 7; // Apply modulo operation to prevent overflow.
        }
        System.out.println(total); // Print the final result.
    }

    // Combination Function
    // The combi function calculates the number of combinations of choosing k items from n items.
    // It uses a simplified formula to find the range of the binomial coefficient.
    public static long combi(int n, int k) {
        long min = (long)(k - 1) * k / 2; // Calculate the minimum value of the binomial coefficient.
        long max = (long)(2 * n - k + 1) * k / 2; // Calculate the maximum value of the binomial coefficient.
        return max - min + 1; // Return the number of combinations.
    }

    // Utility Classes
    // These classes provide basic mathematical operations and input reading capabilities.

    // Abs returns the absolute value of an integer.
    public static int Abs(int x) {
        if (x >= 0) {
            return x;
        }
        return -x;
    }

    // Min returns the smallest value among the given integers.
    public static int Min(int... values) {
        if (values.length == 0) {
            throw new IllegalArgumentException("no values");
        }
        int min = values[0];
        for (int v : values) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    // Max returns the largest value among the given integers.
    public static int Max(int... values) {
        if (values.length == 0) {
            throw new IllegalArgumentException("no values");
        }
        int max = values[0];
        for (int v : values) {
            if (v > max) {
                max = v;
            }
        }
        return max;
    }

    // Pow returns the base raised to the power of exponent.
    public static int Pow(int base, int exponent) {
        int answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }

    // Abs64 returns the absolute value of a 64-bit integer.
    public static long Abs64(long x) {
        if (x >= 0) {
            return x;
        }
        return -x;
    }

    // Min64 returns the smallest value among the given 64-bit integers.
    public static long Min64(long... values) {
        if (values.length == 0) {
            throw new IllegalArgumentException("no values");
        }
        long min = values[0];
        for (long v : values) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    // Max64 returns the largest value among the given 64-bit integers.
    public static long Max64(long... values) {
        if (values.length == 0) {
            throw new IllegalArgumentException("no values");
        }
        long max = values[0];
        for (long v : values) {
            if (v > max) {
                max = v;
            }
        }
        return max;
    }

    // Pow64 returns the base raised to the power of exponent for 64-bit integers.
    public static long Pow64(long base, int exponent) {
        long answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }

    // Scanner Class
    // The Scanner class provides methods to read input efficiently.

    static class Scanner {
        java.util.Scanner scanner;

        public Scanner(java.io.InputStream is) {
            scanner = new java.util.Scanner(is);
        }

        public int nextInt() {
            return scanner.nextInt();
        }

        public long nextLong() {
            return scanner.nextLong();
        }
    }
}
