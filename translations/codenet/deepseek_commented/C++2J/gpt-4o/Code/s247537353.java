import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Fast I/O setup
        Scanner scanner = new Scanner(System.in);

        // Declare variables to store input values
        long A = scanner.nextLong();
        long B = scanner.nextLong();
        long C = scanner.nextLong();
        long K = scanner.nextLong();

        // Check if the sum of A and B is greater than or equal to K
        if (A + B >= K) {
            // Output the minimum of A and K
            System.out.println(Math.min(A, K));
        } else {
            // Calculate the result by subtracting the excess amount from A
            System.out.println(A - (K - (A + B)));
        }

        scanner.close();
    }
}
// <END-OF-CODE>
