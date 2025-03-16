// Importing necessary packages
import java.util.* ;

// Creating a Main class with a main method
public class Main {
    public static void main ( String [ ] args ) {
        // Initializing a Scanner object to read input
        Scanner in = new Scanner ( System.in ) ;

        // Reading the first word from the user input
        String word1 = in.nextLine ( ).replaceAll ( "[^a-zA-Z]" , "" ).toLowerCase ( ) ;
        // This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
        // The resulting string is stored in the 'word1' variable.

        // Reading the second word from the user input
        String word2 = in.nextLine ( ).replaceAll ( "[^a-zA-Z]" , "" ).toLowerCase ( ) ;
        // This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
        // The resulting string is stored in the 'word2' variable.

        // Reading the third word from the user input
        String word3 = in.nextLine ( ).replaceAll ( "[^a-zA-Z]" , "" ).toLowerCase ( ) ;
        // This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
        // The resulting string is stored in the 'word3' variable.

        // Creating six permutations of the given words
        String perm1 = word1 + word2 + word3 ;
        String perm2 = word1 + word3 + word2 ;
        String perm3 = word2 + word1 + word3 ;
        String perm4 = word2 + word3 + word1 ;
        String perm5 = word3 + word2 + word1 ;
        String perm6 = word3 + word1 + word2 ;

        // Reading the number of students
        int students = in.nextInt ( ) ;
        // This block of code reads an integer value from the user input.
        // The number of students is stored in the 'students' variable.
        in.nextLine ( ) ; // Consuming the newline character left after reading an integer.

        // Looping through each student's test case
        for ( int i = 0 ; i < students ; i ++ ) {
            // Reading a test case from the user input
            String testCase = in.nextLine ( ).replaceAll ( "[^a-zA-Z]" , "" ).toLowerCase ( ) ;
            // This block of code reads a line from the user input, removes all non-alphabetic characters, and converts it to lowercase.
            // The resulting string is stored in the 'testCase' variable.

            // Checking if the test case matches any of the permutations
            if ( testCase.equals ( perm1 ) || testCase.equals ( perm2 ) || testCase.equals ( perm3 ) || testCase.equals ( perm4 ) || testCase.equals ( perm5 ) || testCase.equals ( perm6 ) ) {
                // Printing 'ACC' if the test case matches any of the permutations
                System.out.println ( "ACC" ) ;
            } else {
                // Printing 'WA' if the test case doesn't match any of the permutations
                System.out.println ( "WA" ) ;
            }
        }

        // Closing the Scanner object
        in.close ( ) ;
    }
}