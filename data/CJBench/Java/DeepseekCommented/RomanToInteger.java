
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
public final class Main {
    // Initializes a map for Roman numerals to their integer values
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
    
    // Private constructor to prevent instantiation
    private Main() {
    }
    
    // Converts a single Roman numeral character to its integer value
    private static int romanSymbolToInt(final char symbol) {
        return ROMAN_TO_INT.computeIfAbsent(symbol, c -> { throw new IllegalArgumentException("Unknown Roman symbol: " + c); });
    }
    
    // Converts a full Roman numeral string to an integer
    public static int romanToInt(String roman) {
        if (roman == null) {
            throw new NullPointerException("Input cannot be null");
        }
        roman = roman.toUpperCase(); // Converts the input string to uppercase
        int sum = 0;
        int maxPrevValue = 0;
        for (int i = roman.length() - 1; i >= 0; i--) {
            int currentValue = romanSymbolToInt(roman.charAt(i));
            if (currentValue >= maxPrevValue) {
                sum += currentValue;
                maxPrevValue = currentValue;
            } else {
                sum -= currentValue;
            }
        }
        return sum;
    }
    
    // Main method to handle user input and output
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String romanNumeral = scanner.nextLine();
        try {
            int result = romanToInt(romanNumeral);
            System.out.println("Integer value: " + result);
        } catch (IllegalArgumentException | NullPointerException e) {
            System.out.println("Error: " + e.getMessage());
        }
        scanner.close();
    }
}

This code provides a comprehensive solution for converting Roman numerals to integers. It includes detailed comments to explain each logical block, making it easier to understand and maintain.