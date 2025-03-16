import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to convert a number from one base to another
    public static int convertBase(int sourceNumber, int sourceBase, int destBase) {
        // Validate that the source and destination bases are within the acceptable range
        if (sourceBase < 2 || sourceBase > 10 || destBase < 2 || destBase > 10) {
            throw new IllegalArgumentException("Bases must be between 2 and 10.");
        }
        // Convert the source number to decimal
        int decimalValue = toDecimal(sourceNumber, sourceBase);
        // Convert the decimal value to the destination base
        return fromDecimal(decimalValue, destBase);
    }

    // Helper method to convert a number from a specified base to decimal
    private static int toDecimal(int number, int base) {
        int decimalValue = 0; // Variable to hold the decimal value
        int multiplier = 1;   // Multiplier for the current base power
        // Loop until the number is reduced to zero
        while (number != 0) {
            // Add the current digit's contribution to the decimal value
            decimalValue += (number % 10) * multiplier;
            // Update the multiplier for the next digit
            multiplier *= base;
            // Remove the last digit from the number
            number /= 10;
        }
        return decimalValue; // Return the converted decimal value
    }

    // Helper method to convert a decimal number to a specified base
    private static int fromDecimal(int decimal, int base) {
        int result = 0; // Variable to hold the result in the new base
        int multiplier = 1; // Multiplier for the current base power
        // Loop until the decimal value is reduced to zero
        while (decimal != 0) {
            // Add the current digit's contribution to the result
            result += (decimal % base) * multiplier;
            // Update the multiplier for the next digit
            multiplier *= 10;
            // Remove the last digit from the decimal value
            decimal /= base;
        }
        return result; // Return the converted value in the new base
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner for user input
        // Read the source number, source base, and destination base from input
        int sourceNumber = scanner.nextInt();
        int sourceBase = scanner.nextInt();
        int destBase = scanner.nextInt();
        try {
            // Convert the number and print the result
            int result = convertBase(sourceNumber, sourceBase, destBase);
            System.out.println("Converted number: " + result);
        } catch (IllegalArgumentException e) {
            // Handle invalid base input by printing an error message
            System.out.println("Error: " + e.getMessage());
        } finally {
            // Close the scanner to free resources
            scanner.close();
        }
    }
}
