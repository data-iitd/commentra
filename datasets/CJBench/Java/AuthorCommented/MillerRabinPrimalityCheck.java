import java.util.Random;
import java.util.Scanner;

public final class MillerRabinPrimalityCheck {

    private MillerRabinPrimalityCheck() {
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input: n (number to test) and k (number of iterations)
        long n = scanner.nextLong();
        int k = scanner.nextInt();

        // Probabilistic Miller-Rabin Test
        boolean isProbablyPrime = millerRabin(n, k);
        System.out.println("Using Miller-Rabin Probabilistic Test: " + (isProbablyPrime ? "Probably Prime" : "Composite"));

        // Deterministic Miller-Rabin Test
        boolean isPrime = deterministicMillerRabin(n);
        System.out.println("Using Deterministic Miller-Rabin Test: " + (isPrime ? "Prime" : "Composite"));
    }

    /**
     * Check whether the given number is prime or not
     * MillerRabin algorithm is probabilistic. There is also an altered version which is deterministic.
     * https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
     * https://cp-algorithms.com/algebra/primality_tests.html
     *
     * @param n Whole number which is tested on primality
     * @param k Number of iterations
     *       If n is composite then running k iterations of the Miller–Rabin
     *       test will declare n probably prime with a probability at most 4^(−k)
     * @return true or false whether the given number is probably prime or not
     */
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
            long a = 2 + Math.abs(rnd.nextLong()) % (n - 3); // Generate a random number in range [2, n-2]
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

    /**
     * Check if number n is composite (probabilistic)
     *
     * @param n Whole number which is tested for compositeness
     * @param a Random number (prime base) to check if it holds certain equality
     * @param d Number which holds this equation: 'n - 1 = 2^s * d'
     * @param s Number of twos in (n - 1) factorization
     *
     * @return true or false whether the numbers hold the equation or not
     *          the equations are described on the websites mentioned at the beginning of the class
     */
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
