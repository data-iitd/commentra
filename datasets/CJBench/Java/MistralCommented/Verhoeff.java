
import java.util.Objects;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public final class Main {
    private Main() {}

    // Initialize a 2D array representing the multiplication table
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

    // Initialize an array representing the multiplicative inverse
    private static final byte[] MULTIPLICATIVE_INVERSE = {
        0, 4, 3, 2, 1, 5, 6, 7, 8, 9
    };

    // Initialize a 2D array representing the permutation table
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

    // Function to check if a given string of digits passes the Verhoeff checksum algorithm
    public static boolean verhoeffCheck(String digits) {
        // Check input validity
        checkInput(digits);

        // Convert the string to an integer array
        int[] numbers = toIntArray(digits);

        // Initialize checksum variable
        int checksum = 0;

        // Iterate through the digits in reverse order and calculate the checksum
        for (int i = 0; i < numbers.length; i++) {
            int index = numbers.length - i - 1;
            byte b = PERMUTATION_TABLE[i % 8][numbers[index]];
            checksum = MULTIPLICATION_TABLE[checksum][b];
        }

        // Return true if the checksum is zero, indicating valid digits
        return checksum == 0;
    }

    // Function to add a checksum to a given string of digits using the Verhoeff algorithm
    public static String addMainChecksum(String initialDigits) {
        // Check input validity
        checkInput(initialDigits);

        // Concatenate the input with a zero to prepare for the checksum calculation
        String modifiedDigits = initialDigits + "0";

        // Initialize checksum variable
        int checksum = 0;

        // Iterate through the digits in reverse order and calculate the checksum
        for (int i = 0; i < modifiedDigits.length(); i++) {
            int index = modifiedDigits.length() - i - 1;
            byte b = PERMUTATION_TABLE[i % 8][Character.isDigit(modifiedDigits.charAt(index)) ? modifiedDigits.charAt(index) - '0' : 10];
            checksum = MULTIPLICATION_TABLE[checksum][b];
        }

        // Calculate the multiplicative inverse of the checksum and append it to the result
        checksum = MULTIPLICATIVE_INVERSE[checksum];

        // Return the original input with the checksum appended
        return initialDigits + checksum;
    }

    // Main method to read user input and call the Verhoeff checksum functions
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Request user input for a number to validate
        System.out.print("Enter a number to validate: ");
        String inputToValidate = scanner.nextLine();

        // Validate the user input using the verhoeffCheck function and print the result
        boolean isValid = verhoeffCheck(inputToValidate);
        System.out.println("Input is " + (isValid ? "valid" : "not valid"));

        // Request user input for a number to generate a checksum for
        System.out.print("Enter a number to generate a checksum: ");
        String inputToGenerateChecksum = scanner.nextLine();

        // Generate the checksum for the user input using the addMainChecksum function and print the result
        String checksumResult = addMainChecksum(inputToGenerateChecksum);
        System.out.println("Number with checksum: " + checksumResult);

        scanner.close();
    }

    // Function to check the input string for validity
    private static void checkInput(String input) {
        Objects.requireNonNull(input);

        // Use a regular expression to check if the input consists only of digits
        Pattern pattern = Pattern.compile("\\d+");
        Matcher matcher = pattern.matcher(input);
        if (!matcher.matches()) {
            throw new IllegalArgumentException("Input contains invalid characters: " + input);
        }
    }

    // Function to convert a string of digits to an integer array
    private static int[] toIntArray(String string) {
        return string.chars().map(Character::getNumericValue).toArray();
    }
}