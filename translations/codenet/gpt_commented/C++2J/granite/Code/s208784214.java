
import java.util.Scanner; // Import the Scanner class for input operations

public class s208784214{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user

        int N = scanner.nextInt(); // Read the first integer from standard input
        int A = scanner.nextInt(); // Read the second integer from standard input

        // Check if the remainder of N divided by 500 is less than or equal to A
        // If true, print "Yes"; otherwise, print "No"
        System.out.println(N % 500 <= A? "Yes" : "No");

        scanner.close(); // Close the Scanner object to release system resources
    }
}
