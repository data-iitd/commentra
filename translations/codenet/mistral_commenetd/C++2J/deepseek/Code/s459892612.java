import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int a, b, c; // Declare and initialize three integer variables

    // Read the values of a, b, and c from the standard input using scanner
    a = scanner.nextInt();
    b = scanner.nextInt();
    c = scanner.nextInt();

    if (a + b >= c){ // Check if the sum of a and b is greater than or equal to c
      System.out.println("Yes"); // If the condition is true, print the string "Yes" to the standard output
    } else {
      System.out.println("No"); // If the condition is false, print the string "No" to the standard output
    }
  }
}
