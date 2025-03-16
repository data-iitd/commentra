import java.util.Scanner;

public class Main {
    // Utility function to check for errors and print a message if an error occurs.
    private static void check(Exception e) {
        if (e != null) {
            System.err.println("error: " + e.getMessage());
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        // Create a new scanner to read input from standard input (stdin).
        Scanner scanner = new Scanner(System.in);
        
        // Read the first line of input.
        String sage = scanner.nextLine(); // Store the input in the variable 'sage'.

        // Use a switch statement to handle different cases based on the input value.
        switch (sage) {
            case "1":
                // If the input is "1", print "Hello World".
                System.out.println("Hello World");
                break;
            case "2":
                // If the input is "2", initialize a variable to hold the sum of two numbers.
                int sum = 0;
                // Loop to read two numbers from input.
                for (int i = 0; i < 2; i++) {
                    String input = scanner.nextLine(); // Read the next line of input.
                    try {
                        int num = Integer.parseInt(input); // Convert the input string to an integer.
                        sum += num; // Add the number to the sum.
                    } catch (NumberFormatException e) {
                        check(e); // Check for any conversion errors.
                    }
                }
                // Print the total sum of the two numbers.
                System.out.println(sum);
                break;
            default:
                // Handle unexpected input if necessary.
                System.out.println("Invalid input");
                break;
        }
        
        scanner.close(); // Close the scanner to free resources.
    }
}

// <END-OF-CODE>
