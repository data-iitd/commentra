
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * Main class for converting Roman numerals to integers.
 */
public final class Main {

    /**
     * A map storing the Roman symbols and their corresponding integer values.
     */
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

    /**
     * Private constructor to prevent instantiation of this class.
     */
    private Main() {
    }

    /**
     * Converts a single Roman symbol to its corresponding integer value.
     *
     * @param symbol the Roman symbol to convert
     * @return the integer value of the given Roman symbol
     * @throws IllegalArgumentException if the given symbol is unknown
     */
    private static int romanSymbolToInt(final char symbol) {
        return ROMAN_TO_INT.computeIfAbsent(symbol, c -> { throw new IllegalArgumentException("Unknown Roman symbol: " + c); });
    }

    /**
     * Converts a string of Roman numerals to its corresponding integer value.
     *
     * @param roman the Roman numeral string to convert
     * @return the integer value of the given Roman numeral string
     */
    public static int romanToInt(String roman) {
        if (roman == null) { // Check if the input is null
            throw new NullPointerException("Input cannot be null");
        }
        roman = roman.toUpperCase(); // Convert the input to uppercase
        int sum = 0; // Initialize the sum variable
        int maxPrevValue = 0; // Initialize the maximum previous value variable

        // Iterate through the Roman numeral string from the end to the beginning
        for (int i = roman.length() - 1; i >= 0; i--) {
            int currentValue = romanSymbolToInt(roman.charAt(i)); // Get the integer value of the current Roman symbol
            if (currentValue >= maxPrevValue) { // If the current value is greater than or equal to the maximum previous value
                sum += currentValue; // Add the current value to the sum
                maxPrevValue = currentValue; // Update the maximum previous value
            } else { // Otherwise, subtract the current value from the sum
                sum -= currentValue;
            }
        }

        return sum; // Return the final integer value
    }

    /**
     * The entry point of the program.
     *
     * @param args command-line arguments (not used in this program)
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a new Scanner object to read user input
        String romanNumeral = scanner.nextLine(); // Read a line of input from the user

        try {
            int result = romanToInt(romanNumeral); // Convert the Roman numeral to an integer
            System.out.println("Integer value: " + result); // Print the integer value to the console
        } catch (IllegalArgumentException | NullPointerException e) { // Catch any exceptions thrown during the conversion process
            System.out.println("Error: " + e.getMessage()); // Print the error message to the console
        }

        scanner.close(); // Close the Scanner object
    }
}