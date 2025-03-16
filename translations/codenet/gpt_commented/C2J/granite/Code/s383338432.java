
import java.util.Scanner;

public class s383338432{
  public static void main(String[] args) {
    // Declare variables for height and width of the input, and a loop counter
    int height, width, i;

    // Create a Scanner object to read user input
    Scanner scanner = new Scanner(System.in);

    // Read the height and width from user input
    height = scanner.nextInt();
    width = scanner.nextInt();

    // Declare a character array to hold the input strings, with an extra space for the null terminator
    char[] input_str = new char[width + 1];

    // Print the top border of the box, consisting of '#' characters
    for(i = 0; i < width + 2; i++) {
      System.out.print("#");
    }
    System.out.println();

    // Read each line of input and print it with '#' borders
    for(i = 0; i < height; i++) {
      // Read a string from user input
      scanner.nextLine(); // Consume the newline character after reading the previous line
      scanner.next(input_str);
      // Print the string with '#' on both sides
      System.out.printf("#%s#%n", new String(input_str));
    }

    // Print the bottom border of the box, consisting of '#' characters
    for(i = 0; i < width + 2; i++) {
      System.out.print("#");
    }
    System.out.println();

    // Close the Scanner object to release system resources
    scanner.close();
  }
}
