// Import the Scanner class for reading input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from standard input
        Scanner scanner = new Scanner(System.in);

        // Declare and initialize three integer variables "a", "b", and "c"
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        // Check if the condition "a < b && b < c" is true using an if statement
        if (a < b && b < c) {
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
