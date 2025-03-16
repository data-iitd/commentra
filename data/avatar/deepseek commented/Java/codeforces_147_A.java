
import java.io.BufferedReader ; 
import java.io.IOException ; 
import java.io.InputStreamReader ; 
import java.io.PrintWriter ; 

public class Main { 
    // Method to check if a character is a Latin letter
    public static boolean isLatinLetter ( char c ) { 
        return c >= 'a' && c <= 'z' ; 
    } 

    // Method to check if a character is a punctuation mark
    public static boolean isPunctuation ( char c ) { 
        if ( c == '.' ) return true ; 
        if ( c == ',' ) return true ; 
        if ( c == '!' ) return true ; 
        if ( c == '?' ) return true ; 
        return false ; 
    } 

    // Main method: Entry point of the program
    public static void main ( String [ ] args ) throws IOException { 
        // Create BufferedReader to read input from the console
        BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        // Create PrintWriter to print output to the console
        PrintWriter pw = new PrintWriter ( System.out ) ; 
        // Read the input string
        String s = br.readLine ( ) ; 
        // Create a StringBuilder to build the output string
        StringBuilder sb = new StringBuilder ( ) ; 
        // Get the length of the input string
        int n = s.length ( ) ; 
        // Append the first character of the input string to the StringBuilder
        sb.append ( s.charAt ( 0 ) ) ; 
        // Loop through the input string starting from the second character
        for ( int i = 1 ; i < n ; i ++ ) { 
            char c = s.charAt ( i ) ; 
            // Check if the character is a Latin letter
            if ( isLatinLetter ( c ) ) { 
                // If the previous character is not a Latin letter, add a space
                if ( ! isLatinLetter ( s.charAt ( i - 1 ) ) ) { 
                    sb.append ( ' ' ) ; 
                } 
                // Append the current Latin letter to the StringBuilder
                sb.append ( c ) ; 
            } 
            // Check if the character is a punctuation mark
            else if ( isPunctuation ( c ) ) { 
                // Append the punctuation mark to the StringBuilder
                sb.append ( c ) ; 
            } 
        } 
        // Print the final string with spaces added between Latin letters
        pw.println ( sb ) ; 
        // Flush the PrintWriter to ensure all output is printed
        pw.flush ( ) ; 
        // Close the PrintWriter
        pw.close ( ) ; 
    } 
}
