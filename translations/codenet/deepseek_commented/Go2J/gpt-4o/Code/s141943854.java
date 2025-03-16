import java.util.Scanner; // For reading input
import java.util.logging.Level; // For logging errors
import java.util.logging.Logger; // For logging errors

public class Main {
    private static final Logger logger = Logger.getLogger(Main.class.getName());

    // check function logs fatal errors if they occur
    private static void check(Exception e) {
        if (e != null) {
            logger.log(Level.SEVERE, "error: ", e);
            System.exit(1); // Exit the program on error
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for input
        String sage = scanner.nextLine(); // Read input from standard input

        switch (sage) {
            case "1":
                System.out.println("Hello World"); // Print "Hello World" if input is "1"
                break;
            case "2":
                int sum = 0; // Declare sum variable to store the sum of two integers
                for (int i = 0; i < 2; i++) {
                    String input = scanner.nextLine(); // Read input from standard input
                    try {
                        int num = Integer.parseInt(input); // Convert string to integer
                        sum += num; // Add the integer to the sum
                    } catch (NumberFormatException e) {
                        check(e); // Check for errors during conversion
                    }
                }
                System.out.println(sum); // Print the sum of the two integers
                break;
            default:
                System.out.println("Invalid input"); // Handle invalid input
                break;
        }
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
