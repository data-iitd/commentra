import java.util.Objects;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of this utility class
    private Main() {}

    // Multiplication table used for the Verhoeff algorithm
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

    // Multiplicative inverse table used for the Verhoeff algorithm
    private static final byte[] MULTIPLICATIVE_INVERSE = {
        0, 4, 3, 2, 1, 5, 6, 7, 8, 9
    };

    // Permutation table used for the Verhoeff algorithm
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

    // Method to validate a number using the Verhoeff algorithm
    public static boolean verhoeffCheck(String digits) {
        // Validate input format
        checkInput(digits);
        // Convert input string to an integer array
        int[] numbers = toIntArray(digits);
        int checksum = 0;

        // Calculate checksum using the multiplication and permutation tables
        for (int i = 0; i < numbers.length; i++) {
            int index = numbers.length - i - 1;
            byte b = PERMUTATION_TABLE[i % 8][numbers[index]];
            checksum = MULTIPLICATION_TABLE[checksum][b];
        }
        // Return true if checksum is zero (valid), false otherwise
        return checksum == 0;
    }

    // Method to add a checksum to the initial digits using the Verhoeff algorithm
    public static String addMainChecksum(String initialDigits) {
        // Validate input format
        checkInput(initialDigits);
        // Append a placeholder '0' for checksum calculation
        String modifiedDigits = initialDigits + "0";
        // Convert modified string to an integer array
        int[] numbers = toIntArray(modifiedDigits);
        int checksum = 0;

        // Calculate checksum using the multiplication and permutation tables
        for (int i = 0; i < numbers.length; i++) {
            int index = numbers.length - i - 1;
            byte b = PERMUTATION_TABLE[i % 8][numbers[index]];
            checksum = MULTIPLICATION_TABLE[checksum][b];
        }
        // Get the multiplicative inverse of the checksum
        checksum = MULTIPLICATIVE_INVERSE[checksum];
        // Return the original digits with the calculated checksum appended
        return initialDigits + checksum;
    }

    // Main method to run the application
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Prompt user for input to validate
        System.out.print("Enter a number to validate: ");
        String inputToValidate = scanner.nextLine();
        // Validate the input and display the result
        System.out.println("Input is " + (verhoeffCheck(inputToValidate) ? "valid" : "not valid"));
        
        // Prompt user for input to generate a checksum
        System.out.print("Enter a number to generate a checksum: ");
        String inputToGenerateChecksum = scanner.nextLine();
        // Generate and display the number with checksum
        System.out.println("Number with checksum: " + addMainChecksum(inputToGenerateChecksum));
        
        // Close the scanner to prevent resource leaks
        scanner.close();
    }

    // Method to check if the input string is valid (non-null and numeric)
    private static void checkInput(String input) {
        Objects.requireNonNull(input); // Ensure input is not null
        // Throw an exception if input contains invalid characters
        if (!input.matches("\\d+")) {
            throw new IllegalArgumentException("Input contains invalid characters: " + input);
        }
    }

    // Method to convert a string of digits into an integer array
    private static int[] toIntArray(String string) {
        return string.chars().map(Character::getNumericValue).toArray();
    }
}
