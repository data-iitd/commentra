
import java.util.Scanner ;

public class Main {
    // Initialize Scanner object to read input from the console
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;
        String S = "" ; // Initialize string S to store the first input line
        String T = "" ; // Initialize string T to store the second input line

        // Read the first input line from the console
        S = sc.nextLine ( ) ;

        // Read the second input line from the console
        T = sc.nextLine ( ) ;

        // Close the Scanner object to save system resources
        sc.close ( ) ;

        // Initialize an array of strings A with all possible characters from a to z
        String [ ] A = { "a" , "b" , "c" , "d" , "e" , "f" , "g" , "h" , "i" , "j" , "k" , "l" , "m" , "n" , "o" , "p" , "q" , "r" , "s" , "t" , "u" , "v" , "w" , "x" , "y" , "z" } ;

        // Initialize a boolean variable res to store the result of the comparison
        boolean res = true ;

        // Iterate through each string s in the array A
        for ( String s : A ) {
            // Find the index of string s in string S
            int sIdx = S.indexOf ( s ) ;

            // If string s is not found in string S, continue to the next string in the array
            if ( sIdx < 0 ) continue ;

            // Convert the character at the index sIdx in string T to a string
            String t = String.valueOf ( T.charAt ( sIdx ) ) ;

            // Initialize an index variable idx to 0
            int idx = 0 ;

            // Iterate through each character in string S starting from the index sIdx
            while ( idx < S.length ( ) ) {
                // If string s is found in string S starting from index idx, compare the corresponding characters in strings S and T
                if ( S.indexOf ( s , idx ) >= 0 ) {
                    if ( S.indexOf ( s , idx ) != T.indexOf ( t , idx ) ) {
                        // If the characters do not match, set the boolean variable res to false and break out of the loop
                        res = false ;
                        break ;
                    } else {
                        // If the characters match, increment the index variable idx by the length of string s
                        idx = S.indexOf ( s , idx ) + 1 ;
                    }
                }

                // If string s is not found in string T starting from index idx, set the boolean variable res to false and break out of the loop
                else if ( T.indexOf ( t , idx ) >= 0 ) {
                    res = false ;
                    break ;
                }

                // If string s is not found in both strings S and T starting from index idx, break out of the loop
                else break ;
            }

            // If the boolean variable res is still true after the loop, print "Yes" to the console
            if ( res ) System.out.println ( "Yes" ) ;

            // If the boolean variable res is false, print "No" to the console and break out of the main loop
            else {
                System.out.println ( "No" ) ;
                break ;
            }
        }
    }
}