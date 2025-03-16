import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();

        long total = 0;
        for (int i = k; i <= n + 1; i++) {
            total += combi(n, i);
            total = total % (pow(10, 9) + 7);
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

    public static int max(int... values) {
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

    public static long max64(long... values) {
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

    public static long pow64(long base, int exponent) {
        long answer = 1;
        for (int i = 0; i < exponent; i++) {
            answer *= base;
        }
        return answer;
    }
}
// <END-OF-CODE>
