import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int a; // Declare and initialize variable 'a' to store first user input
        int b; // Declare and initialize variable 'b' to store second user input
        int result; // Declare variable 'result' to store the result of the computation

        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input
        a = scanner.nextInt(); // Read the first integer value from the user
        b = scanner.nextInt(); // Read the second integer value from the user

        if (a > b) { // Check if 'a' is greater than 'b'
            result = 2 * a - 1; // If true, assign the value '2 * a - 1' to 'result'
        } else if (a == b) { // Check if 'a' is equal to 'b'
            result = 2 * a; // If true, assign the value '2 * a' to 'result'
        } else { // If 'a' is less than 'b'
            result = 2 * b - 1; // Assign the value '2 * b - 1' to 'result'
        }

        System.out.println(result); // Print the value of 'result' to the console

        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
