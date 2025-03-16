import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Step 1: Include necessary libraries and declare variables
        // We include the Scanner class for input operations.
        // We declare two integer variables, N and A, to store user input.
        int N, A;

        // Step 2: Read input values
        // We create a Scanner object to read input from the standard input.
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        A = scanner.nextInt();

        // Step 3: Perform the required operation
        // We check if the remainder of N divided by 500 is less than or equal to A.
        // If the condition is true, we print "Yes"; otherwise, we print "No".
        System.out.println((N % 500 <= A) ? "Yes" : "No");

        // Step 4: Close the scanner
        // We close the scanner to prevent resource leaks.
        scanner.close();
    }
}

// <END-OF-CODE>
