import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Declare three integer variables to store user input
    int a, b, c;
    
    // Read three integers from the standard input
    Scanner sc = new Scanner(System.in);
    a = sc.nextInt();
    b = sc.nextInt();
    c = sc.nextInt();

    // Check if the sum of a and b is greater than or equal to c
    if (a + b >= c){
      // If true, print "Yes"
      System.out.println("Yes");
    } else {
      // Otherwise, print "No"
      System.out.println("No");
    }
  }
}
