import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; // Create a Scanner object to read input from the user
        String s = sc.nextLine ( ) ; // Read a line of input from the user and store it in a string variable s
        int length = s.length ( ) ; // Calculate the length of the string s and store it in an integer variable length
        char ch = 0 ; // Initialize a character variable ch to 0

        // Iterate through the string s in reverse order, starting from the last character
        for ( int i = length - 1 ; i >= 0 ; i -- ) { 
            if ( s.charAt ( i ) != ' ' && s.charAt ( i ) != '?' ) { // Check if the current character is not a space or a question mark
                ch = s.charAt ( i ) ; // Assign the current character to the variable ch
                break ; // Exit the loop
            } 
        }

        ch = Character.toLowerCase ( ch ) ; // Convert the character ch to lowercase

        // Check if ch is one of the vowels (a, e, i, o, u, y)
        if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' ) { 
            System.out.println ( "YES" ) ; // Print "YES" if ch is a vowel
        } else { 
            System.out.println ( "NO" ) ; // Print "NO" if ch is not a vowel
        } 
    } 
}