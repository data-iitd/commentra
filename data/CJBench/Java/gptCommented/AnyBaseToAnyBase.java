import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {}

    // Constants for minimum and maximum base values
    static final int MINIMUM_BASE = 2;
    static final int MAXIMUM_BASE = 36;

    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner in = new Scanner(System.in);
        
        // Read the number to be converted
        String n = in.next();
        
        // Read the source base and validate it
        int b1 = in.nextInt();
        while (b1 < MINIMUM_BASE || b1 > MAXIMUM_BASE) {
            System.out.println("Invalid base! Please enter again.");
            b1 = in.nextInt();
        }

        // Validate the number for the specified source base
        if (!validForBase(n, b1)) {
            System.out.println("The number is invalid for this base!");
            return; // Exit if the number is invalid
        }

        // Read the target base and validate it
        int b2 = in.nextInt();
        while (b2 < MINIMUM_BASE || b2 > MAXIMUM_BASE) {
            System.out.println("Invalid base! Please enter again.");
            b2 = in.nextInt();
        }

        // Convert the number from base b1 to base b2
        String result = base2base(n, b1, b2);
        
        // Output the converted number
        System.out.println("Converted number: " + result);
        
        // Close the scanner to prevent resource leaks
        in.close();
    }

    // Method to validate if the number is valid for the given base
    public static boolean validForBase(String n, int base) {
        // Define valid digits for bases up to 36
        char[] validDigits = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        };
        
        // Create an array of valid digits for the specified base
        char[] digitsForBase = Arrays.copyOfRange(validDigits, 0, base);
        
        // Use a HashSet for quick lookup of valid digits
        HashSet<Character> digitsList = new HashSet<>();
        for (char c : digitsForBase) {
            digitsList.add(c);
        }

        // Check if each character in the number is valid for the base
        for (char c : n.toUpperCase().toCharArray()) {
            if (!digitsList.contains(c)) {
                return false; // Return false if an invalid character is found
            }
        }
        return true; // Return true if all characters are valid
    }

    // Method to convert a number from base b1 to base b2
    public static String base2base(String n, int b1, int b2) {
        int decimalValue = 0; // Variable to hold the decimal value
        StringBuilder output = new StringBuilder(); // StringBuilder to build the output

        // Convert the number from base b1 to decimal
        for (char charB1 : n.toUpperCase().toCharArray()) {
            // Convert character to its integer value based on the base
            int charB2 = (charB1 >= 'A' && charB1 <= 'Z') ? 10 + (charB1 - 'A') : charB1 - '0';
            decimalValue = decimalValue * b1 + charB2; // Update decimal value
        }

        // Handle the case where the number is zero
        if (decimalValue == 0) {
            return "0"; // Return "0" if the decimal value is zero
        }

        // Convert the decimal value to the target base b2
        while (decimalValue != 0) {
            int remainder = decimalValue % b2; // Get the remainder
            // Convert remainder to the appropriate character and insert at the beginning
            output.insert(0, (char) (remainder < 10 ? '0' + remainder : 'A' + (remainder - 10)));
            decimalValue /= b2; // Update decimal value for the next iteration
        }
        return output.toString(); // Return the final converted number
    }
}
