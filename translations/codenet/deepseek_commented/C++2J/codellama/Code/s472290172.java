import java.util.Scanner;
import java.util.Map;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        // Read the input string from the standard input.

        int max = 0, cnt = 0;
        // Initialize max and cnt to keep track of the maximum length of consecutive 'A', 'C', 'G', or 'T' characters and the current length of such a sequence, respectively.

        for (int i = 0; i < str.length(); i++) {
            // Iterate over each character in the string.
            char sc = str.charAt(i);
            if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') {
                // Check if the character is one of 'A', 'C', 'G', or 'T'.
                cnt++;
                // If it is, increment the cnt variable.
            } else {
                cnt = 0;
                // If not, reset cnt to 0.
            }
            max = Math.max(max, cnt);
            // After each character, update max to be the maximum of max and cnt.
        }

        System.out.println(max);
        // Print the value of max to the standard output.
    }
}
