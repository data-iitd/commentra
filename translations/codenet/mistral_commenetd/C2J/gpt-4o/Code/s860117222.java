import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare three long long integers to store input values
        long a, b, c;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read the values of a, b, and c from the standard input
        a = scanner.nextLong();
        b = scanner.nextLong();
        c = scanner.nextLong();

        // Calculate the difference between c and the sum of a and b
        long d = c - a - b;

        // Check if d is positive and if the product of the squares of a and b is less than d squared
        if (d > 0 && (4 * a * b) < (d * d)) {
            // If the condition is true, print "Yes" to the standard output
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No" to the standard output
            System.out.println("No");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
