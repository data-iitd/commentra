import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read an integer input from the user
    int n = sc.nextInt();
    
    // Check if the integer n, when divided by 10 and then by 111, results in 0
    if ((n / 10) % 111 == 0) {
      // If true, print "Yes"
      System.out.println("Yes");
    } 
    // Check if the last three digits of n, when divided by 111, results in 0
    else if ((n % 1000) % 111 == 0) {
      // If true, print "Yes"
      System.out.println("Yes");
    } 
    // If neither condition is met, print "No"
    else {
      System.out.println("No");
    }
  }
}
