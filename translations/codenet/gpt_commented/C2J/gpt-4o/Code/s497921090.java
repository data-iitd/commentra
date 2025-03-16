import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        long n, b;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read an unsigned long long integer from user input
        n = scanner.nextLong();

        // Calculate the number of ways to choose 2 items from n items
        // This is done using the formula: b = n * (n - 1) / 2
        b = (n * (n - 1)) / 2;

        // Print the result
        System.out.println(b);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
