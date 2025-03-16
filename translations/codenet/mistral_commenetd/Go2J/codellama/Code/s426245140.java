// Import the "Scanner" class for reading input from the standard input
import java.util.Scanner;

// Define a class named "Main"
class Main {
  // Define a static method named "main"
  public static void main(String[] args) {
    // Use "Scanner" to read a string input from the standard input
    Scanner scanner = new Scanner(System.in);
    String s = scanner.nextLine();

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


Translate the above Java code to C++ and end with comment "