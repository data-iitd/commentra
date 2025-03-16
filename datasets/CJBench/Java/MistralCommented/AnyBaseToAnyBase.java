
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public final class Main {
    private Main() {} // Private constructor to prevent instantiation of the class from outside

    static final int MINIMUM_BASE = 2; // Minimum base allowed for conversion
    static final int MAXIMUM_BASE = 36; // Maximum base allowed for conversion

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Initialize Scanner object to read input from the console

        String n = in.next(); // Read the first line (number to be converted) from the console
        int b1 = in.nextInt(); // Read the first base from the console

        // Check if the first base is within the allowed range
        while (b1 < MINIMUM_BASE || b1 > MAXIMUM_BASE) {
            System.out.println("Invalid base! Please enter again."); // Print error message and ask for a valid base
            b1 = in.nextInt(); // Read the base again
        }

        if (!validForBase(n, b1)) { // Check if the number is valid for the given base
            System.out.println("The number is invalid for this base!"); // Print error message and exit the program
            return;
        }

        int b2 = in.nextInt(); // Read the second base from the console

        // Check if the second base is within the allowed range
        while (b2 < MINIMUM_BASE || b2 > MAXIMUM_BASE) {
            System.out.println("Invalid base! Please enter again."); // Print error message and ask for a valid base
            b2 = in.nextInt(); // Read the base again
        }

        String result = base2base(n, b1, b2); // Convert the number from base b1 to base b2 and store the result
        System.out.println("Converted number: " + result); // Print the converted number
        in.close(); // Close the Scanner object
    }

    public static boolean validForBase(String n, int base) { // Check if the given number is valid for the given base
        char[] validDigits = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        }; // Define an array of valid digits for all bases
        char[] digitsForBase = Arrays.copyOfRange(validDigits, 0, base); // Extract the valid digits for the given base
        HashSet<Character> digitsList = new HashSet<>(); // Create a HashSet to store the unique valid digits

        for (char c : digitsForBase) { // Add each valid digit to the HashSet
            digitsList.add(c);
        }

        for (char c : n.toUpperCase().toCharArray()) { // Iterate through each character in the number (ignoring case)
            if (!digitsList.contains(c)) { // Check if the character is a valid digit for the given base
                return false; // If not, return false
            }
        }

        return true; // If all characters are valid digits, return true
    }

    public static String base2base(String n, int b1, int b2) { // Convert a number from base b1 to base b2
        int decimalValue = 0; // Initialize decimalValue to 0
        StringBuilder output = new StringBuilder(); // Initialize an empty StringBuilder to store the result

        for (char charB1 : n.toUpperCase().toCharArray()) { // Iterate through each character in the number (ignoring case)
            int charB2;

            if (charB1 >= 'A' && charB1 <= 'Z') { // If the character is a letter, convert it to its decimal value
                charB2 = 10 + (charB1 - 'A');
            } else { // If the character is a digit, its decimal value is its ASCII value minus '0'
                charB2 = charB1 - '0';
            }

            decimalValue = decimalValue * b1 + charB2; // Multiply the current decimalValue by the base (b1) and add the value of the current character
        }

        if (decimalValue == 0) { // If the decimalValue is 0, the result is '0'
            return "0";
        }

        while (decimalValue != 0) { // While the decimalValue is not 0
            int remainder = decimalValue % b2; // Calculate the remainder of decimalValue divided by the base (b2)
            output.insert(0, (char) (remainder < 10 ? '0' + remainder : 'A' + (remainder - 10))); // Add the corresponding digit in the new base (b2) to the StringBuilder (prepending it)
            decimalValue /= b2; // Divide the decimalValue by the base (b2) and update the decimalValue
        }

        return output.toString(); // Return the converted number as a String
    }
}