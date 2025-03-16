// Step 1: Include the standard input/output library.
import java.util.Scanner;

// Step 2: Define the main function.
public class Main {
  public static void main(String[] args) {
    // Step 3: Declare integer variables a, b, c, x, y.
    int a, b, c, x, y;

    // Step 4: Read values for a, b, c, x, y from the user.
    Scanner sc = new Scanner(System.in);
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();
    x = sc.nextInt();
    y = sc.nextInt();

    // Step 5: Double the value of c.
    c *= 2;

    // Step 6: Check if the sum of a and b is less than or equal to c.
    if (a + b <= c) {
      // Step 7: If true, print the product of a and x plus the product of b and y.
      System.out.println(a * x + b * y);
    } else {
      // Step 8: If false, start the else block.
      if (x <= y) {
        // Step 9: Check if x is less than or equal to y.
        if (b <= c) {
          // Step 10: Check if b is less than or equal to c.
          System.out.println(c * x + (y - x) * b);
        } else {
          // Step 12: If false, start the else block.
          System.out.println(c * y);
        }
      } else {
        // Step 14: If x is greater than y, start the else block.
        if (a <= c) {
          // Step 15: Check if a is less than or equal to c.
          System.out.println(c * y + (x - y) * a);
        } else {
          // Step 17: If false, start the else block.
          System.out.println(c * x);
        }
      }
    }
  }
}

