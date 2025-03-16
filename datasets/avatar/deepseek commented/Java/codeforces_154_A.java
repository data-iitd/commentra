
import java.util.* ; 
import java.io.* ; 
import java.math.* ; 

public class Main { 
    public static void main ( String hi [ ] ) throws Exception { 
        // Reading input from standard input
        BufferedReader infile = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        char [ ] arr = infile.readLine ( ).toCharArray ( ) ; // Read a line and convert it to a character array
        int N = arr.length ; // Store the length of the character array
        
        // Initialize a HashSet to store unique strings and read the number of test cases
        HashSet < String > set = new HashSet < String > ( ) ; 
        int K = Integer.parseInt ( infile.readLine ( ) ) ; 
        
        // Initialize the result variable to store the final count
        int res = 0 ; 
        
        // Loop to process each test case
        for ( int k = 0 ; k < K ; k ++ ) { 
            String input = infile.readLine ( ) ; // Read the input string for the current test case
            int a = 0 ; // Counter for the first character of the input
            int b = 0 ; // Counter for the second character of the input
            
            // Iterate over the characters of the input array
            for ( int i = 0 ; i < N ; i ++ ) { 
                if ( arr [ i ] == input.charAt ( 0 ) ) // If the character matches the first character of the input
                    a ++ ; 
                else if ( arr [ i ] == input.charAt ( 1 ) ) // If the character matches the second character of the input
                    b ++ ; 
                else { // If the character does not match either of the input characters
                    res += Math.min ( a , b ) ; // Add the minimum of a and b to the result
                    a = b = 0 ; // Reset the counters
                } 
            } 
            res += Math.min ( a , b ) ; // Add the minimum of a and b to the result after the loop
        } 
        
        // Print the final result
        System.out.println ( res ) ; 
    } 
}