
import java.util.Scanner;

public class s860117222{
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare three long long integer variables to hold input values
        long long a = scanner.nextLong();
        long long b = scanner.nextLong();
        long long c = scanner.nextLong();

        // Calculate the value of d as the difference between c and the sum of a and b
        long long d = c - a - b;

        // Check if d is positive and if 4 times the product of a and b is less than d squared
        if ((d > 0) && ((4 * a * b) < d * d)) {
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
