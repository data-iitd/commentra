
// Import the Scanner class to read input from the console
import java.util.Scanner;

// Class Rectangle is the entry point of the program
public class Rectangle {
  // Function main is the entry point of the program
  public static void main(String[] args) {
    // Create a Scanner object to read input from the console
    Scanner input = new Scanner(System.in);

    // Declare variables for height and width of the rectangle to be printed
    int height, width;
    // Declare a character array to store the input string
    char[] input_str = new char[width+1];
    // Initialize a counter variable 'i'
    int i;

    // Read the height and width of the rectangle from the user
    height = input.nextInt();
    width = input.nextInt();

    // Print the top border of the rectangle
    for(i = 0; i < width + 2; i++) {
      // Print '#' character for each iteration
      System.out.print("#");
    }
    System.out.println(); // Print newline character after the top border

    // Print the body of the rectangle
    for(i = 0; i < height; i++) {
      // Read a string from the user
      input.next(input_str);
      // Print the top and bottom border of each row with '#' character
      System.out.printf("#%s#\n", input_str);
    }

    // Print the bottom border of the rectangle
    for(i = 0; i < width + 2; i++) {
      // Print '#' character for each iteration
      System.out.print("#");
    }
    System.out.println(); // Print newline character after the bottom border
  }
}

