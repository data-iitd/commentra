import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize a new Scanner to read input
        Scanner scanner = new Scanner(System.in);
        // Read three integers A, B, and C from input
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        // Check if the difference between B and A is equal to the difference between C and B
        if (B - A == C - B) {
            // If the differences are equal, print "YES"
            System.out.println("YES");
        } else {
            // Otherwise, print "NO"
            System.out.println("NO");
        }
        scanner.close(); // Close the scanner
    }

    // Utility methods for max and min calculations
    public static int intMax(int a, int b) {
        return (a < b) ? b : a; // Return the maximum of two integers
    }

    public static long int64Max(long a, long b) {
        return (a < b) ? b : a; // Return the maximum of two int64 values
    }

    public static double float64Max(double a, double b) {
        return (a < b) ? b : a; // Return the maximum of two float64 values
    }

    public static int intMin(int a, int b) {
        return (a > b) ? b : a; // Return the minimum of two integers
    }

    public static long int64Min(long a, long b) {
        return (a > b) ? b : a; // Return the minimum of two int64 values
    }

    public static double float64Min(double a, double b) {
        return (a > b) ? b : a; // Return the minimum of two float64 values
    }

    public static int intGcd(int a, int b) {
        if (a < b) {
            int temp = b;
            b = a;
            a = temp; // Ensure a is the larger number
        }
        if (b == 0) {
            return a; // If b is zero, return a
        }
        return intGcd(b, a % b); // Recursive call to find GCD
    }

    public static long int64Gcd(long a, long b) {
        if (a < b) {
            long temp = b;
            b = a;
            a = temp; // Ensure a is the larger number
        }
        if (b == 0) {
            return a; // If b is zero, return a
        }
        return int64Gcd(b, a % b); // Recursive call to find GCD
    }

    public static int intAbs(int a) {
        return (a < 0) ? -a : a; // Return the absolute value of an integer
    }

    public static long int64Abs(long a) {
        return (a < 0) ? -a : a; // Return the absolute value of an int64
    }
}
// <END-OF-CODE>
