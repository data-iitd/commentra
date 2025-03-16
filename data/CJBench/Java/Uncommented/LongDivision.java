
import java.util.Scanner;
public final class LongDivision {
    private LongDivision() {
    }
    public static int divide(int dividend, int divisor) {
        long newDividend1 = dividend;
        long newDivisor1 = divisor;
        if (divisor == 0) {
            throw new ArithmeticException("Division by zero");
        }
        if (dividend < 0) {
            newDividend1 = newDividend1 * -1;
        }
        if (divisor < 0) {
            newDivisor1 = newDivisor1 * -1;
        }
        if (dividend == 0 || newDividend1 < newDivisor1) {
            return 0;
        }
        StringBuilder answer = new StringBuilder();
        String dividendString = "" + newDividend1;
        int lastIndex = 0;
        String remainder = "";
        for (int i = 0; i < dividendString.length(); i++) {
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
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            try {
                return Integer.parseInt(answer.toString()) * (-1);
            } catch (NumberFormatException e) {
                return Integer.MIN_VALUE;
            }
        }
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
