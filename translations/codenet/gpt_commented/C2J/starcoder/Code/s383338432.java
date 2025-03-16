import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Declare variables for height and width of the input, and a loop counter
    int height, width, i;

    // Read the height and width from user input
    Scanner in = new Scanner(System.in);
    height = in.nextInt();
    width = in.nextInt();

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
      in.next(input_str);
      // Print the string with '#' on both sides
      System.out.printf("#%s#\n", input_str);
    }

    // Print the bottom border of the box, consisting of '#' characters
    for(i = 0; i < width + 2; i++) {
      System.out.print("#");
    }
    System.out.println();
  }
}
