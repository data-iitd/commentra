import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize two integer variables, x and a
        int x, a;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read data from the standard input stream and store it into x and a
        x = scanner.nextInt();
        a = scanner.nextInt();

        // Check if x is greater than or equal to a
        int result = (x >= a) ? 1 : 0;

        // Multiply the result by 10
        result *= 10;

        // Print the result to the standard output stream
        System.out.println(result);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
