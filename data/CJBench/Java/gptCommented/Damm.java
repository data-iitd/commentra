import java.util.Objects;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Damm algorithm checksum lookup table
    private static final byte[][] DAMM_TABLE = {
        {0, 3, 1, 7, 5, 9, 8, 6, 4, 2},
        {7, 0, 9, 2, 1, 5, 4, 8, 6, 3},
        {4, 2, 0, 6, 8, 7, 1, 3, 5, 9},
        {1, 7, 5, 0, 9, 8, 3, 4, 2, 6},
        {6, 1, 2, 3, 0, 4, 5, 9, 7, 8},
        {3, 6, 7, 4, 2, 0, 9, 5, 8, 1},
        {5, 8, 6, 9, 7, 2, 0, 1, 3, 4},
        {8, 9, 4, 5, 3, 6, 2, 0, 1, 7},
        {9, 4, 3, 8, 6, 1, 7, 2, 0, 5},
        {2, 5, 8, 1, 4, 3, 6, 7, 9, 0},
    };

    // Method to check if the input digits are valid according to the Damm algorithm
    public static boolean dammCheck(String digits) {
        checkInput(digits); // Validate input format
        int[] numbers = toIntArray(digits); // Convert input string to an integer array
        int checksum = 0; // Initialize checksum

        // Calculate checksum using the Damm table
        for (int number : numbers) {
            checksum = DAMM_TABLE[checksum][number];
        }
        // Return true if checksum is 0 (valid), false otherwise
        return checksum == 0;
    }

    // Method to generate a checksum for the given initial digits
    public static String addMainChecksum(String initialDigits) {
        checkInput(initialDigits); // Validate input format
        int[] numbers = toIntArray(initialDigits); // Convert input string to an integer array
        int checksum = 0; // Initialize checksum

        // Calculate checksum using the Damm table
        for (int number : numbers) {
            checksum = DAMM_TABLE[checksum][number];
        }
        // Return the original digits concatenated with the checksum
        return initialDigits + checksum;
    }

    // Main method to handle user input and execute operations
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner for user input
        String operation = sc.nextLine(); // Read the operation type (check or generate)

        // Check operation: Validate input digits
        if (operation.equalsIgnoreCase("check")) {
            String digits = sc.nextLine(); // Read the digits to check
            try {
                boolean isValid = dammCheck(digits); // Validate the digits
                // Output the result of the validation
                System.out.println("The input '" + digits + "' is " + (isValid ? "valid" : "not valid"));
            } catch (Exception e) {
                // Handle any exceptions that occur during validation
                System.out.println("Error: " + e.getMessage());
            }
        } 
        // Generate operation: Create a checksum for the input digits
        else if (operation.equalsIgnoreCase("generate")) {
            System.out.println("Enter the input digits to generate checksum:");
            String digits = sc.nextLine(); // Read the digits to generate checksum
            try {
                String result = addMainChecksum(digits); // Generate the checksum
                // Output the result with the checksum
                System.out.println("Generated value with checksum: " + result);
            } catch (Exception e) {
                // Handle any exceptions that occur during checksum generation
                System.out.println("Error: " + e.getMessage());
            }
        } else {
            // Handle invalid operation input
            System.out.println("Invalid operation. Please enter 'check' or 'generate'.");
        }
        sc.close(); // Close the scanner
    }

    // Method to check if the input is valid (not null and contains only digits)
    private static void checkInput(String input) {
        Objects.requireNonNull(input); // Ensure input is not null
        if (!input.matches("\\d+")) { // Check if input contains only digits
            throw new IllegalArgumentException("Input '" + input + "' contains not only digits");
        }
    }

    // Method to convert a string of digits into an integer array
    private static int[] toIntArray(String string) {
        return string.chars().map(i -> Character.digit(i, 10)).toArray(); // Convert each character to its integer value
    }
}
