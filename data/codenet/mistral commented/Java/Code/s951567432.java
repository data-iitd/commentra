
import java.util.Scanner; // Import the Scanner class for user input

public class Main {
  public static void main(String[] args) {
    // Initialize a Scanner object to read user input
    Scanner scanner = new Scanner(System.in);

    // Read an integer value from the user and assign it to the count variable
    int count = scanner.nextInt();

    int total = 0; // Initialize the total variable with an initial value of 0

    // Use a for loop to iterate from 1 to count and add each index to the total variable
    for (int ix = 1; ix <= count; ix++) {
      total += ix;
    }

    // Print the total value to the standard output
    System.out.println(total);

    // Close the Scanner object to release system resources
    scanner.close();
  }
}