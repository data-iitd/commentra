import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation
    private Main() {
    }

    // Main method to convert a number from a source base to a destination base
    public static int convertBase(int sourceNumber, int sourceBase, int destBase) {
        // Check if the source and destination bases are within the valid range (2 to 10)
        if (sourceBase < 2 || sourceBase > 10 || destBase < 2 || destBase > 10) {
            throw new IllegalArgumentException("Bases must be between 2 and 10.");
        }

        // Convert the source number to its decimal (base 10) equivalent
        int decimalValue = toDecimal(sourceNumber, sourceBase);

        // Convert the decimal value to the destination base
        return fromDecimal(decimalValue, destBase);
    }

    // Private method to convert a number from a given base to its decimal (base 10) equivalent
    private static int toDecimal(int number, int base) {
        int decimalValue = 0;
        int multiplier = 1;
        while (number != 0) {
            decimalValue += (number % 10) * multiplier;
            multiplier *= base;
            number /= 10;
        }
        return decimalValue;
    }

    // Private method to convert a decimal number to a number in a given base
    private static int fromDecimal(int decimal, int base) {
        int result = 0;
        int multiplier = 1;
        while (decimal != 0) {
            result += (decimal % base) * multiplier;
            multiplier *= 10;
            decimal /= base;
        }
        return result;
    }

    // Main method to run the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int sourceNumber = scanner.nextInt();
        int sourceBase = scanner.nextInt();
        int destBase = scanner.nextInt();
        try {
            int result = convertBase(sourceNumber, sourceBase, destBase);
            System.out.println("Converted number: " + result);
        } catch (IllegalArgumentException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
