import java.util.Scanner;

public class Solution {
  public static void main(String[] args) {
    // Declare a string to hold the input string
    String s;
    
    // Read a string from standard input
    Scanner sc = new Scanner(System.in);
    s = sc.nextLine();
    
    // Initialize variables: i for iteration and flag to track validity
    int i, flag = 0;
    
    // Iterate through each character in the string
    for (i = 0; i < s.length(); i++) {
      // Check if the index is even
      if (i % 2 == 0) {
        // Switch case for characters at even indices
        switch (s.charAt(i)) {
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
        switch (s.charAt(i)) {
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

