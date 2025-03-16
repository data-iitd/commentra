import java.util.Scanner;

// Constants
class Constants {
    static final int MOD = 998244353;
    static final int FAC_NUM = 300001;
}

public class Main {
    // Main function
    public static void main(String[] args) {
        // Initialize a new scanner
        Scanner sc = new Scanner(System.in);

        // Read an integer N from the standard input
        int N = sc.nextInt();

        // Initialize a variable sum to 0
        long sum = 0;

        // Loop through numbers from 1 to N
        for (int i = 1; i <= N; i++) {
            // If the number is not divisible by 3 or 5, add it to the sum
            if (i % 3 != 0 && i % 5 != 0) {
                sum += i;
            }
        }

        // Print the result to the standard output
        System.out.println(sum);
    }

    // Math functions
    static int pow(int a, int n) {
        // Calculate a^n modulo MOD
        int ans = 1;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = (int)((1L * ans * a) % Constants.MOD);
            }
            a = (int)((1L * a * a) % Constants.MOD);
            n >>= 1;
        }
        return ans;
    }

    static int gcd(int a, int b) {
        // Calculate the greatest common divisor of a and b
        if (a < b) {
            return gcd(b, a);
        }
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    static int min(int a, int b) {
        // Return the minimum of a and b
        return a < b ? a : b;
    }

    // Combination function
    static int combination(int n, int k, int[] fac, int[] ifac) {
        // Calculate the binomial coefficient (n choose k) modulo MOD
        if (n < k || n < 0) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        return (int)((1L * ifac[k] * ifac[n - k] % Constants.MOD) * fac[n] % Constants.MOD);
    }

    // Factorial function
    static int[][] factorial() {
        // Calculate and return the factorial of all numbers from 0 to FAC_NUM-1
        int[] fac = new int[Constants.FAC_NUM];
        int[] ifac = new int[Constants.FAC_NUM];
        fac[0] = 1;
        ifac[0] = 1;
        for (int i = 1; i < Constants.FAC_NUM; i++) {
            fac[i] = (int)((1L * fac[i - 1] * i) % Constants.MOD);
            ifac[i] = (int)((1L * ifac[i - 1] * pow(i, Constants.MOD - 2)) % Constants.MOD);
        }
        return new int[][]{fac, ifac};
    }

    // Lower bound function
    static int lowerBound(int[] vs, int v) {
        // Calculate the index of the first element in vs that is greater than or equal to v
        int n = vs.length / 2;
        int m = vs.length;
        while (m != n) {
            if (vs[n] < v) {
                n = (m - n + 1) / 2 + n;
            } else {
                m = n;
                n = n / 2;
            }
        }
        return n;
    }

    // IntSlice function
    static int[] intSlice(int n, int init) {
        // Create and initialize a slice of length n with the given initial value
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            r[i] = init;
        }
        return r;
    }
}

// <END-OF-CODE>
