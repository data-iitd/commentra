// Import the "Scanner" class from the "java.util" package
import java.util.Scanner;

// Define a class named "Main"
public class Main {
  // Define a static void method named "main"
  public static void main(String[] args) {
    // Create a new instance of the "Scanner" class named "sc"
    Scanner sc = new Scanner(System.in);

    // Read a string input from the standard input
    String s = sc.next();

    // Check if the first three characters of the string "s" form an identical sequence
    if (s.charAt(0) == s.charAt(1) && s.charAt(1) == s.charAt(2)) || (s.charAt(1) == s.charAt(2) && s.charAt(2) == s.charAt(3)){
      // If the condition is true, print "Yes" to the standard output
      System.out.println("Yes");
    } else {
      // If the condition is false, print "No" to the standard output
      System.out.println("No");
    }
  }
}

// End of code

