import java.util.Scanner;

public class AverageCalculator {
    public static void main(String[] args) {
        // Declare variables to hold two integers and their average
        int a, b, n;

        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Read two integers from user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the average of the two integers
        n = (a + b) / 2;

        // Print the calculated average
        System.out.println(n);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
