import java.util.Scanner; // Import the Scanner class for reading input

public class Main { // Define the public class Main which is the entry point of the program
  public static void main(String[] args) { // The main method is the entry point of the program
    Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input
    int r = scanner.nextInt(); // Read an integer input from the user
    System.out.println(r * r); // Print the square of the input integer
    scanner.close(); // Close the scanner object to free up resources
  }
}
