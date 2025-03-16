
// Import the "java.util.Scanner" class for reading user input
import java.util.Scanner;

// Define a class named "s426245140"
public class s426245140{
  // Define a main method to execute the program
  public static void main(String[] args) {
    // Create a new instance of the "Scanner" class to read user input
    Scanner scanner = new Scanner(System.in);

    // Use "scanner.nextLine()" to read a string input from the standard input
    String s = scanner.nextLine();

    // Check if the first three characters of the string "s" form an identical sequence
    if ((s.charAt(0) == s.charAt(1)) && (s.charAt(1) == s.charAt(2))) || ((s.charAt(1) == s.charAt(2)) && (s.charAt(2) == s.charAt(3))){
      // If the condition is true, print "Yes" to the standard output
      System.out.println("Yes");
    } else {
      // If the condition is false, print "No" to the standard output
      System.out.println("No");
    }

    // Close the "Scanner" object to release system resources
    scanner.close();
  }
}

// End of code