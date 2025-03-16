
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        // Create a Scanner object to read input from the user
        Scanner in = new Scanner ( System.in ) ; 
        
        // Read an integer K from the user
        int K = in.nextInt ( ) ; 
        
        // Read a string S from the user
        String S = in.next ( ) ; 
        
        // Check if the length of the string S is less than or equal to K
        if ( S.length ( ) <= K ) { 
            // If true, print the string S as it is
            System.out.println ( S ) ; 
        } else { 
            // If false, truncate the string to the first K characters and append "..."
            System.out.println ( S.substring ( 0 , K ) + "..." ) ; 
        } 
    } 
}
