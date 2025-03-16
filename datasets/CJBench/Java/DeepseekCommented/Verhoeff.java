import java.util.Objects; // Importing Objects class to use its methods
import java.util.Scanner; // Importing Scanner class for input

public final class Main { // Defining the final class Main
    private Main() {} // Private constructor to prevent instantiation

    // Multiplication table for the Verhoeff algorithm
    private static final byte[][] MULTIPLICATION_TABLE = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 0, 6, 7, 8, 9, 5},
        {2, 3, 4, 0, 1, 7, 8, 9, 5, 6},
        {3, 4, 0, 1, 2, 8, 9, 5, 6, 7},
        {4, 0, 1, 2, 3, 9, 5, 6, 7, 8},
        {5, 9, 8, 7, 6, 0, 4, 3, 2, 1},
        {6, 5, 9, 8, 7, 1, 0, 4, 3, 2},
        {7, 6, 5, 9, 8, 2, 1, 0, 4, 3},
        {8, 7, 6, 5, 9, 3, 2, 1, 0, 4},
        {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
    };

    // Multiplicative inverse table for the Verhoeff algorithm
    private static final byte[] MULTIPLICATIVE_INVERSE = {
        0, 4, 3, 2, 1, 5, 6, 7, 8, 9
    };

    // Permutation table for the Verhoeff algorithm
    private static final byte[][] PERMUTATION_TABLE = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 5, 7, 6, 2, 8, 3, 0, 9, 4},
        {5, 8, 0, 3, 7, 9, 6, 1, 4, 2},
        {8, 9, 1, 6, 0, 4, 3, 5, 2, 7},
        {9, 4, 5, 3, 1, 2, 6, 8, 7, 0},
        {4, 2, 8, 6, 5, 7, 3, 9, 0, 1},
        {2, 7, 9, 3, 8, 0, 6, 4, 1, 5},
        {7, 0, 4, 6, 9, 1, 3, 2, 5, 8}
    };

    // Main method to check if the input string is valid according to the Verhoeff algorithm
    public static boolean verhoeffCheck(String digits) {
        checkInput(digits); // Check if the input is valid
        int[] numbers = toIntArray(digits); // Convert input string to an array of integers
        int checksum = 0; // Initialize checksum to 0
        for (int i = 0; i < numbers.length; i++) {
            int index = numbers.length - i - 1; // Calculate the index for the permutation table
            byte b = PERMUTATION_TABLE[i % 8][numbers[index]]; // Get the permuted value
            checksum = MULTIPLICATION_TABLE[checksum][b]; // Update the checksum using the multiplication table
        }
        return checksum == 0; // Return true if checksum is 0, otherwise false
    }

    // Method to add a checksum to the input string using the Verhoeff algorithm
    public static String addMainChecksum(String initialDigits) {
        checkInput(initialDigits); // Check if the input is valid
        String modifiedDigits = initialDigits + "0"; // Append "0" to the input string
        int[] numbers = toIntArray(modifiedDigits); // Convert the modified string to an array of integers
        int checksum = 0; // Initialize checksum to 0
        for (int i = 0; i < numbers.length; i++) {
            int index = numbers.length - i - 1; // Calculate the index for the permutation table
            byte b = PERMUTATION_TABLE[i % 8][numbers[index]]; // Get the permuted value
            checksum = MULTIPLICATION_TABLE[checksum][b]; // Update the checksum using the multiplication table
        }
        checksum = MULTIPLICATIVE_INVERSE[checksum]; // Get the multiplicative inverse of the checksum
        return initialDigits + checksum; // Return the input string with the appended checksum
    }

    // Main method to interact with the user
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        System.out.print("Enter a number to validate: "); // Prompt the user to enter a number
        String inputToValidate = scanner.nextLine(); // Read the input string
        System.out.println("Input is " + (verhoeffCheck(inputToValidate) ? "valid" : "not valid")); // Validate the input and print the result
        System.out.print("Enter a number to generate a checksum: "); // Prompt the user to enter a number
        String inputToGenerateChecksum = scanner.nextLine(); // Read the input string
        System.out.println("Number with checksum: " + addMainChecksum(inputToGenerateChecksum)); // Generate and print the checksum
        scanner.close(); // Close the Scanner object
    }

    // Helper method to check if the input string contains only digits
    private static void checkInput(String input) {
        Objects.requireNonNull(input); // Check if the input is not null
        if (!input.matches("\\d+")) { // Check if the input matches the pattern of digits
            throw new IllegalArgumentException("Input contains invalid characters: " + input); // Throw an exception if the input is invalid
        }
    }

    // Helper method to convert a string of digits to an array of integers
    private static int[] toIntArray(String string) {
        return string.chars().map(Character::getNumericValue).toArray(); // Convert the string to an array of integers
    }
}
