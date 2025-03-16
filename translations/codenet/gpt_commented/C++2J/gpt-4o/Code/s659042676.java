import java.util.Scanner; // Import Scanner for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        int a, b; // Declare two integer variables to store input values

        // Read two integer values from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate and output the result of the expression (6 - a - b)
        // This assumes that a and b are part of a game or problem where their sum should not exceed 6
        System.out.println(6 - a - b);

        scanner.close(); // Close the scanner to prevent resource leaks
    }
}

// <END-OF-CODE>
