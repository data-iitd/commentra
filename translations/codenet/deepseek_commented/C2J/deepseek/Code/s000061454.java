public class Main {
    public static void main(String[] args) {
        // Variable declarations
        int a, b, n; // Input values and loop counters
        int sum; // To store the sum of the digits
        int i, j; // Loop counters

        // Create a Scanner object to read input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Infinite loop
        while (true) {
            // Read three integers from standard input
            if (!scanner.hasNextInt())
                break; // Break if input reading fails
            a = scanner.nextInt();
            b = scanner.nextInt();
            n = scanner.nextInt();

            // Reduce 'a' to its remainder when divided by 'b'
            a -= a / b * b;

            // Initialize sum to zero
            sum = 0;

            // Outer loop runs 'n' times
            for (i = 1; i <= n; i++) {
                // Multiply 'a' by 10 to shift the decimal point
                a *= 10;

                // Inner loop iterates from 9 down to 0
                for (j = 9; j >= 0; j--) {
                    // Find the largest digit 'j' such that 'b*j' is less than or equal to 'a'
                    if (b * j <= a)
                        break;
                }

                // Subtract 'b*j' from 'a' and add 'j' to the sum
                a -= b * j;
                sum += j;
            }

            // Output the sum of the digits
            System.out.println(sum);
        }

        // Close the scanner
        scanner.close();
    }
}
