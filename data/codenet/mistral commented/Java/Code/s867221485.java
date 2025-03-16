import java.lang.reflect.Array;
import java.util.*;

/**
 * Created by Santa.
 * This is the main class for the problem.
 */
public class Main {

  static int N; // The number of strings to process
  static int K; // The maximum length of a string
  static long Q; // The number of queries
  static int A; // The first index of the substring
  static int B; // The last index of the substring
  static long C; // The query value
  static double min = 9999999; // Initialize minimum value to a large number
  static long ans = 0; // Initialize answer to zero

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in); // Initialize Scanner object for reading input

    N = scanner.nextInt(); // Read the number of strings from the input

    // Read the newline character
    scanner.nextLine();

    String s; // Initialize a String variable to store the current string

    boolean flag = false; // Initialize a boolean variable to keep track of the state of the current hash
    int ans = 0; // Initialize the answer to zero
    int hen = 0; // Initialize the count of 'h' characters
    int sha = 0; // Initialize the count of 's' characters
    int dot = 0; // Initialize the count of '#' characters
    int temp = 0; // Initialize a temporary variable to store the count of '#' characters before the last one
    boolean first = true; // Initialize a boolean variable to keep track of the first occurrence of '#' in the current string

    for (int i = 0; i < N; i++) { // Iterate through each string
      s = scanner.nextLine(); // Read the current string from the input

      for (int j = 0; j < s.length(); j++) { // Iterate through each character in the current string
        if (s.charAt(j) == '#') { // If the character is '#'
          flag = !flag; // Toggle the state of the current hash

          if (sha <= dot) { // If the number of 's' characters is less than or equal to the number of '#' characters before the last one
            ans += sha; // Add the count of 's' characters to the answer
            sha = 0; // Reset the count of 's' characters to zero
            dot = 0; // Reset the count of '#' characters to zero
            first = true; // Reset the flag to indicate that this is the first occurrence of '#' in the current string
          } else {
            // If the number of '#' characters is greater than the number of 's' characters, add the count of '#' characters before the last one to the temporary variable
            temp += dot;
          }

          sha++; // Increment the count of 's' characters
        } else {
          if (!first) { // If this is not the first character in the current string
            dot++; // Increment the count of '#' characters
          }
          first = false; // Set the flag to indicate that this is not the first character in the current string
        }
      }

      if (sha <= dot) { // If the number of 's' characters is less than or equal to the number of '#' characters
        ans += sha; // Add the count of 's' characters to the answer
        dot = 0; // Reset the count of '#' characters to zero
      } else {
        // Add the count of '#' characters before the last one to the answer
        ans += temp;
      }
    }

    // If the last string has more '#' characters than 's' characters, add the count of '#' characters to the answer
    if (sha <= dot) {
      ans += sha;
      dot = 0;
    }

    // Print the answer
    System.out.println(ans + dot);
  }
}
