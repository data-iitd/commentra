
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; // Initialize Scanner for input operations

        // Read and process the three input words
        String word1 = in.nextLine ( ).replaceAll ( "[^a-zA-Z]" , "" ).toLowerCase ( ) ; 
        String word2 = in.nextLine ( ).replaceAll ( "[^a-zA-Z]" , "" ).toLowerCase ( ) ; 
        String word3 = in.nextLine ( ).replaceAll ( "[^a-zA-Z]" , "" ).toLowerCase ( ) ; 

        // Generate all possible permutations of the three words
        String perm1 = word1 + word2 + word3 ; 
        String perm2 = word1 + word3 + word2 ; 
        String perm3 = word2 + word1 + word3 ; 
        String perm4 = word2 + word3 + word1 ; 
        String perm5 = word3 + word2 + word1 ; 
        String perm6 = word3 + word1 + word2 ; 

        // Read the number of test cases
        int students = in.nextInt ( ) ; 
        in.nextLine ( ) ; // Consume the newline character after the integer input

        // Process each test case
        for ( int i = 0 ; i < students ; i ++ ) { 
            String testCase = in.nextLine ( ).replaceAll ( "[^a-zA-Z]" , "" ).toLowerCase ( ) ; 
            // Check if the test case matches any of the generated permutations
            if ( testCase.equals ( perm1 ) || testCase.equals ( perm2 ) || testCase.equals ( perm3 ) || 
                 testCase.equals ( perm4 ) || testCase.equals ( perm5 ) || testCase.equals ( perm6 ) ) { 
                System.out.println ( "ACC" ) ; // Print "ACC" if a match is found
            } else { 
                System.out.println ( "WA" ) ; // Print "WA" if no match is found
            } 
        } 
    } 
}