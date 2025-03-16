
import java.util.Scanner; // Import Scanner for input from the user

public class s659042676{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user

        int a = scanner.nextInt(); // Read the first integer value from the user
        int b = scanner.nextInt(); // Read the second integer value from the user

        // Calculate and output the result of the expression (6 - a - b)
        // This assumes that a and b are part of a game or problem where their sum should not exceed 6
        System.out.println(6 - a - b);

        scanner.close(); // Close the Scanner object to release system resources
    }
}
