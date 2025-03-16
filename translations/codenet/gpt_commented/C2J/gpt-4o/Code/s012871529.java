import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare two integer variables to hold the input values
        int a, b;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read two integers from the user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate and print the product of a and b, and the perimeter of a rectangle with sides a and b
        System.out.println(a * b + " " + (2 * (a + b)));

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
