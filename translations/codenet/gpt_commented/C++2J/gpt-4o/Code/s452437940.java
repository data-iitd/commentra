import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the input values
        long a, b, x;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read three long integers from standard input
        a = scanner.nextLong();
        b = scanner.nextLong();
        x = scanner.nextLong();

        // Calculate the number of multiples of x in the range [a, b]
        long s = (b / x - a / x);

        // If 'a' is a multiple of 'x', include it in the count
        if (a % x == 0) s++;

        // Print the result: the total count of multiples of x in the range
        System.out.println(s);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
