import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);  // Create a Scanner object to read input from the user
    int height = input.nextInt();  // Read the height from the user input
    int width = input.nextInt();  // Read the width from the user input
    String input_str = input.next();  // Read a string from the user

    // Print the top border of the output
    for(int i = 0; i < width + 2; i++) {
      System.out.print("#");
    }
    System.out.println();

    // Read and print each line of input with borders
    for(int i = 0; i < height; i++) {
      System.out.printf("#%s#\n", input_str);  // Print the string with borders
    }

    // Print the bottom border of the output
    for(int i = 0; i < width + 2; i++) {
      System.out.print("#");
    }
    System.out.println();
  }
}
