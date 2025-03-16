import java.util.Scanner;  // Import the Scanner class for input

public class Main {
    public static void main(String[] args) {
        int a, b, c, d;  // Declare four integer variables

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read two integer values from the standard input and store them in a and b
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate the product of a and b, and store it in c
        c = a * b;

        // Calculate the perimeter of a rectangle with sides a and b, and store it in d
        d = 2 * a + 2 * b;

        // Print the values of c and d to the standard output
        System.out.println(c + " " + d);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
