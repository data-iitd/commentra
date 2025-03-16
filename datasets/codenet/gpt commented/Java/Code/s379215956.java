import java.util.*;

class Main {
  public static void main(String[] args) {
    // Create a Scanner object to read input from the user
    Scanner sc = new Scanner(System.in);
    
    // Read a string input from the user
    String s = sc.next();
    
    // Extract individual characters from the string
    String s1 = s.substring(0, 1); // First character
    String s2 = s.substring(1, 2); // Second character
    String s3 = s.substring(2, 3); // Third character
    String s4 = s.substring(3, 4); // Fourth character
    
    // Initialize a variable to track if any adjacent characters are the same
    int a = 0;
    
    // Check if the first and second characters are the same
    if (s1.equals(s2)) a = 1;
    // Check if the second and third characters are the same
    if (s2.equals(s3)) a = 1;
    // Check if the third and fourth characters are the same
    if (s3.equals(s4)) a = 1;
    
    // Determine if the string is "Bad" or "Good" based on the checks
    if (a == 1) {
      // If any adjacent characters are the same, print "Bad"
      System.out.println("Bad");
    } else {
      // If all adjacent characters are different, print "Good"
      System.out.println("Good");
    }
    
  }
}
