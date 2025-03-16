import java.util.Scanner;

public class Main {
    // Greatest Common Divisor
    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    // Least Common Multiple
    public static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long q = scanner.nextLong();
        
        long[] a = new long[(int) q];
        long[] point = new long[(int) n];

        // Read the input for q queries
        for (int i = 0; i < q; i++) {
            a[i] = scanner.nextLong();
            point[(int) (a[i] - 1)]++;
        }

        // Determine if each player has enough points
        for (int i = 0; i < n; i++) {
            if (k - (q - point[i]) > 0) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }

        scanner.close();
    }
}

// <END-OF-CODE>
