
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int height = sc.nextInt();
    int width = sc.nextInt();
    char[] input_str = new char[width + 1];

    // Print the top border of the output
    for (int i = 0; i < width + 2; i++) {
      System.out.print("#");
    }
    System.out.println();

    // Read and print each line of input with borders
    for (int i = 0; i < height; i++) {
      sc.nextLine();
      sc.nextLine().getChars(0, width, input_str, 0);
      System.out.print("#");
      System.out.print(input_str);
      System.out.println("#");
    }

    // Print the bottom border of the output
    for (int i = 0; i < width + 2; i++) {
      System.out.print("#");
    }
    System.out.println();
  }
}

