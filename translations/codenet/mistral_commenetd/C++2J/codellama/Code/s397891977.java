
import java.util.Scanner; // Import the Scanner class for input/output operations

public class Main { // The Main class is the entry point of the program
  public static void main(String[] args) { // The main method is the entry point of the program
    Scanner scanner = new Scanner(System.in); // Create a new Scanner object for input operations
    int r = scanner.nextInt(); // Read the value of "r" from the standard input using the nextInt() method
    System.out.println(r * r); // Output the square of "r" to the standard output using the println() method
    scanner.close(); // Close the Scanner object
  }
}

