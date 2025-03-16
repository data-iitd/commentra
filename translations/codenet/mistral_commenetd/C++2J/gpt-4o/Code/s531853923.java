import java.util.Scanner;  // Import the Scanner class for input operations

public class Main {  // Declare the Main class
    public static void main(String[] args) {  // Declare the main method
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare four integer variables to store input values
        int a, b, c, d;

        // Read input values from the user using the Scanner
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Check if the condition is true
        if (a * b % 2 == 1 && (c + d) % 2 == 1) {
            // If the condition is true, print "No" to the output stream
            System.out.println("No");
        } else {
            // If the condition is false, print "Yes" to the output stream
            System.out.println("Yes");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
