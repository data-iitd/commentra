
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class
    }

    public static long convertMain(int octalNumber) {
        long binaryNumber = 0; // Initialize binaryNumber to 0
        int digitPosition = 1; // Initialize digitPosition to 1

        // Convert octal number to binary number
        while (octalNumber != 0) {
            int octalDigit = octalNumber % 10; // Get the last digit of the octal number
            long binaryDigit = convertOctalDigitToBinary(octalDigit); // Convert the octal digit to binary digit
            binaryNumber += binaryDigit * digitPosition; // Add the binary digit to the binary number with its weight
            octalNumber /= 10; // Remove the last digit from the octal number
            digitPosition *= 1000; // Multiply the weight of the next digit by 1000
        }

        return binaryNumber; // Return the binary number
    }

    public static long convertOctalDigitToBinary(int octalDigit) {
        long binaryDigit = 0; // Initialize binaryDigit to 0
        int binaryMultiplier = 1; // Initialize binaryMultiplier to 1

        // Convert an octal digit to its binary equivalent
        while (octalDigit != 0) {
            int octalDigitRemainder = octalDigit % 2; // Get the last bit of the octal digit
            binaryDigit += octalDigitRemainder * binaryMultiplier; // Add the bit to the binary digit with its weight
            octalDigit /= 2; // Remove the last bit from the octal digit
            binaryMultiplier *= 10; // Multiply the weight of the next bit by 10
        }

        return binaryDigit; // Return the binary digit
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console

        // Read an octal number from the console and convert it to binary number
        int octalNumber = scanner.nextInt();
        long binaryNumber = convertMain(octalNumber);

        // Print the binary number to the console
        System.out.println("Binary equivalent: " + binaryNumber);

        scanner.close(); // Close the Scanner object
    }
}