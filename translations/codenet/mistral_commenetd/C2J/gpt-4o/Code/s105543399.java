import java.util.Scanner; // We import the Scanner class for input

public class Main { // We define the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        long n, a, m, M, c; // We declare variables of type long for numbers that can be very large
        c = 0; // We initialize the variable 'c' to zero
        m = Long.MAX_VALUE; // We initialize 'm' to a very large positive number
        M = Long.MIN_VALUE; // We initialize 'M' to a very large negative number

        Scanner scanner = new Scanner(System.in); // We create a Scanner object for input

        // We read the first number 'n' from the standard input
        n = scanner.nextLong();

        for (long i = 1; i <= n; i++) { // We start a for loop that iterates 'n' times
            // We read the current number 'a' from the standard input
            a = scanner.nextLong();

            // If the current number 'a' is greater than the current maximum number 'M', we update 'M' with 'a'
            if (a > M) {
                M = a;
            }

            // If the current number 'a' is smaller than the current minimum number 'm', we update 'm' with 'a'
            if (a < m) {
                m = a;
            }

            // We add the current number 'a' to the variable 'c'
            c += a;
        }

        // We print the minimum number 'm', the maximum number 'M', and the sum 'c' to the standard output
        System.out.printf("%d %d %d\n", m, M, c);

        // We close the scanner
        scanner.close();
    } // The main method ends
} // The Main class ends
// <END-OF-CODE>
