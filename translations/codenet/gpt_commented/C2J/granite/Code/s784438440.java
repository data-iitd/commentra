
import java.util.Scanner;

public class s784438440{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare two integer variables a and b
        int a, b;

        // Read two integers from user input
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Calculate and print the result of the expression
        // The expression computes the number of complete groups of (a-1) that can fit into (b-1) + (a-2)
        System.out.println(((b - 1) + (a - 2)) / (a - 1));

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
