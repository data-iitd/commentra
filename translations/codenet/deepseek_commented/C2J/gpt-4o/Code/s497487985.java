import java.util.Scanner;

public class Main {
    // Function to calculate the greatest common divisor (GCD)
    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    // Function to calculate the least common multiple (LCM)
    public static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long n; // Number of players
        long k; // Initial points
        long q; // Number of queries
        long[] a = new long[100001]; // Array to store query results
        long[] point = new long[100001]; // Array to store points for each player

        // Read input values
        n = scanner.nextLong();
        k = scanner.nextLong();
        q = scanner.nextLong();

        // Process each query to update points
        for (long i = 0; i < q; i++) {
            a[(int)i] = scanner.nextLong();
            point[(int)a[(int)i] - 1]++; // Update points for the player who answered the query
        }

        // Determine if each player can reach the required points
        for (long i = 0; i < n; i++) {
            if (k - (q - point[(int)i]) > 0) {
                System.out.println("Yes"); // Player can reach the required points
            } else {
                System.out.println("No"); // Player cannot reach the required points
            }
        }

        scanner.close();
    }
}
// <END-OF-CODE>
