// Package declaration
import java.util.Scanner;

// Class declaration
public class Main {
    // Main method
    public static void main(String[] args) {
        // Variable declaration
        int a, b, h;

        // Creating a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Reading input values
        a = scanner.nextInt();
        b = scanner.nextInt();
        h = scanner.nextInt();

        // Calculating the result
        int result = (a + b) * h / 2;

        // Printing the result
        System.out.println(result);

        // Closing the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
