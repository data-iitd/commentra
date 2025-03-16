import java.util.*;

public class Main {
    static final long BIG = 2000000007;
    static final long VERYBIG = 20000000000000007L;
    static final long MOD = 1000000007;
    static final long FOD = 998244353;
    static final int N_MAX = 1048576;

    static long n, m;
    static long[] cnt = new long[3];
    static long pcnt;
    static String s;

    static long gcd(long x, long y) {
        if (y == 0) {
            return x;
        } else {
            return gcd(y, x % y);
        }
    }

    static long bitpow(long a, long x, long modulo) {
        long result = 1;
        while (x > 0) {
            if ((x & 1) == 1) {
                result = (result * a) % modulo;
            }
            x /= 2;
            a = (a * a) % modulo;
        }
        return result;
    }

    static long divide(long a, long b, long modulo) {
        return (a * bitpow(b, modulo - 2, modulo)) % modulo;
    }

    static long ncr(long n, long r, long m) {
        if (n < 0 || r < 0 || n < r) return 0;
        return (factorial(n) * (inverseFactorial(r) * inverseFactorial(n - r) % m)) % m;
    }

    static long factorial(long n) {
        long result = 1;
        for (long i = 1; i <= n; i++) {
            result = (result * i) % FOD;
        }
        return result;
    }

    static long inverseFactorial(long n) {
        return bitpow(factorial(n), FOD - 2, FOD);
    }

    static long solve() {
        long result = 1;
        for (int i = 0; i < n * 3; i++) {
            long v;
            switch (s.charAt(i)) {
                case 'R':
                    v = 0;
                    break;
                case 'G':
                    v = 1;
                    break;
                case 'B':
                    v = 2;
                    break;
                default:
                    continue;
            }

            if (cnt[(int) ((v + 1) % 3)] > 0 && cnt[(int) ((v + 2) % 3)] > 0) {
                result = (result * pcnt) % FOD;
                pcnt--;
                cnt[(int) ((v + 1) % 3)]--;
                cnt[(int) ((v + 2) % 3)]--;
            } else {
                if ((cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) > cnt[(int) v]) {
                    result = (result * ((cnt[(int) ((v + 1) % 3)] + cnt[(int) ((v + 2) % 3)]) - cnt[(int) v])) % FOD;
                    pcnt++;
                }
                cnt[(int) v]++;
            }
        }

        System.out.println(result);
        return 0;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextLong();
        m = scanner.nextLong();
        s = scanner.next();
        solve();
    }
}

// <END-OF-CODE>
