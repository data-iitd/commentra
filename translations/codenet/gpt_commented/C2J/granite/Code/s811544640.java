
import java.util.Scanner;

public class s811544640{
  public static void main(String[] args) {
    // Declare three integer variables a, b, and c
    Scanner scanner = new Scanner(System.in);
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    int c = scanner.nextInt();

    // Check if b is greater than the product of a and c
    if (b > a * c) {
      // If true, print the value of c
      System.out.println(c);
    } else {
      // If false, print the result of b divided by a
      System.out.println(b / a);
    }

    // Return 0 to indicate successful execution of the program
    System.out.println(0);
  }
}
