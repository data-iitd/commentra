import java.util.*;

public class DivideTheString {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String S = in.next();
        // Reverse the input string to facilitate checking from the end
        S = new StringBuilder(S).reverse().toString();
        // Reverse each of the substrings in the divide array for matching
        String[] divide = {"dream", "dreamer", "erase", "eraser"};
        for (int i = 0; i < 4; ++i) divide[i] = new StringBuilder(divide[i]).reverse().toString();

        // Initialize a flag to determine if the string can be fully divided
        boolean can = true;
        // Start checking the string from the beginning
        for (int i = 0; i < S.length();) {
            boolean can2 = false; // Flag to check if we can divide with any of the substrings
            // Iterate through each substring in the divide array
            for (int j = 0; j < 4; ++j) {
                String d = divide[j];
                // Check if the current substring matches the beginning of the remaining string
                if (S.substring(i, i + d.length()).equals(d)) { // If we can divide with d
                    can2 = true; // Set the flag to true
                    i += d.length(); // Move the index forward by the length of the matched substring
                }
            }
            // If no substring matched, set the can flag to false and break the loop
            if (!can2) { // If we couldn't divide the string
                can = false;
                break;
            }
        }

        // Output the result based on whether the string can be fully divided
        if (can) System.out.println("YES"); // If it can be divided, print "YES"
        else System.out.println("NO"); // Otherwise, print "NO"
    }
}
