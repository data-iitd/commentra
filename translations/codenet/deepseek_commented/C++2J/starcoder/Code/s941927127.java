
import java.util.*;

public class Main {
  public static void main(String[] args) {
    // Step 1: Read input
    Scanner sc = new Scanner(System.in);
    String W = sc.next();
    
    // Step 2: Sort the string
    char[] W_arr = W.toCharArray();
    Arrays.sort(W_arr);
    String W_sorted = new String(W_arr);
    
    // Step 3: Check for character pairs
    for (int i = 0; i < W_sorted.length()-1; i++) {
      if (W_sorted.charAt(i)!= W_sorted.charAt(i+1)) {
        // If a character is not followed by its pair, output "No" and exit.
        System.out.println("No");
        return;
      }
    }
    
    // Step 4: Output result
    // If all characters are in pairs, the program outputs "Yes"; otherwise,
    // it outputs "No".
    System.out.println("Yes");
  }
}

