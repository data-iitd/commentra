
import java.util.Scanner;

public class s459892612{
  public static void main(String[] args) {
    // Declare three integer variables to store user input
    int a, b, c;
    
    // Create a Scanner object to read input from the standard input
    Scanner scanner = new Scanner(System.in);
    
    // Read three integers from the standard input
    a = scanner.nextInt();
    b = scanner.nextInt();
    c = scanner.nextInt();
    
    // Check if the sum of a and b is greater than or equal to c
    if (a + b >= c){
      // If true, print "Yes"
      System.out.println("Yes");
    } else {
      // Otherwise, print "No"
      System.out.println("No");
    }
    
    // Close the Scanner object to release system resources
    scanner.close();
  }
}
