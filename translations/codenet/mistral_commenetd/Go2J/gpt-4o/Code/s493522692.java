// Util functions
import java.util.*;
import java.lang.Math;

public class UtilFunctions {
    
    // Scanner for input
    private static Scanner sc = new Scanner(System.in);

    // Scans the next token, a string, into sc and returns it.
    public static String nextStr() {
        return sc.next();
    }

    // Scans the next token, a string, into sc and converts it to an integer.
    public static int nextInt() {
        return Integer.parseInt(sc.next());
    }

    // Returns the maximum of two integers.
    public static int maxInt(int a, int b) {
        return (a > b) ? a : b;
    }

    // Returns the minimum of two integers.
    public static int minInt(int a, int b) {
        return (a < b) ? a : b;
    }

    // Returns the absolute value of an integer.
    public static int absInt(int a) {
        return (a >= 0) ? a : -a;
    }

    // Returns the absolute value of a floating-point number.
    public static double absFloat64(double a) {
        return (a >= 0) ? a : -a;
    }

    // Returns the maximum of two floating-point numbers.
    public static double maxFloat64(double a, double b) {
        return (a > b) ? a : b;
    }

    // Returns the minimum of two floating-point numbers.
    public static double minFloat64(double a, double b) {
        return (a < b) ? a : b;
    }

    // Converts a string to an integer.
    public static int str2Int(String s) {
        return Integer.parseInt(s);
    }

    // Reverses a given string.
    public static String reverse(String s) {
        return new StringBuilder(s).reverse().toString();
    }

    // Calculates 'p' raised to the power of 'q'.
    public static int powInt(int p, int q) {
        return (int) Math.pow(p, q);
    }

    // Checks if a given number is prime.
    public static boolean isPrime(int x) {
        if (x <= 1) return false;
        if (x == 2) return true;
        if (x % 2 == 0) return false;

        for (int i = 3; i * i <= x; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    }

    // Finds the prime factors of a given number.
    public static List<Integer> primeFactors(int n) {
        List<Integer> pfs = new ArrayList<>();
        
        while (n % 2 == 0) {
            pfs.add(2);
            n /= 2;
        }

        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                pfs.add(i);
                n /= i;
            }
        }

        if (n > 2) {
            pfs.add(n);
        }

        return pfs;
    }

    // Finds the prime factors of a given number and returns them as a map.
    public static Map<Integer, Integer> primeFactorsMap(int n) {
        Map<Integer, Integer> pfs = new HashMap<>();

        while (n % 2 == 0) {
            pfs.put(2, pfs.getOrDefault(2, 0) + 1);
            n /= 2;
        }

        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                pfs.put(i, pfs.getOrDefault(i, 0) + 1);
                n /= i;
            }
        }

        if (n > 2) {
            pfs.put(n, pfs.getOrDefault(n, 0) + 1);
        }

        return pfs;
    }
}

// <END-OF-CODE>
