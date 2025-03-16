
import java.util.Scanner; // Import the Scanner class for reading user input

public class Main {
  public static void main(String... args) {
    Scanner scan = new Scanner(System.in); // Create a new Scanner object to read user input

    // Read an integer value `r` from the user input
    int r = scan.nextInt();

    // Calculate the square of the integer value `r`
    int res = (int)Math.pow(r,2);

    // Print the square of the integer value `r` to the standard output stream
    System.out.println(res);
  }
}