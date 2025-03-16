
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
public final class Main {
    private Main() {} // Prevents instantiation
    static final int MINIMUM_BASE = 2; // Minimum valid base
    static final int MAXIMUM_BASE = 36; // Maximum valid base
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String n = in.next(); // Read the number as a string
        int b1 = in.nextInt(); // Read the first base
        while (b1 < MINIMUM_BASE || b1 > MAXIMUM_BASE) { // Validate the first base
            System.out.println("Invalid base! Please enter again.");
            b1 = in.nextInt();
        }
        if (!validForBase(n, b1)) { // Check if the number is valid for the first base
            System.out.println("The number is invalid for this base!");
            return;
        }
        int b2 = in.nextInt(); // Read the second base
        while (b2 < MINIMUM_BASE || b2 > MAXIMUM_BASE) { // Validate the second base
            System.out.println("Invalid base! Please enter again.");
            b2 = in.nextInt();
        }
        String result = base2base(n, b1, b2); // Convert the number to the second base
        System.out.println("Converted number: " + result); // Output the converted number
        in.close(); // Close the scanner
    }
    public static boolean validForBase(String n, int base) {
        char[] validDigits = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
            'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        };
        char[] digitsForBase = Arrays.copyOfRange(validDigits, 0, base);
        HashSet<Character> digitsList = new HashSet<>();
        for (char c : digitsForBase) {
            digitsList.add(c);
        }
        for (char c : n.toUpperCase().toCharArray()) {
            if (!digitsList.contains(c)) {
                return false;
            }
        }
        return true;
    }
    public static String base2base(String n, int b1, int b2) {
        int decimalValue = 0; // Initialize the decimal value
        StringBuilder output = new StringBuilder(); // To build the output string
        for (char charB1 : n.toUpperCase().toCharArray()) {
            int charB2 = (charB1 >= 'A' && charB1 <= 'Z') ? 10 + (charB1 - 'A') : charB1 - '0';
            decimalValue = decimalValue * b1 + charB2; // Convert to decimal
        }
        if (decimalValue == 0) { // Handle the case where the number is zero
            return "0";
        }
        while (decimalValue != 0) {
            int remainder = decimalValue % b2; // Get the remainder
            output.insert(0, (char) (remainder < 10 ? '0' + remainder : 'A' + (remainder - 10))); // Convert to target base
            decimalValue /= b2; // Update the decimal value
        }
        return output.toString(); // Return the converted number
    }
}