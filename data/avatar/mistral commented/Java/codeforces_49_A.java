
import java.util.Scanner ;

public class Main {

    public static void main ( String [ ] args ) {
        // Initialize Scanner object to read input from the console
        Scanner sc = new Scanner ( System.in ) ;

        String s = "" ; // Initialize an empty string to store the input line

        // Read the next line from the console and store it in the string 's'
        s = sc.nextLine ( ) ;

        // Get the length of the string 's'
        int length = s.length ( ) ;

        // Initialize a character variable 'ch' to store the first non-space and non-question mark character found in the string 's'
        char ch = ' ' ;

        // Iterate through the string 's' from the end to the beginning
        for ( int i = length - 1 ; i >= 0 ; i -- ) {
            // Check if the current character is not a space or a question mark
            if ( s.charAt ( i ) != ' ' && s.charAt ( i ) != '?' ) {
                // If yes, store the character in 'ch' and break out of the loop
                ch = s.charAt ( i ) ;
                break ;
            }
        }

        // Convert the character 'ch' to lowercase
        ch = Character.toLowerCase ( ch ) ;

        // Check if the character 'ch' is a vowel or a y
        if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' ) {
            // If yes, print "YES" to the console
            System.out.println ( "YES" ) ;
        } else {
            // If no, print "NO" to the console
            System.out.println ( "NO" ) ;
        }
    }
}