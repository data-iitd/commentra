public class Main {
    public static int walkOnMultiplicationTable(int num) {
        // Initialize the variable `div` to 0.
        // `div` will store the largest divisor of `num` that is less than `sqrt(num)`.
        int div = 0;

        // Start the loop from the integer value of the square root of `num` down to 2.
        for (int i = (int) Math.sqrt(num); i > 1; i--) {
            // Check if `num` is divisible by the current value of `i`.
            if (num % i == 0) {
                // If `num` is divisible by `i`, set `div` to `i` and break out of the loop.
                div = i;
                break;
            }
        }

        // Check if `div` is still 0, which means no divisor was found.
        if (div == 0) {
            // If no divisor was found, return `num - 1`.
            return num - 1;
        }

        // Otherwise, return the sum of the divisor and the quotient of `num` divided by the divisor, minus 2.
        return div + num / div - 2;
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int a = scanner.nextInt();
        System.out.println(walkOnMultiplicationTable(a));
    }
}
