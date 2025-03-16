import java.util.Scanner;

public class Main {
    // Function to check for errors and exit with error message if any
    private static void check(boolean condition, String message) {
        if (condition) {
            System.err.println("error: " + message);
            System.exit(1);
        }
    }

    // Main function
    public static void main(String[] args) {
        // Initialize a scanner to read from standard input
        Scanner scanner = new Scanner(System.in);

        // Read the first line from standard input
        String sage = scanner.nextLine();

        // Use a switch statement to determine the action based on the first line read
        switch (sage) {
            case "1":
                // Print "Hello World" if the first line is "1"
                System.out.println("Hello World");
                break;
            case "2":
                // Initialize a variable named 'sum' to store the sum of two numbers
                int sum = 0;

                // Use a for loop to read and sum two numbers
                for (int i = 0; i < 2; i++) {
                    // Read the next line from standard input
                    String input = scanner.nextLine();

                    // Convert the next line to an integer and store it in a variable named 'num'
                    int num;
                    try {
                        num = Integer.parseInt(input);
                    } catch (NumberFormatException e) {
                        check(true, "Invalid number format");
                        return; // This line will never be reached due to the check
                    }

                    // Add the current number to the sum
                    sum += num;
                }

                // Print the sum of the two numbers
                System.out.println(sum);
                break;
            default:
                System.err.println("Invalid input");
                break;
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
