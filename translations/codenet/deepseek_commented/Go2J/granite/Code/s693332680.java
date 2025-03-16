
import java.util.Scanner;

public class s693332680{
    public static void main(String[] args) {
        // Declare three integer variables x, a, and b to store input values.
        int x, a, b;

        // Create a Scanner object to read input from the standard input.
        Scanner scanner = new Scanner(System.in);

        // Read three integers from the standard input and assign them to x, a, and b.
        x = scanner.nextInt();
        a = scanner.nextInt();
        b = scanner.nextInt();

        // Use a switch statement to evaluate the condition b-a and execute the corresponding block of code.
        switch (true) {
            // If b-a is less than or equal to 0, print "delicious".
            case b - a <= 0:
                System.out.println("delicious");
                break;
            // If b-a is greater than 0 but less than or equal to x, print "safe".
            case b - a <= x:
                System.out.println("safe");
                break;
            // If b-a is greater than x, print "dangerous".
            default:
                System.out.println("dangerous");
                break;
        }

        // Close the Scanner object to release system resources.
        scanner.close();
    }
}
