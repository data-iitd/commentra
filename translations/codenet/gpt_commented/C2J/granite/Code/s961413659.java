
import java.util.Scanner;

public class s961413659{
    public static void main(String[] args) {
        // Create a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Declare two integer variables to hold the input values
        int a, b;

        // Read two integer values from user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // If the first input value is 1, set it to 14
        if (a == 1)
            a = 14;

        // If the second input value is 1, set it to 14
        if (b == 1)
            b = 14;

        // Compare the two values and print the result
        if (a < b)
            // If 'a' is less than 'b', print "Bob"
            System.out.println("Bob");
        else if (a > b)
            // If 'a' is greater than 'b', print "Alice"
            System.out.println("Alice");
        else
            // If 'a' is equal to 'b', print "Draw"
            System.out.println("Draw");

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
