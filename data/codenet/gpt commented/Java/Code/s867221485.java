import java.lang.reflect.Array;
import java.util.*;

/**
 * Created by Santa.
 */
public class Main {

  // Declare static variables for various parameters
  static int N; // Number of characters in the input string
  static int K; // Unused variable (could be used for future enhancements)
  static long Q; // Unused variable (could be used for future enhancements)
  static int A; // Unused variable (could be used for future enhancements)
  static int B; // Unused variable (could be used for future enhancements)
  static long C; // Unused variable (could be used for future enhancements)
  static double min = 9999999; // Unused variable (could be used for future enhancements)
  static long ans = 0; // Variable to store the final answer

  public static void main(String[] args) {
    // Create a scanner object to read input
    Scanner scanner = new Scanner(System.in);

    // Read the number of characters from input
    int N = scanner.nextInt();
    scanner.nextLine(); // Consume the newline character

    // Read the input string
    String s = scanner.nextLine();

    // Initialize flags and counters
    boolean flag = false; // Unused variable
    int ans = 0; // Variable to accumulate the answer
    int hen = 0; // Unused variable
    int sha = 0; // Counter for '#' characters
    int dot = 0; // Counter for '.' characters
    int temp = 0; // Unused variable
    boolean first = true; // Flag to track the first character in a sequence

    // Iterate through each character in the input string
    for (int i = 0; i < N; i++) {
      // Check if the current character is '#'
      if(s.charAt(i) == '#'){
        first = false; // Set first to false since we encountered a '#'
        
        // If the count of '#' is less than or equal to the count of '.'
        if(sha <= dot){
          ans += sha; // Add the count of '#' to the answer
          sha = 0; // Reset the '#' counter
          dot = 0; // Reset the '.' counter
          first = true; // Reset first flag
        } else {
          // If '#' count is greater, we do not add to the answer
        }

        sha++; // Increment the '#' counter
      } else {
        // If the current character is not '#', increment the '.' counter
        dot++;
      }
    }

    // After the loop, check the final counts
    if(sha <= dot){
      ans += sha; // Add the count of '#' to the answer if it's less than or equal to '.'
      dot = 0; // Reset the '.' counter
    } else {
      // If '#' count is greater, we do not add to the answer
    }

    // Output the final answer, which is the sum of ans and remaining dot count
    System.out.println(ans + dot);
  }
}
