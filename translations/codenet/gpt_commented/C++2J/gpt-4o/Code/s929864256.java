import java.util.Scanner; // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        long a = scanner.nextLong(); // Read a long integer a
        long b = scanner.nextLong(); // Read a long integer b

        // Calculate the maximum of the sum, difference, and product of a and b
        long result = Math.max(a + b, Math.max(a - b, a * b)); // Calculate the maximum value
        System.out.println(result); // Output the maximum value

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
