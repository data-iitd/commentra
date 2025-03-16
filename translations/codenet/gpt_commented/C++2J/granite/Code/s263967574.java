
import java.util.Scanner; // Import the Scanner class from the java.util package

public class s263967574{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Create a Scanner object to read user input
        int x = scanner.nextInt(); // Read an integer value from the user and store it in x

        // Check if the input value x is greater than or equal to 1200
        if (x >= 1200) 
            System.out.println("ARC"); // If true, output "ARC"
        else 
            System.out.println("ABC"); // If false, output "ABC"
        
        scanner.close(); // Close the Scanner object to release system resources
    }
}
