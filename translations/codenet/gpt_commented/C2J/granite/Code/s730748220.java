
import java.util.Scanner; // Import Scanner class from java.util package

public class s730748220{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user
        int n = scanner.nextInt(); // Read an integer input from the user and store it in variable n
        
        // Calculate and print the result based on the input n
        // The expression (24 + (24 - n)) simplifies to (48 - n)
        System.out.println(24 + (24 - n));
        
        scanner.close(); // Close the Scanner object to release system resources
    }
}
// END-OF-CODE