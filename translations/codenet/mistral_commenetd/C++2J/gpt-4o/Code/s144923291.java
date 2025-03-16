import java.util.Scanner;

public class Main {
    // Constants for maximum integer values
    static final int intmax = Integer.MAX_VALUE;
    static final long lmax = Long.MAX_VALUE;
    static final long uintmax = Long.MAX_VALUE; // Java does not have unsigned types
    static final long ulmax = Long.MAX_VALUE; // Java does not have unsigned types
    static final long llmax = Long.MAX_VALUE;

    // Function for ceiling division
    static long cei(long x, long y) {
        long ans = x / y;
        if (x % y != 0) ans++;
        return ans;
    }

    // Function for finding greatest common divisor
    static long gcd(long x, long y) {
        return y == 0 ? x : gcd(y, x % y);
    }

    // Function for finding least common multiple
    static long lcm(long x, long y) {
        return x / gcd(x, y) * y;
    }

    // Function for exponentiation
    static long llpow(long x, long n) {
        long ans = 1;
        for (long i = 0; i < n; i++) {
            ans *= x;
        }
        return ans;
    }

    // Function for factorial calculation
    static long fact(long x) {
        long ans = 1;
        for (long i = 0; i < x; i++) {
            ans *= (x - i);
        }
        return ans;
    }

    // Function for calculating nCr
    static long ncr(long n, long r) {
        return fact(n) / fact(r) / fact(n - r);
    }

    // Function for calculating nPr
    static long npr(long n, long r) {
        return fact(n) / fact(n - r);
    }

    // Function for prime number check
    static boolean prime(long a) {
        if (a <= 1) return false;
        for (long i = 2; i * i <= a; i++) {
            if (a % i == 0) return false;
        }
        return true;
    }

    // Function for generating Fibonacci sequence
    static long fib(long x) {
        long[] fibo = new long[(int) (x + 10)];
        fibo[0] = 1;
        fibo[1] = 1;
        fibo[2] = 1;
        for (long i = 3; i <= x; i++) {
            fibo[(int) i] = fibo[(int) (i - 1)] + fibo[(int) (i - 2)];
        }
        return fibo[(int) x];
    }

    // Function for finding number of digits
    static long dig(long n) {
        long d = 0;
        while (n / 10 > 0) {
            d++;
            n /= 10;
        }
        return d;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        long h = sc.nextLong(); // Read height
        long w = sc.nextLong(); // Read width
        String s = "snuke"; // Pattern to match

        for (long i = 0; i < h; i++) { // Iterate through each row
            for (long j = 0; j < w; j++) { // Iterate through each column
                String t = sc.next(); // Read a string from input
                if (s.equals(t)) { // Check if current string matches the pattern
                    char c = (char) ('A' + j); // Calculate the column index and convert to character
                    System.out.println(c + "" + (i + 1)); // Print the character and its row number
                    return; // Exit if a match is found
                }
            }
        }

        sc.close(); // Close the scanner
    }
}
// <END-OF-CODE>
