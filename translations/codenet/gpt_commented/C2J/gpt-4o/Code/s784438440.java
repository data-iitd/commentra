import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables a and b
        int a, b;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read two integers from user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate and print the result of the expression
        // The expression computes the number of complete groups of (a-1) that can fit into (b-1) + (a-2)
        System.out.println((b - 1 + a - 2) / (a - 1));

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
