import java.util.Random;
import java.util.Scanner;
public final class MillerRabinPrimalityCheck {
    private MillerRabinPrimalityCheck() {
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        int k = scanner.nextInt();
        boolean isProbablyPrime = millerRabin(n, k);
        System.out.println("Using Miller-Rabin Probabilistic Test: " + (isProbablyPrime ? "Probably Prime" : "Composite"));
        boolean isPrime = deterministicMillerRabin(n);
        System.out.println("Using Deterministic Miller-Rabin Test: " + (isPrime ? "Prime" : "Composite"));
    }
    public static boolean millerRabin(long n, int k) {
        if (n < 4) {
            return n == 2 || n == 3;
        }
        int s = 0;
        long d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            s++;
        }
        Random rnd = new Random();
        for (int i = 0; i < k; i++) {
            long a = 2 + Math.abs(rnd.nextLong()) % (n - 3); 
            if (checkComposite(n, a, d, s)) {
                return false;
            }
        }
        return true;
    }
    public static boolean deterministicMillerRabin(long n) {
        if (n < 2) {
            return false;
        }
        int r = 0;
        long d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }
        for (int a : new int[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (n == a) {
                return true;
            }
            if (checkComposite(n, a, d, r)) {
                return false;
            }
        }
        return true;
    }
    private static boolean checkComposite(long n, long a, long d, int s) {
        long x = powerModP(a, d, n);
        if (x == 1 || x == n - 1) {
            return false;
        }
        for (int r = 1; r < s; r++) {
            x = powerModP(x, 2, n);
            if (x == n - 1) {
                return false;
            }
        }
        return true;
    }
    private static long powerModP(long x, long y, long p) {
        long res = 1;
        x %= p;
        if (x == 0) {
            return 0;
        }
        while (y > 0) {
            if ((y & 1) == 1) {
                res = multiplyModP(res, x, p);
            }
            y >>= 1;
            x = multiplyModP(x, x, p);
        }
        return res;
    }
    private static long multiplyModP(long a, long b, long p) {
        long res = 0;
        a %= p;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = (res + a) % p;
            }
            a = (2 * a) % p;
            b >>= 1;
        }
        return res;
    }
}
