import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the utility class
    private Main() {
    }

    // Method to convert an octal number to its binary equivalent
    public static long convertMain(int octalNumber) {
        long binaryNumber = 0; // Variable to hold the resulting binary number
        int digitPosition = 1; // Variable to track the position of the binary digit

        // Loop until all digits of the octal number are processed
        while (octalNumber != 0) {
            // Extract the last digit of the octal number
            int octalDigit = octalNumber % 10;
            // Convert the octal digit to its binary equivalent
            long binaryDigit = convertOctalDigitToBinary(octalDigit);
            // Add the binary digit to the final binary number at the correct position
            binaryNumber += binaryDigit * digitPosition;
            // Remove the last digit from the octal number
            octalNumber /= 10;
            // Update the position for the next binary digit (each octal digit corresponds to 3 binary digits)
            digitPosition *= 1000;
        }
        return binaryNumber; // Return the final binary number
    }

    // Method to convert a single octal digit to its binary equivalent
    public static long convertOctalDigitToBinary(int octalDigit) {
        long binaryDigit = 0; // Variable to hold the resulting binary digit
        int binaryMultiplier = 1; // Variable to track the position of the binary digit

        // Loop until all bits of the octal digit are processed
        while (octalDigit != 0) {
            // Get the remainder when dividing by 2 (to get the binary digit)
            int octalDigitRemainder = octalDigit % 2;
            // Add the binary digit to the result at the correct position
            binaryDigit += octalDigitRemainder * binaryMultiplier;
            // Remove the last bit from the octal digit
            octalDigit /= 2;
            // Update the position for the next binary digit
            binaryMultiplier *= 10;
        }
        return binaryDigit; // Return the binary equivalent of the octal digit
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object for input
        int octalNumber = scanner.nextInt(); // Read the octal number from user input
        long binaryNumber = convertMain(octalNumber); // Convert the octal number to binary
        // Print the binary equivalent
        System.out.println("Binary equivalent: " + binaryNumber);
        scanner.close(); // Close the scanner to free resources
    }
}
