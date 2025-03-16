import java.util.Scanner;
// Import the Scanner class for reading input.

public class Main {
    public static void main(String[] args) {
        int n;
        // Declare an integer variable 'n' to store the user input.

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        // Use the Scanner to read an integer value from the standard input
        // and store it in the variable 'n'.

        if (n % 2 == 0) {
            System.out.println(n / 2);
            // If the number 'n' is even, print the value of 'n/2' as the output.
        } else {
            System.out.println((n / 2) + 1);
            // If the number 'n' is odd, print the value of '(n/2)+1' as the output.
        }

        scanner.close();
        // Close the scanner to prevent resource leaks.
    }
}
// <END-OF-CODE>
