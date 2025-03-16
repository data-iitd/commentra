// Import the Scanner class for reading input
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable named x of type int
        int x;

        // Create a Scanner object to read input
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from the standard input and assign it to the variable x
        x = scanner.nextInt();

        // Print the result of x cubed (x*x*x)
        System.out.println(x * x * x);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
