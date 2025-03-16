import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    // Declare three integer variables 'a', 'b', and 'c'
    int a, b, c;

    // Read three integers from the standard input using scanner.nextInt()
    a = scanner.nextInt();
    b = scanner.nextInt();
    c = scanner.nextInt();

    // Check if the condition 'b > a * c' is true
    if (b > a * c) {
      // If the condition is true, print the value of 'c'
      System.out.println(c);
    } else {
      // If the condition is false, calculate the integer division of 'b' by 'a'
      // and print the result
      System.out.println(b / a);
    }

    // Close the scanner to free up resources
    scanner.close();
  }
}
