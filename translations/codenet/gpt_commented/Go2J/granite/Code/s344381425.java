
import java.util.Scanner;

public class s344381425{
    public static void main(String[] args) {
        // Declare three integer variables to hold the input values
        int a, b, c;
        
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Read three integers from standard input
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        
        // Check if the integers are in strictly increasing order
        if (a < b && b < c) {
            // If they are in increasing order, print "Yes"
            System.out.println("Yes");
        } else {
            // If they are not in increasing order, print "No"
            System.out.println("No");
        }
        
        // Close the Scanner object to release system resources
        scanner.close();
        
        // End of the main method
        return;
    }
}
