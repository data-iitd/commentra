
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    // Declare three integer variables 'a', 'b', and 'c'
    int a, b, c;

    // Read three integers from the standard input using 'Scanner' class
    Scanner sc = new Scanner(System.in);
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();

    // Check if the condition 'b > a * c' is true
    if (b > a * c) {
      // If the condition is true, print the value of 'c'
      System.out.println(c);
    } else {
      // If the condition is false, calculate the integer division of 'b' by 'a'
      // and print the result
      System.out.println(b / a);
    }
  }
}

