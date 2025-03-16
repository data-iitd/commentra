
import java.util.*; // Import the Scanner and other classes from the Java standard library

public class Main { // Define the main class
  public static void main(String[] args) { // Define the main function
    Scanner input = new Scanner(System.in); // Create a Scanner object to read from the standard input

    int r = input.nextInt(); // Read a value of type int from the standard input and store it in the variable "r"

    System.out.println(r * r); // Output the square of "r" to the standard output

    input.close(); // Close the Scanner object
  }
}

