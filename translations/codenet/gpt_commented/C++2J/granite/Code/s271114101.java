
import java.util.Scanner; // Import the Scanner class from the java.util package for input operations

public class s271114101{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user

        int a = scanner.nextInt(); // Read the first integer from the user
        int b = scanner.nextInt(); // Read the second integer from the user
        int c = scanner.nextInt(); // Read the third integer from the user

        // Check if any two of the three numbers sum up to the third number
        // If a + b equals c, or b + c equals a, or a + c equals b, print "Yes"
        // Otherwise, print "No"
        System.out.println((a + b == c || b + c == a || a + c == b)? "Yes" : "No");

        scanner.close(); // Close the Scanner object to release system resources
    }
}
