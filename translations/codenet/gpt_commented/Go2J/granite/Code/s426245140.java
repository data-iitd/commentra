
import java.util.Scanner;

public class s426245140{
  public static void main(String[] args) {
    // Declare a variable to hold the input string
    Scanner scanner = new Scanner(System.in);
    String s = scanner.nextLine();
    
    // Check if the first three characters are the same or the last three characters are the same
    if ((s.charAt(0) == s.charAt(1)) && (s.charAt(1) == s.charAt(2))) {
      // If the condition is true, print "Yes"
      System.out.println("Yes");
    } else if ((s.charAt(1) == s.charAt(2)) && (s.charAt(2) == s.charAt(3))) {
      // If the condition is true, print "Yes"
      System.out.println("Yes");
    } else {
      // If the condition is false, print "No"
      System.out.println("No");
    }
  }
}
