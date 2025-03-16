
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        // Initialize a new FastScanner to read input
        FastScanner fsc = new FastScanner();
        // Read three integers A, B, and C from input
        int A = fsc.nextInt();
        int B = fsc.nextInt();
        int C = fsc.nextInt();
        // Check if the difference between B and A is equal to the difference between C and B
        if (B - A == C - B) {
            // If the differences are equal, print "YES"
            System.out.println("YES");
        } else {
            // Otherwise, print "NO"
            System.out.println("NO");
        }
    }

    // FastScanner is a structure for efficient input reading
    public static class FastScanner {
        BufferedReader r;
        StringTokenizer t;
        String s;

        public FastScanner() {
            // Create a new buffered reader with a specified size
            r = new BufferedReader(new InputStreamReader(System.in), 1024);
        }

        // Next reads the next token from the input
        public String next() {
            if (t == null || !t.hasMoreTokens()) {
                try {
                    s = r.readLine();
                    t = new StringTokenizer(s);
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            return t.nextToken();
        }

        // NextLine reads the next line from the input
        public String nextLine() {
            try {
                return r.readLine();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
        }

        // NextInt reads the next integer from the input
        public int nextInt() {
            return Integer.parseInt(next());
        }

        // NextInt64 reads the next int64 from the input
        public long nextInt64() {
            return Long.parseLong(next());
        }
    }

    // IntMax returns the maximum of two integers
    public static int IntMax(int a, int b) {
        if (a < b) {
            return b; // Return b if it is greater
        }
        return a; // Otherwise, return a
    }

    // Int64Max returns the maximum of two int64 values
    public static long Int64Max(long a, long b) {
        if (a < b) {
            return b; // Return b if it is greater
        }
        return a; // Otherwise, return a
    }

    // Float64Max returns the maximum of two float64 values
    public static double Float64Max(double a, double b) {
        if (a < b) {
            return b; // Return b if it is greater
        }
        return a; // Otherwise, return a
    }

    // IntMin returns the minimum of two integers
    public static int IntMin(int a, int b) {
        if (a > b) {
            return b; // Return b if it is smaller
        }
        return a; // Otherwise, return a
    }

    // Int64Min returns the minimum of two int64 values
    public static long Int64Min(long a, long b) {
        if (a > b) {
            return b; // Return b if it is smaller
        }
        return a; // Otherwise, return a
    }

    // Float64Min returns the minimum of two float64 values
    public static double Float64Min(double a, double b) {
        if (a > b) {
            return b; // Return b if it is smaller
        }
        return a; // Otherwise, return a
    }

    // IntGcd computes the greatest common divisor of two integers
    public static int IntGcd(int a, int b) {
        if (a < b) {
            b = a; // Ensure a is the larger number
        }
        if (b == 0) {
            return a; // If b is zero, return a
        }
        return IntGcd(b, a % b); // Recursive call to find GCD
    }

    // Int64Gcd computes the greatest common divisor of two int64 values
    public static long Int64Gcd(long a, long b) {
        if (a < b) {
            b = a; // Ensure a is the larger number
        }
        if (b == 0) {
            return a; // If b is zero, return a
        }
        return Int64Gcd(b, a % b); // Recursive call to find GCD
    }

    // IntAbs returns the absolute value of an integer
    public static int IntAbs(int a) {
        if (a < 0) {
            a *= -1; // Negate if a is negative
        }
        return a; // Return the absolute value
    }

    // Int64Abs returns the absolute value of an int64
    public static long Int64Abs(long a) {
        if (a < 0) {
            a *= -1; // Negate if a is negative
        }
        return a; // Return the absolute value
    }

    // Float64Abs returns the absolute value of a float64
    public static double Float64Abs(double a) {
        if (a < 0) {
            a *= -1; // Negate if a is negative
        }
        return a; // Return the absolute value
    }

    // Float64Min returns the minimum of two float64 values
    public static double Float64Min(double a, double b) {
        if (a > b) {
            return b; // Return b if it is smaller
        }
        return a; // Otherwise, return a
    }

    // Float64Max returns the maximum of two float64 values
    public static double Float64Max(double a, double b) {
        if (a < b) {
            return b; // Return b if it is greater
        }
        return a; // Otherwise, return a
    }

    // Int64Min returns the minimum of two int64 values
    public static long Int64Min(long a, long b) {
        if (a > b) {
            return b; // Return b if it is smaller
        }
        return a; // Otherwise, return a
    }

    // Int64Max returns the maximum of two int64 values
    public static long Int64Max(long a, long b) {
        if (a < b) {
            return b; // Return b if it is greater
        }
        return a; // Otherwise, return a
    }

    // IntMin returns the minimum of two integers
    public static int IntMin(int a, int b) {
        if (a > b) {
            return b; // Return b if it is smaller
        }
        return a; // Otherwise, return a
    }

    // IntMax returns the maximum of two integers
    public static int IntMax(int a, int b) {
        if (a < b) {
            return b; // Return b if it is greater
        }
        return a; // Otherwise, return a
    }

    // Int64Abs returns the absolute value of an int64
    public static long Int64Abs(long a) {
        if (a < 0) {
            a *= -1; // Negate if a is negative
        }
        return a; // Return the absolute value
    }

    // IntAbs returns the absolute value of an integer
    public static int IntAbs(int a) {
        if (a < 0) {
            a *= -1; // Negate if a is negative
        }
        return a; // Return the absolute value
    }

    // Int64Gcd computes the greatest common divisor of two int64 values
    public static long Int64Gcd(long a, long b) {
        if (a < b) {
            b = a; // Ensure a is the larger number
        }
        if (b == 0) {
            return a; // If b is zero, return a
        }
        return Int64Gcd(b, a % b); // Recursive call to find GCD
    }

    // IntGcd computes the greatest common divisor of two integers
    public static int IntGcd(int a, int b) {
        if (a < b) {
            b = a; // Ensure a is the larger number
        }
        if (b == 0) {
            return a; // If b is zero, return a
        }
        return IntGcd(b, a % b); // Recursive call to find GCD
    }

    // Int64Min returns the minimum of two int64 values
    public static long Int64Min(long a, long b) {
        if (a > b) {
            return b; // Return b if it is smaller
        }
        return a; // Otherwise, return a
    }

    // Int64Max returns the maximum of two int64 values
    public static long Int64Max(long a, long b) {
        if (a < b) {
            return b; // Return b if it is greater
        }
        return a; // Otherwise, return a
    }

    // IntMin returns the minimum of two integers
    public static int IntMin(int a, int b) {
        if (a > b) {
            return b; // Return b if it is smaller
        }
        return a; // Otherwise, return a
    }

    // IntMax returns the maximum of two integers
    public static int IntMax(int a, int b) {
        if (a < b) {
            return b; // Return b if it is greater
        }
        return a; // Otherwise, return a
    }

    // Int64Abs returns the absolute value of an int64
    public static long Int64Abs(long a) {
        if (a < 0) {
            a *= -1; // Negate if a is negative
        }
        return a; // Return the absolute value
    }

    // IntAbs returns the absolute value of an integer
    public static int IntAbs(int a) {
        if (a < 0) {
            a *= -1; // Negate if a is negative
        }
        return a; // Return the absolute value
    }

    // Int64Gcd computes the greatest common divisor of two int64 values
    public static long Int64Gcd(long a, long b) {
        if (a < b) {
            b = a; // Ensure a is the larger number
        }
        if (b == 0) {
            return a; // If b is zero, return a
        }
        return Int64Gcd(b, a % b); // Recursive call to find GCD
    }

    // IntGcd computes the greatest common divisor of two integers
    public static int IntGcd(int a, int b) {
        if (a < b) {
            b = a; // Ensure a is the larger number
        }
        if (b == 0) {
            return a; // If b is zero, return a
        }
        return IntGcd(b, a % b); // Recursive call to find GCD
    }

    // Int64Min returns the minimum of two int64 values
    public static long Int64Min(long a, long b) {
        if (a > b) {
            return b; // Return b if it is smaller
        }
        return a; // Otherwise, return a
    }

    // Int64Max returns the maximum of two int64 values
    public static long Int64Max(long a, long b) {
        if (a < b) {
            return b; // Return b if it is greater
        }
        return a; // Otherwise,