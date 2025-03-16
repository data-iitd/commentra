
import java.util.Scanner;

public class s459892612{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare three integer variables to hold input values
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();

        // Check if the sum of a and b is greater than or equal to c
        if (a + b >= c) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }

        // Close the Scanner object to release system resources
        scanner.close();
    }
}
