
import java.util.Scanner;

public final class Main {
    private Main() {
        // Private constructor to prevent instantiation of the class from outside
    }

    public static int divide(int dividend, int divisor) {
        long newDividend1 = dividend; // Assign the dividend to a long variable for easier manipulation
        long newDivisor1 = divisor; // Assign the divisor to a long variable for easier manipulation

        if (divisor == 0) { // Check if the divisor is zero
            throw new ArithmeticException("Division by zero"); // Throw an exception if the divisor is zero
        }

        if (dividend < 0) { // Check if the dividend is negative
            newDividend1 = newDividend1 * -1; // Multiply the dividend by -1 to make it positive
        }

        if (divisor < 0) { // Check if the divisor is negative
            newDivisor1 = newDivisor1 * -1; // Multiply the divisor by -1 to make it positive
        }

        if (dividend == 0 || newDividend1 < newDivisor1) { // Check if the dividend is zero or the quotient is less than zero
            return 0; // Return zero if the dividend is zero or the quotient is less than zero
        }

        StringBuilder answer = new StringBuilder(); // Create a StringBuilder object to store the quotient digits
        String dividendString = "" + newDividend1; // Convert the long dividend to a String
        int lastIndex = 0; // Initialize the last index of the String to 0
        String remainder = ""; // Initialize the remainder as an empty String

        for (int i = 0; i < dividendString.length(); i++) { // Iterate through each digit of the dividend String
            String partV1 = remainder + dividendString.substring(lastIndex, i + 1); // Concatenate the remainder and the current digit to form a part of the dividend
            long part1 = Long.parseLong(partV1); // Parse the part of the dividend as a long number

            if (part1 >= newDivisor1) { // Check if the current part is greater than or equal to the divisor
                int quotient = 0; // Initialize the quotient to zero
                while (part1 >= newDivisor1) { // Subtract the divisor from the current part until the current part is less than the divisor
                    part1 = part1 - newDivisor1;
                    quotient++; // Increment the quotient by 1 for each subtraction
                }
                answer.append(quotient); // Append the quotient to the StringBuilder
            } else { // If the current part is less than the divisor, append a zero to the StringBuilder
                answer.append(0);
            }

            remainder = part1 == 0 ? "" : String.valueOf(part1); // Update the remainder for the next iteration
            lastIndex++; // Increment the last index of the String
        }

        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) { // Check if the dividend and divisor have opposite signs
            try {
                return Integer.parseInt(answer.toString()) * (-1); // Multiply the quotient by -1 and return the result if the signs are opposite
            } catch (NumberFormatException e) {
                return Integer.MIN_VALUE; // Return the minimum integer value if there's an error parsing the quotient
            }
        }

        try {
            return Integer.parseInt(answer.toString()); // Parse the quotient as an integer and return the result
        } catch (NumberFormatException e) {
            return Integer.MAX_VALUE; // Return the maximum integer value if there's an error parsing the quotient
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the console
        int dividend = scanner.nextInt(); // Read the dividend from the console as an integer
        int divisor = scanner.nextInt(); // Read the divisor from the console as an integer

        try {
            int result = divide(dividend, divisor); // Call the divide method to calculate the quotient
            System.out.println("Result: " + result); // Print the quotient to the console
        } catch (ArithmeticException e) {
            System.out.println("Error: " + e.getMessage()); // Print the error message to the console if there's an error
        } finally {
            scanner.close(); // Close the Scanner object to release the system resources
        }
    }
}