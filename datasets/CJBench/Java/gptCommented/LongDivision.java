import java.util.Scanner;

public final class Main {
    // Private constructor to prevent instantiation of the class
    private Main() {
    }

    // Method to perform division of two integers without using the division operator
    public static int divide(int dividend, int divisor) {
        // Convert dividend and divisor to long to handle overflow
        long newDividend1 = dividend;
        long newDivisor1 = divisor;

        // Check for division by zero and throw an exception if true
        if (divisor == 0) {
            throw new ArithmeticException("Division by zero");
        }

        // Convert dividend to positive if it's negative
        if (dividend < 0) {
            newDividend1 = newDividend1 * -1;
        }

        // Convert divisor to positive if it's negative
        if (divisor < 0) {
            newDivisor1 = newDivisor1 * -1;
        }

        // If dividend is zero or less than divisor, return 0
        if (dividend == 0 || newDividend1 < newDivisor1) {
            return 0;
        }

        // StringBuilder to build the quotient as a string
        StringBuilder answer = new StringBuilder();
        String dividendString = "" + newDividend1; // Convert dividend to string for processing
        int lastIndex = 0; // Track the last processed index in the dividend string
        String remainder = ""; // To hold the remainder during division

        // Loop through each digit of the dividend
        for (int i = 0; i < dividendString.length(); i++) {
            // Create the current part of the dividend to be divided
            String partV1 = remainder + dividendString.substring(lastIndex, i + 1);
            long part1 = Long.parseLong(partV1); // Convert the current part to long

            // If the current part is greater than or equal to the divisor
            if (part1 >= newDivisor1) {
                int quotient = 0; // Initialize quotient for this part
                // Subtract the divisor from the part until it's less than the divisor
                while (part1 >= newDivisor1) {
                    part1 = part1 - newDivisor1;
                    quotient++;
                }
                // Append the quotient to the answer
                answer.append(quotient);
            } else {
                // If the part is less than the divisor, append 0 to the answer
                answer.append(0);
            }

            // Update the remainder for the next iteration
            remainder = part1 == 0 ? "" : String.valueOf(part1);
            lastIndex++; // Move to the next index
        }

        // Adjust the sign of the result based on the original signs of dividend and divisor
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            try {
                // Return the negative of the computed quotient
                return Integer.parseInt(answer.toString()) * (-1);
            } catch (NumberFormatException e) {
                // Handle overflow by returning Integer.MIN_VALUE
                return Integer.MIN_VALUE;
            }
        }

        // Attempt to return the computed quotient as an integer
        try {
            return Integer.parseInt(answer.toString());
        } catch (NumberFormatException e) {
            // Handle overflow by returning Integer.MAX_VALUE
            return Integer.MAX_VALUE;
        }
    }

    // Main method to execute the program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a scanner to read input
        int dividend = scanner.nextInt(); // Read the dividend from input
        int divisor = scanner.nextInt(); // Read the divisor from input

        // Try to perform the division and catch any arithmetic exceptions
        try {
            int result = divide(dividend, divisor); // Call the divide method
            System.out.println("Result: " + result); // Print the result
        } catch (ArithmeticException e) {
            // Print error message if division by zero occurs
            System.out.println("Error: " + e.getMessage());
        } finally {
            // Close the scanner resource
            scanner.close();
        }
    }
}
