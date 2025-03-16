
import java.util.Scanner;

public class s423495369{
  public static void main(String[] args) {
    // Declare three integer variables A, B, and C
    Scanner scanner = new Scanner(System.in);
    int A = scanner.nextInt();
    int B = scanner.nextInt();
    int C = scanner.nextInt();

    // Check if C is between A and B (A < C < B)
    if (A < C && C < B) {
      // If true, print "Yes"
      System.out.println("Yes");
    } 
    // Check if C is between B and A (A > C > B)
    else if (A > C && C > B) {
      // If true, print "Yes"
      System.out.println("Yes");
    } 
    // If neither condition is met, print "No"
    else {
      System.out.println("No");
    }
  }
}
