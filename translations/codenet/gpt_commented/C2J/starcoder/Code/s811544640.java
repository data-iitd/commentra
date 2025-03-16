
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Declare three integer variables a, b, and c
    int a, b, c;

    // Read three integers from user input
    Scanner sc = new Scanner(System.in);
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();

    // Check if b is greater than the product of a and c
    if (b > a * c) {
      // If true, print the value of c
      System.out.println(c);
    } else {
      // If false, print the result of b divided by a
      System.out.println(b / a);
    }
  }
}

