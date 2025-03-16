
import java.util.Map;
import java.util.Scanner;

public final class Main {
    // Initialize a map to store base numbers and their English words representation
    private static final Map<Integer, String> BASE_NUMBERS_MAP = Map.ofEntries(
        Map.entry(0, ""), Map.entry(1, "One"), Map.entry(2, "Two"), Map.entry(3, "Three"), Map.entry(4, "Four"),
        Map.entry(5, "Five"), Map.entry(6, "Six"), Map.entry(7, "Seven"), Map.entry(8, "Eight"), Map.entry(9, "Nine"),
        Map.entry(10, "Ten"), Map.entry(11, "Eleven"), Map.entry(12, "Twelve"), Map.entry(13, "Thirteen"),
        Map.entry(14, "Fourteen"), Map.entry(15, "Fifteen"), Map.entry(16, "Sixteen"), Map.entry(17, "Seventeen"),
        Map.entry(18, "Eighteen"), Map.entry(19, "Nineteen"), Map.entry(20, "Twenty"), Map.entry(30, "Thirty"),
        Map.entry(40, "Forty"), Map.entry(50, "Fifty"), Map.entry(60, "Sixty"), Map.entry(70, "Seventy"),
        Map.entry(80, "Eighty"), Map.entry(90, "Ninety"), Map.entry(100, "Hundred")
    );

    // Initialize a map to store thousand power and their English words representation
    private static final Map<Integer, String> THOUSAND_POWER_MAP = Map.ofEntries(
        Map.entry(1, "Thousand"), Map.entry(2, "Million"), Map.entry(3, "Billion")
    );

    private Main() {
    }

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read an integer number from the console
        int number = scanner.nextInt();

        // Close the Scanner object to free system resources
        scanner.close();

        try {
            // Convert the integer number to its English words representation
            String result = integerToEnglishWords(number);

            // Print the English words representation to the console
            System.out.println("English Word Representation: " + result);
        } catch (IllegalArgumentException e) {
            // Print an error message to the console if the number is negative
            System.out.println("Error: " + e.getMessage());
        }
    }

    // Convert an integer number to its English words representation
    private static String convertToWords(int number) {
        int remainder = number % 100;
        StringBuilder result = new StringBuilder();

        // Handle the case when the remainder is less than or equal to 20
        if (remainder <= 20) {
            result.append(BASE_NUMBERS_MAP.get(remainder));
        } else if (BASE_NUMBERS_MAP.containsKey(remainder)) {
            // Handle the case when the remainder is a two-digit number
            result.append(BASE_NUMBERS_MAP.get(remainder / 10 * 10));

            // Handle the case when the remainder is a number between 21 and 99
            int onesDigit = remainder % 10;
            if (onesDigit > 0) {
                String ones = BASE_NUMBERS_MAP.getOrDefault(onesDigit, "");
                result.append(" ").append(ones);
            }
        }

        // Handle the case when the number has hundreds digit
        int hundredsDigit = number / 100;
        if (hundredsDigit > 0) {
            String hundreds = BASE_NUMBERS_MAP.get(hundredsDigit);
            if (result.length() > 0) {
                result.insert(0, " ");
            }
            result.insert(0, String.format("%s Hundred", hundreds));
        }

        return result.toString().trim();
    }

    // Convert an integer number to its English words representation
    public static String integerToEnglishWords(int number) {
        if (number < 0) {
            throw new IllegalArgumentException("Number must be non-negative.");
        }

        if (number == 0) {
            return "Zero";
        }

        StringBuilder result = new StringBuilder();
        int index = 0;

        // Convert the number to its English words representation by iterating through its digits
        while (number > 0) {
            int remainder = number % 1000;
            number /= 1000;

            // If the remainder is greater than zero, convert it to English words and add it to the result
            if (remainder > 0) {
                String subResult = convertToWords(remainder);
                if (!subResult.isEmpty()) {
                    if (index > 0) {
                        subResult += " " + THOUSAND_POWER_MAP.get(index);
                    }
                    if (result.length() > 0) {
                        result.insert(0, " ");
                    }
                    result.insert(0, subResult);
                }
            }
            index++;
        }

        return result.toString().trim();
    }
}