import java.lang.reflect.Array;
import java.util.*;

/**
 * Created by Santa.
 */
public class Main {

  static int N; // Number of characters in the input string
  static int K; // Not used in the code
  static long Q; // Not used in the code
  static int A; // Not used in the code
  static int B; // Not used in the code
  static long C; // Not used in the code
  static double min = 9999999; // A large initial value for comparison
  static long ans = 0; // To store the final result

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    N = scanner.nextInt(); // Read the number of characters
    scanner.nextLine(); // Consume the newline character

    String s = scanner.nextLine(); // Read the input string

    boolean flag = false; // A flag to indicate some condition
    int ans = 0; // To store the count of '#'
    int hen = 0; // Not used in the code
    int sha = 0; // To count consecutive '#'
    int dot = 0; // To count consecutive '.'
    int temp = 0; // Not used in the code
    boolean first = true; // To check the first occurrence

    // Loop through each character in the string
    for (int i = 0; i < N; i++) {
      if(s.charAt(i) == '#'){
        first = false;
        if(sha <= dot){
          ans += sha; // Add the count of '#' to ans
          sha = 0; // Reset sha
          dot = 0; // Reset dot
          first = true; // Reset first
        }
        sha++; // Increment the count of '#'
      } else {
        dot++; // Increment the count of '.'
      }
    }

    // Final check after the loop
    if(sha <= dot){
      ans += sha; // Add the count of '#' to ans
      dot = 0; // Reset dot
    }

    System.out.println(ans + dot); // Print the final result
  }
}
