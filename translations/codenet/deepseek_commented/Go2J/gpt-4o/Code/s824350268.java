import java.util.*;
import java.io.*;

public class Main {
    static final int initialBufSize = 10000;
    static final int maxBufSize = 1000000;
    static final int mod = (int) (1e9 + 7);
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = getInt();
        int sqrtN = (int) Math.sqrt(N);

        int min = N; // Initialize min with N.
        for (int i = 1; i <= sqrtN; i++) {
            if (N % i != 0) { // Check if i is a divisor of N.
                continue;
            }

            int num = i + (N / i) - 2; // Calculate the sum of the divisor and its complement.
            if (num < min) { // Update min if the current sum is smaller.
                min = num;
            }
        }

        System.out.println(min); // Print the minimum sum found.
    }

    // Read an integer from standard input.
    static int getInt() {
        return sc.nextInt();
    }

    // Read a string from standard input.
    static String getString() {
        return sc.next();
    }

    // Return the absolute value of a.
    static int abs(int a) {
        return Math.abs(a);
    }

    // Return a raised to the power of q.
    static int pow(int p, int q) {
        return (int) Math.pow(p, q);
    }

    // Return n raised to the power of p modulo mod.
    static int powMod(int n, int p) {
        if (p == 0) {
            return 1;
        } else if (p % 2 == 0) {
            int t = powMod(n, p / 2);
            return calcMod(t * t);
        } else {
            return calcMod(n * powMod(n, p - 1));
        }
    }

    // Return the minimum value among the provided integers.
    static int min(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function min() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.min(res, num);
        }
        return res;
    }

    // Return the maximum value among the provided integers.
    static int max(int... nums) {
        if (nums.length == 0) {
            throw new IllegalArgumentException("function max() requires at least one argument.");
        }
        int res = nums[0];
        for (int num : nums) {
            res = Math.max(res, num);
        }
        return res;
    }

    // Check if b is present in the array a.
    static boolean strSearch(String[] a, String b) {
        for (String s : a) {
            if (s.equals(b)) {
                return true;
            }
        }
        return false;
    }

    // Print the elements of an integer array.
    static void printIntArray(int[] array) {
        System.out.println(Arrays.toString(array).substring(1, Arrays.toString(array).length() - 1));
    }

    // Return x modulo mod.
    static int calcMod(int x) {
        return x % mod;
    }

    // Return the reverse of the given string.
    static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    // Check if n is a prime number.
    static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n % 2 == 0) {
            return false;
        }

        int sqrtN = (int) Math.sqrt(n);
        for (int i = 3; i <= sqrtN; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }
}
// <END-OF-CODE>
