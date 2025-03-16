import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables n and m
        int n, m;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read two integers from standard input
        // n represents the number of rows, and m represents the number of columns
        n = scanner.nextInt();
        m = scanner.nextInt();

        // Calculate the product of (n - 1) and (m - 1)
        // This represents the number of internal edges in a grid of n by m cells
        System.out.println((n - 1) * (m - 1));

        // Close the scanner to free resources
        scanner.close();
    }
}

// <END-OF-CODE>
