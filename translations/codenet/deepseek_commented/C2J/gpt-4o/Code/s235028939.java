import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int n = scanner.nextInt(); // Read the first integer
        int m = scanner.nextInt(); // Read the second integer
        System.out.println((n - 1) * (m - 1)); // Print the result of the expression (n - 1) * (m - 1)
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
