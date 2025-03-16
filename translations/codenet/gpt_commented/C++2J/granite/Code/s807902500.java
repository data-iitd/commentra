
import java.util.Scanner; // Import the Scanner class for input operations

public class s807902500{
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in); // Create a Scanner object to read input from the user
    String s = scanner.next(); // Read the first input string, s
    String t = scanner.next(); // Read the second input string, t
    s += s; // Concatenate string s with itself, effectively doubling it

    // Check if string t can be found within the doubled string s
    // If found, print "Yes", otherwise print "No"
    System.out.println(s.indexOf(t)!= -1? "Yes" : "No");
  }
}
