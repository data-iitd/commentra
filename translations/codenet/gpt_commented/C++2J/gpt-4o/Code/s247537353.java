import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input

        long A = scanner.nextLong(); // Read input value for A
        long B = scanner.nextLong(); // Read input value for B
        long C = scanner.nextLong(); // Read input value for C (not used in the logic)
        long K = scanner.nextLong(); // Read input value for K

        // Check if the sum of A and B is greater than or equal to K
        if (A + B >= K) {
            // If true, output the minimum of A and K
            System.out.println(Math.min(A, K));
        } else {
            // If false, calculate and output the remaining value after subtracting (K - (A + B)) from A
            System.out.println(A - (K - (A + B)));
        }

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
