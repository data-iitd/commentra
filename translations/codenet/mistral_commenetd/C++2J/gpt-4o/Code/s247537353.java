import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input values from the standard input
        long A = scanner.nextLong();
        long B = scanner.nextLong();
        long C = scanner.nextLong();
        long K = scanner.nextLong();

        // Check if the sum of A and B is greater than or equal to K
        if (A + B >= K) {
            // If true, print the minimum value between A and K
            System.out.println(Math.min(A, K));
        } else {
            // If false, calculate the difference between K and the sum of A and B,
            // and subtract it from A to get the required value
            System.out.println(A - (K - (A + B)));
        }

        scanner.close(); // Close the scanner
    }
}
// <END-OF-CODE>
