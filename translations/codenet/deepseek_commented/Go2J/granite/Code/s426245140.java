
import java.util.Scanner;

public class s426245140{
  public static void main(String[] args) {
    // Declare a variable to store the input string
    String s;
    
    // Create a Scanner object to read input from the user
    Scanner scanner = new Scanner(System.in);
    
    // Read a string input from the user and store it in `s`
    s = scanner.nextLine();
    
    // Check if the first three characters of `s` are the same or if the second three characters of `s` are the same
    if ((s.charAt(0) == s.charAt(1)) && (s.charAt(1) == s.charAt(2))) {
      // If either condition is true, print "Yes"
      System.out.println("Yes");
    } else if ((s.charAt(1) == s.charAt(2)) && (s.charAt(2) == s.charAt(3))) {
      // If either condition is true, print "Yes"
      System.out.println("Yes");
    } else {
      // Otherwise, print "No"
      System.out.println("No");
    }
  }
}
