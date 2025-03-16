import java.util.Scanner;

// Main class: Entry point of the program.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        
        if (B - A == C - B) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
        
        scanner.close();
    }
}

// Utility functions for various operations.
class Utils {
    public static int max(int a, int b) {
        return a < b ? b : a;
    }

    public static long max(long a, long b) {
        return a < b ? b : a;
    }

    public static double max(double a, double b) {
        return a < b ? b : a;
    }

    public static int min(int a, int b) {
        return a > b ? b : a;
    }

    public static long min(long a, long b) {
        return a > b ? b : a;
    }

    public static double min(double a, double b) {
        return a > b ? b : a;
    }

    public static int gcd(int a, int b) {
        if (a < b) {
            int temp = b;
            b = a;
            a = temp;
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static long gcd(long a, long b) {
        if (a < b) {
            long temp = b;
            b = a;
            a = temp;
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static int abs(int a) {
        return a < 0 ? -a : a;
    }

    public static long abs(long a) {
        return a < 0 ? -a : a;
    }
}

// <END-OF-CODE>
