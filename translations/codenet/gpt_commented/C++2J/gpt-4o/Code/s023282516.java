import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    // Define the array of substrings to check against
    static String[] divide = {"dream", "dreamer", "erase", "eraser"};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the input string from the user
        String S = scanner.next();
        
        // Reverse the input string to facilitate checking from the end
        StringBuilder reversedS = new StringBuilder(S).reverse();
        S = reversedS.toString();
        
        // Reverse each of the substrings in the divide array for matching
        for (int i = 0; i < divide.length; i++) {
            divide[i] = new StringBuilder(divide[i]).reverse().toString();
        }

        // Initialize a flag to determine if the string can be fully divided
        boolean can = true;
        // Start checking the string from the beginning
        for (int i = 0; i < S.length();) {
            boolean can2 = false; // Flag to check if we can divide with any of the substrings
            // Iterate through each substring in the divide array
            for (String d : divide) {
                // Check if the current substring matches the beginning of the remaining string
                if (S.startsWith(d, i)) { // If we can divide with d
                    can2 = true; // Set the flag to true
                    i += d.length(); // Move the index forward by the length of the matched substring
                    break; // Break to avoid checking other substrings once a match is found
                }
            }
            // If no substring matched, set the can flag to false and break the loop
            if (!can2) { // If we couldn't divide the string
                can = false;
                break;
            }
        }

        // Output the result based on whether the string can be fully divided
        if (can) {
            System.out.println("YES"); // If it can be divided, print "YES"
        } else {
            System.out.println("NO"); // Otherwise, print "NO"
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
