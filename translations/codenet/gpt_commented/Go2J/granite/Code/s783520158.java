
import java.util.Scanner;

public class s783520158{
    public static void main(String[] args) {
        // Declare three integer variables to hold the input values
        int a, b, c;

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read three integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();

        // Check if the difference between the first two numbers is equal to the difference between the last two numbers
        if (b - a == c - b) {
            // If the differences are equal, print "YES"
            System.out.println("YES");
        } else {
            // If the differences are not equal, print "NO"
            System.out.println("NO");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
