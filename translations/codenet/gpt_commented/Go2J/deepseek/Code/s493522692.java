import java.util.Scanner;

public class Main {
    // Utility functions for input and mathematical operations

    // nextInt reads the next integer from input
    static int nextInt() {
        return sc.nextInt();
    }

    // maxInt returns the maximum of two integers
    static int maxInt(int a, int b) {
        return a > b ? a : b;
    }

    // minInt returns the minimum of two integers
    static int minInt(int a, int b) {
        return a < b ? a : b;
    }

    // absInt returns the absolute value of an integer
    static int absInt(int a) {
        return a >= 0 ? a : -a;
    }

    // maxFloat64 returns the maximum of two float64 values
    static double maxFloat64(double a, double b) {
        return a > b ? a : b;
    }

    // minFloat64 returns the minimum of two float64 values
    static double minFloat64(double a, double b) {
        return a < b ? a : b;
    }

    // str2Int converts a string to an integer
    static int str2Int(String s) {
        return Integer.parseInt(s);
    }

    // reverse returns the reversed string
    static String reverse(String s) {
        char[] chars = s.toCharArray();
        for (int i = 0, j = chars.length - 1; i < j; i++, j--) {
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
        }
        return new String(chars);
    }

    // powInt calculates p raised to the power of q
    static int powInt(int p, int q) {
        return (int) Math.pow(p, q);
    }

    // isPrime checks if a number is prime
    static boolean isPrime(int x) {
        if (x == 1) {
            return false;
        }
        if (x == 2) {
            return true;
        }
        if (x % 2 == 0) {
            return false;
        }

        boolean b = true;
        int rootx = (int) Math.sqrt(x);
        for (int i = 3; i <= rootx; i += 2) {
            if (x % i == 0) {
                b = false;
                break;
            }
        }
        return b;
    }

    // PrimeFactors returns the prime factors of a number
    static int[] PrimeFactors(int n) {
        // Get the number of 2s that divide n
        int[] pfs = new int[32];
        int index = 0;
        while (n % 2 == 0) {
            pfs[index++] = 2;
            n /= 2;
        }

        // n must be odd at this point, so we can skip one element
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            // while i divides n, append i and divide n
            while (n % i == 0) {
                pfs[index++] = i;
                n /= i;
            }
        }

        // Handle the case when n is a prime number greater than 2
        if (n > 2) {
            pfs[index++] = n;
        }

        int[] result = new int[index];
        System.arraycopy(pfs, 0, result, 0, index);
        return result;
    }

    // PrimeFactorsMap returns a map of prime factors and their counts
    static int[] PrimeFactorsMap(int n) {
        int[] pfs = new int[32];
        int index = 0;
        // Get the number of 2s that divide n
        while (n % 2 == 0) {
            pfs[index++] = 2;
            n /= 2;
        }

        // n must be odd at this point, so we can skip one element
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            // while i divides n, append i and divide n
            while (n % i == 0) {
                pfs[index++] = i;
                n /= i;
            }
        }

        // Handle the case when n is a prime number greater than 2
        if (n > 2) {
            pfs[index++] = n;
        }

        int[] result = new int[index];
        System.arraycopy(pfs, 0, result, 0, index);
        return result;
    }

    // sumInts returns the sum of a slice of integers
    static int sumInts(int[] x) {
        int total = 0;
        for (int v : x) {
            total += v;
        }
        return total;
    }

    // gcd calculates the greatest common divisor of two integers
    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // lcm calculates the least common multiple of two integers
    static int lcm(int x, int y) {
        return x * y / gcd(x, y);
    }

    // Main function
    static final int initialBufSize = 10000; // Initial buffer size for input
    static final int maxBufSize = 1000000; // Maximum buffer size for input
    static final int mod = 1_000_000_007; // Modulus value

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        // Read the number of 'S' and 'c'
        int N = nextInt();
        int M = nextInt();
        int tmp = minInt(N, M / 2); // Calculate the minimum of N and half of M
        int ans = tmp; // Add the temporary value to the answer
        N -= tmp; // Decrease N by the temporary value
        M -= tmp * 2; // Decrease M by twice the temporary value
        // Output the final answer, which includes the remaining M divided by 4
        System.out.println(ans + M / 4);
    }
}
