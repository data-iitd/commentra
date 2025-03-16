
import java.util.Scanner;

public class s495283729{
  public static void main(String[] args) {
    // Declare a character array to hold the input string
    char[] s = new char[1000];
    
    // Create a Scanner object to read input from the user
    Scanner scanner = new Scanner(System.in);
    
    // Read a string from standard input
    scanner.nextLine().getChars(0, 1000, s, 0);
    
    // Initialize variables: i for iteration and flag to track validity
    int i, flag = 0;
    
    // Iterate through each character in the string
    for (i = 0; i < s.length; i++) {
      // Check if the index is even
      if (i % 2 == 0) {
        // Switch case for characters at even indices
        switch (s[i]) {
          case 'R':
            // 'R' is valid, do nothing
            break;
          case 'U':
            // 'U' is valid, do nothing
            break;
          case 'D':
            // 'D' is valid, do nothing
            break;
          default:
            // If character is not valid, set flag to indicate an error
            flag = 1;
            break;
        }
      } else {
        // Switch case for characters at odd indices
        switch (s[i]) {
          case 'L':
            // 'L' is valid, do nothing
            break;
          case 'U':
            // 'U' is valid, do nothing
            break;
          case 'D':
            // 'D' is valid, do nothing
            break;
          default:
            // If character is not valid, set flag to indicate an error
            flag = 1;
            break;
        }
      }
    }
    
    // Check the flag to determine if the input string was valid
    if (flag == 0) {
      // If flag is still 0, print "Yes" indicating valid input
      System.out.println("Yes");
    } else {
      // If flag is set, print "No" indicating invalid input
      System.out.println("No");
    }
  }
}
