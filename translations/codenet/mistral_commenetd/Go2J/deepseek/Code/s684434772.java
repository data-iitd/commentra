import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();

        long total = 0;

        for (int i = k; i <= n + 1; i++) {
            long comb = combi(n, i);
            total += comb;
            total = total % (long) (Math.pow(10, 9) + 7);
        }

        System.out.println(total);
    }

    public static long combi(int n, int k) {
        long min = (long) (k - 1) * k / 2;
        long max = (long) (2 * n - k + 1) * k / 2;
        return max - min + 1;
    }

    public static int abs(int x) {
        return x >= 0 ? x : -x;
    }

    public static int min(int... values) {
        int min = values[0];
        for (int v : values) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    public static int max(int... values) {
        int max = values[0];
        for (int v : values) {
            if (v > max) {
                max = v;
            }
        }
        return max;
    }

    public static int pow(int base, int exponent) {
        int answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }

    public static long abs64(long x) {
        return x >= 0 ? x : -x;
    }

    public static long min64(long... values) {
        long min = values[0];
        for (long v : values) {
            if (v < min) {
                min = v;
            }
        }
        return min;
    }

    public static long max64(long... values) {
        long max = values[0];
        for (long v : values) {
            if (v > max) {
                max = v;
            }
        }
        return max;
    }

    public static long pow64(long base, int exponent) {
        long answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }
}
