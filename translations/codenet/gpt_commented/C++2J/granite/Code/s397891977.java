
import java.util.Scanner; // Import the Scanner class for console I/O

public class s397891977{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in); // Create a Scanner object to read user input

    int r = scanner.nextInt(); // Read the radius value from user input

    // Calculate the area of the circle using the formula πr²
    // Here, we are using the simplified version by omitting π for demonstration
    System.out.println(r * r); // Output the calculated area (r squared)

    scanner.close(); // Close the Scanner object to release system resources
  }
}
