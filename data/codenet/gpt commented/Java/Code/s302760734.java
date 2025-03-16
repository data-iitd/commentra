import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Read two strings from input and convert them to character arrays
        char[] s = scanner.next().toCharArray();
        char[] t = scanner.next().toCharArray();
        
        // Initialize a flag to check if a match is found
        boolean check = false;
        
        // Iterate through the string 's' to find a position where 't' can fit
        for(int i = s.length - t.length; i >= 0; i--) {
            // Assume a match is possible
            boolean check2 = true;
            
            // Check if 't' can fit into 's' starting at position 'i'
            for(int j = 0; j < t.length; j++) {
                // If the characters do not match and the character in 's' is not '?', set check2 to false
                if(s[i + j] != '?' && s[i + j] != t[j]) {
                    check2 = false;
                }
            }
            
            // If a valid position is found, replace '?' or matching characters in 's' with characters from 't'
            if(check2) {
                check = true; // Mark that a match has been found
                for(int j = 0; j < t.length; j++) {
                    s[i + j] = t[j]; // Replace characters in 's' with those from 't'
                }
            }
            
            // Break the loop if a match has been found
            if(check) {
                break;
            }
        }
        
        // If a match was found, print the modified string
        if(check) {
            for(int i = 0; i < s.length; i++) {
                // Replace any remaining '?' with 'a'
                if(s[i] == '?') {
                    System.out.print("a");
                } else {
                    System.out.print(s[i]); // Print the character as is
                }
            }
            System.out.println(); // Print a newline after the output
        } else {
            // If no match was found, print "UNRESTORABLE"
            System.out.println("UNRESTORABLE");
        }
    }
}
