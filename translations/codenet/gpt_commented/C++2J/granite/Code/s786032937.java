
import java.util.Scanner;  // Import the Scanner class for user input

public class s786032937{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);  // Create a Scanner object to read user input
        int n = scanner.nextInt();  // Read the number of sides of the polygon from user input

        // Calculate the sum of the interior angles of a polygon with 'n' sides
        // The formula for the sum of interior angles is (n - 2) * 180
        int sumOfInteriorAngles = (n - 2) * 180;  // Calculate the sum of interior angles

        System.out.println(sumOfInteriorAngles);  // Output the calculated sum of interior angles

        scanner.close();  // Close the Scanner object to release system resources
    }
}
