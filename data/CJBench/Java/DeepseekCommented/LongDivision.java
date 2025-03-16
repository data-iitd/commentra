import java.util.Scanner;

public final class Main {
    private Main() {
    }

    // This method takes two integers, dividend and divisor, and returns their division result.
    // It handles various edge cases, including division by zero and negative numbers.
    public static int divide(int dividend, int divisor) {
        long newDividend1 = dividend;
        long newDivisor1 = divisor;

        // Check for division by zero and handle it by throwing an ArithmeticException.
        if (divisor == 0) {
            throw new ArithmeticException("Division by zero");
        }

        // Handle negative numbers by converting them to positive.
        if (dividend < 0) {
            newDividend1 = newDividend1 * -1;
        }
        if (divisor < 0) {
            newDivisor1 = newDivisor1 * -1;
        }

        // If dividend is zero or dividend is less than divisor, return 0.
        if (dividend == 0 || newDividend1 < newDivisor1) {
            return 0;
        }

        // Use StringBuilder to build the result of the division.
        StringBuilder answer = new StringBuilder();
        String dividendString = "" + newDividend1;
        int lastIndex = 0;
        String remainder = "";

        // Loop through each digit of the dividend.
        for (int i = 0; i < dividendString.length(); i++) {
            String partV1 = remainder + dividendString.substring(lastIndex, i + 1);
            long part1 = Long.parseLong(partV1);

            // Check if the current part is greater than or equal to the divisor.
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

            // Update the remainder for the next iteration.
            remainder = part1 == 0 ? "" : String.valueOf(part1);
            lastIndex++;
        }

        // Handle the sign of the result based on the signs of the dividend and divisor.
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            try {
                return Integer.parseInt(answer.toString()) * (-1);
            } catch (NumberFormatException e) {
                return Integer.MIN_VALUE;
            }
        }

        // Convert the result to an integer and return it.
        try {
            return Integer.parseInt(answer.toString());
        } catch (NumberFormatException e) {
            return Integer.MAX_VALUE;
        }
    }

    // The main method is the entry point of the program.
    // It reads two integers from the user, calls the divide method, and prints the result.
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
