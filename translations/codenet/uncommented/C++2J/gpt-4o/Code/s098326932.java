import java.util.Scanner;

public class Main {
    static long f(long N) {
        long[] a = new long[20];
        int d = 0;
        while (N > 0) {
            a[d] = N % 10;
            N /= 10;
            d++;
        }
        double m = 1e18;
        long res = N;
        for (int i = 0; i <= d; i++) {
            long bunsi = 0;
            long bunbo = 9 * i;
            for (int j = d - 1; j >= 0; j--) {
                bunsi *= 10;
                if (j < i) bunsi += 9;
                else bunsi += a[j];

                if (j >= i) bunbo += a[j];
            }
            double frac = (double) bunsi / (double) bunbo;
            if (frac < m) {
                m = frac;
                res = bunsi;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long K = scanner.nextLong();
        long N = f(1);
        for (long i = 0; i < K; i++) {
            System.out.println(N);
            N = f(N + 1);
        }
        scanner.close();
    }
}

// <END-OF-CODE>
