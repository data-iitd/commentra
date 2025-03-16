import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables
        long a, b, x;

        // Create a Scanner object to read input values
        Scanner scanner = new Scanner(System.in);

        // Read input values from standard input
        a = scanner.nextLong();
        b = scanner.nextLong();
        x = scanner.nextLong();

        // Calculate the difference between the number of complete x-blocks in b and a
        long s = (b / x - a / x);

        // If a is a multiple of x, then the last x-block in a is complete, so add 1 to the result
        if (a % x == 0) s++;

        // Print the result to standard output
        System.out.println(s);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
