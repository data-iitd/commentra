//        Given two integers dividend and divisor, divide two integers without using multiplication,
//        division, and mod operator.
//
//        The integer division should truncate toward zero, which means losing its fractional part.
//        For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2. My
//        method used Long Division, here is the source
//        "https://en.wikipedia.org/wiki/Long_division"

import java.util.Scanner;

/**
 * Perform division of two integers without using multiplication, division, and mod operator.
 */
public final class LongDivision {
    private LongDivision() {
    }

    /**
     * Performs division of two integers using the long division algorithm.
     * 
     * @param dividend The number to be divided.
     * @param divisor  The number by which the dividend is divided.
     * @return The quotient after division.
     * @throws ArithmeticException If the divisor is zero.
     */
    public static int divide(int dividend, int divisor) {
        long newDividend1 = dividend;
        long newDivisor1 = divisor;

        // Check for division by zero
        if (divisor == 0) {
            throw new ArithmeticException("Division by zero");
        }
        // Convert both dividend and divisor to positive for simplicity
        if (dividend < 0) {
            newDividend1 = newDividend1 * -1;
        }
        if (divisor < 0) {
            newDivisor1 = newDivisor1 * -1;
        }

        // If dividend is 0 or smaller than divisor, return 0
        if (dividend == 0 || newDividend1 < newDivisor1) {
            return 0;
        }

        // To store the result as a string during long division
        StringBuilder answer = new StringBuilder();

        // Convert dividend to a string for digit-by-digit processing
        String dividendString = "" + newDividend1;
        int lastIndex = 0;

        String remainder = "";

        // Iterate through each digit of the dividend string
        for (int i = 0; i < dividendString.length(); i++) {
            // Extract the current part of the dividend
            String partV1 = remainder + dividendString.substring(lastIndex, i + 1);
            long part1 = Long.parseLong(partV1);
            if (part1 >= newDivisor1) {
                int quotient = 0;
                while (part1 >= newDivisor1) {
                    part1 = part1 - newDivisor1;
                    quotient++;
                }
                answer.append(quotient);
            } else {
                answer.append(0);
            }
            remainder = part1 == 0 ? "" : String.valueOf(part1);
            lastIndex++;
        }

        // Handle negative results based on the original signs of the dividend and divisor
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            try {
                return Integer.parseInt(answer.toString()) * (-1);
            } catch (NumberFormatException e) {
                return Integer.MIN_VALUE;
            }
        }
        // Return the result as an integer
        try {
            return Integer.parseInt(answer.toString());
        } catch (NumberFormatException e) {
            return Integer.MAX_VALUE;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int dividend = scanner.nextInt();

        int divisor = scanner.nextInt();

        try {
            int result = divide(dividend, divisor);
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}
