import java.util.Scanner;

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
    }

    // Max, Min
    public static int intMax(int a, int b) {
        return a < b ? b : a;
    }

    public static long int64Max(long a, long b) {
        return a < b ? b : a;
    }

    public static double float64Max(double a, double b) {
        return a < b ? b : a;
    }

    public static int intMin(int a, int b) {
        return a > b ? b : a;
    }

    public static long int64Min(long a, long b) {
        return a > b ? b : a;
    }

    public static double float64Min(double a, double b) {
        return a > b ? b : a;
    }

    // Gcd
    public static int intGcd(int a, int b) {
        if (a < b) {
            int temp = b;
            b = a;
            a = temp;
        }
        if (b == 0) {
            return a;
        }
        return intGcd(b, a % b);
    }

    public static long int64Gcd(long a, long b) {
        if (a < b) {
            long temp = b;
            b = a;
            a = temp;
        }
        if (b == 0) {
            return a;
        }
        return int64Gcd(b, a % b);
    }

    public static int intAbs(int a) {
        return a < 0 ? -a : a;
    }

    public static long int64Abs(long a) {
        return a < 0 ? -a : a;
    }
}

// <END-OF-CODE>
