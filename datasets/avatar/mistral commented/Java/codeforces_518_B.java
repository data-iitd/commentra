
import java.util.* ;

// Main method declaration
public class Main {

    // Main method starts the execution of the program
    public static void main ( String [ ] args ) {
        Scanner scan = new Scanner ( System.in ) ; // Create a new Scanner object to read input from the console
        StringBuilder s = new StringBuilder ( scan.next ( ) ) ; // Create a new StringBuilder object to store the first input string
        String t = scan.next ( ) ; // Read the second input string from the console

        // Initialize counters for unique characters in the first string and opposite characters in the second string
        int ura = 0 ;
        int opa = 0 ;

        // Create a HashMap to store the frequency of each character in the second string
        Map < Character , Integer > tmap = new HashMap < > ( ) ;

        // Read the characters of the second string and store their frequencies in the HashMap
        for ( int i = 0 ; i < t.length ( ) ; i ++ ) {
            Character ch = t.charAt ( i ) ;
            if ( ! tmap.containsKey ( ch ) ) // If the character is not already in the HashMap
                tmap.put ( ch , 1 ) ; // Add it with a frequency of 1
            else
                tmap.put ( ch , tmap.get ( ch ) + 1 ) ; // If the character is already in the HashMap, increment its frequency
        }

        // Process the first string
        int length = s.length ( ) ;
        for ( int i = 0 ; i < length ; i ++ ) {
            Character ch = s.charAt ( i ) ;
            Integer num = tmap.get ( ch ) ;
            if ( num == null ) // If the character is not in the second string
                continue ;
            int inum = num ;
            if ( inum == 1 ) // If the character appears only once in the second string
                tmap.remove ( ch ) ; // Remove it from the HashMap
            else
                tmap.put ( ch , inum - 1 ) ; // If the character appears more than once in the second string, decrement its frequency
            s.setCharAt ( i , 'Я' ) ; // Replace the character in the StringBuilder with 'Я'
            ura ++ ; // Increment the counter for unique characters
        }

        // Process the reversed version of the first string
        for ( int i = 0 ; i < length ; i ++ ) {
            Character ch = s.charAt ( i ) ;
            Character rch = reverse ( ch ) ; // Get the reverse character of the current character
            Integer num = tmap.get ( rch ) ;
            if ( num == null ) // If the reverse character is not in the second string
                continue ;
            int inum = num ;
            if ( inum == 1 ) // If the reverse character appears only once in the second string
                tmap.remove ( rch ) ; // Remove it from the HashMap
            else
                tmap.put ( rch , inum - 1 ) ; // If the reverse character appears more than once in the second string, decrement its frequency
            opa ++ ; // Increment the counter for opposite characters
        }

        // Print the results
        System.out.println ( ura + " " + opa ) ;
    }

    // Reverse the given character
    public static Character reverse ( Character ch ) {
        if ( Character.isLowerCase ( ch ) ) { // If the character is lowercase
            return Character.toUpperCase ( ch ) ; // Return its uppercase version
        } else {
            return Character.toLowerCase ( ch ) ; // If the character is uppercase, return its lowercase version
        }
    }
}