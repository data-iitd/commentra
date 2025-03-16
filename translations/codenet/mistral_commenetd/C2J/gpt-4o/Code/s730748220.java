import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Declare variables
        int n;

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input

        System.out.print("Enter the value of n: ");
        n = scanner.nextInt(); // Read an integer value from the user and store it in variable n

        // Calculate and print the result
        System.out.println("The result is: " + (24 + (24 - n)));

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
