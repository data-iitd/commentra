
import java.util.Objects;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }

    private static final byte[][] DAMM_TABLE = {
        // Damm table for checksum calculation
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

    public static boolean dammCheck(String digits) {
        // Method to check if given digits form a valid Damm number
        checkInput(digits);
        int[] numbers = toIntArray(digits);
        int checksum = 0;
        for (int number : numbers) {
            checksum = DAMM_TABLE[checksum][number];
        }
        return checksum == 0;
    }

    public static String addMainChecksum(String initialDigits) {
        // Method to add main checksum to given digits
        checkInput(initialDigits);
        int[] numbers = toIntArray(initialDigits);
        int checksum = 0;
        for (int number : numbers) {
            checksum = DAMM_TABLE[checksum][number];
        }
        return initialDigits + String.valueOf(checksum.intValue());
    }

    public static void main(String[] args) {
        // Main method to handle user input and call appropriate methods
        Scanner sc = new Scanner(System.in);
        String operation = sc.nextLine();
        if (operation.equalsIgnoreCase("check")) {
            // Check operation
            String digits = sc.nextLine();
            try {
                boolean isValid = dammCheck(digits);
                System.out.println("The input '" + digits + "' is " + (isValid ? "valid" : "not valid"));
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        } else if (operation.equalsIgnoreCase("generate")) {
            // Generate operation
            System.out.println("Enter the input digits to generate checksum:");
            String digits = sc.nextLine();
            try {
                String result = addMainChecksum(digits);
                System.out.println("Generated value with checksum: " + result);
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        } else {
            // Invalid operation
            System.out.println("Invalid operation. Please enter 'check' or 'generate'.");
        }
        sc.close();
    }

    private static void checkInput(String input) {
        // Method to validate input and throw exception if it's invalid
        Objects.requireNonNull(input);
        Pattern pattern = Pattern.compile("\\d+");
        Matcher matcher = pattern.matcher(input);
        if (!matcher.matches()) {
            throw new IllegalArgumentException("Input '" + input + "' contains not only digits");
        }
    }

    private static int[] toIntArray(String string) {
        // Method to convert given string to an integer array
        return string.chars().map(i -> Character.digit(i, 10)).toArray();
    }
}