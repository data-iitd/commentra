// Import necessary packages
import java.util.Scanner;

// Main class
public class Main {
    // Main method
    public static void main(String[] args) {
        // Initialize scanner for reading input
        Scanner sc = new Scanner(System.in);

        // Read the first string from standard input
        String s = sc.next();

        // Initialize variable c with 'a'
        char c = 'a';

        // Check all characters from 'a' to 'z' in the string s
        for (int j = 0; j < 26; j++) {
            // Initialize variable found as false
            boolean found = false;

            // Iterate through each character in the string s
            for (int i = 0; i < s.length(); i++) {
                // If current character matches c, set found to true and break the loop
                if (s.charAt(i) == c) {
                    found = true;
                    break;
                }
            }

            // If character c is not found in the string s, print it and return
            if (!found) {
                System.out.println(c);
                return;
            }

            // Increment variable c
            c++;
        }

        // If no character from 'a' to 'z' is found in the string s, print "None"
        System.out.println("None");
        
        // Close the scanner
        sc.close();
    }
}
// <END-OF-CODE>
