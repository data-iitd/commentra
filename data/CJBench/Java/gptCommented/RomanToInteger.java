import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public final class Main {
    // A static map to hold the Roman numeral symbols and their corresponding integer values
    private static final Map<Character, Integer> ROMAN_TO_INT = new HashMap<>() {
        {
            put('I', 1);
            put('V', 5);
            put('X', 10);
            put('L', 50);
            put('C', 100);
            put('D', 500);
            put('M', 1000);
        }
    };

    // Private constructor to prevent instantiation of the Main class
    private Main() {
    }

    // Converts a single Roman numeral character to its integer value
    private static int romanSymbolToInt(final char symbol) {
        return ROMAN_TO_INT.computeIfAbsent(symbol, c -> { 
            throw new IllegalArgumentException("Unknown Roman symbol: " + c); 
        });
    }

    // Converts a Roman numeral string to its integer value
    public static int romanToInt(String roman) {
        // Check for null input and throw an exception if it is null
        if (roman == null) {
            throw new NullPointerException("Input cannot be null");
        }
        // Convert the input string to uppercase to handle lowercase inputs
        roman = roman.toUpperCase();
        int sum = 0; // Variable to hold the final integer value
        int maxPrevValue = 0; // Variable to track the maximum value of the previous Roman numeral

        // Iterate through the Roman numeral string from right to left
        for (int i = roman.length() - 1; i >= 0; i--) {
            int currentValue = romanSymbolToInt(roman.charAt(i)); // Get the integer value of the current Roman numeral
            // If the current value is greater than or equal to the maximum previous value, add it to the sum
            if (currentValue >= maxPrevValue) {
                sum += currentValue;
                maxPrevValue = currentValue; // Update the maximum previous value
            } else {
                // If the current value is less than the maximum previous value, subtract it from the sum
                sum -= currentValue;
            }
        }
        return sum; // Return the final computed integer value
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for user input
        String romanNumeral = scanner.nextLine(); // Read the input Roman numeral from the user
        try {
            // Convert the Roman numeral to an integer and print the result
            int result = romanToInt(romanNumeral);
            System.out.println("Integer value: " + result);
        } catch (IllegalArgumentException | NullPointerException e) {
            // Handle exceptions and print error messages
            System.out.println("Error: " + e.getMessage());
        }
        scanner.close(); // Close the scanner to free resources
    }
}
