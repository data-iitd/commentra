
import java.io.BufferedReader ; 
import java.io.IOException ; 
import java.io.InputStreamReader ; 
import java.io.PrintWriter ; 
import java.math.BigInteger ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) throws NumberFormatException , IOException { 
        // Set up input and output streams
        InputStreamReader inputStreamReader = new InputStreamReader ( System.in ) ; 
        BufferedReader bufferedReader = new BufferedReader ( inputStreamReader ) ; 
        PrintWriter writer = new PrintWriter ( System.out ) ; 

        // Read the input string from the user
        String str = bufferedReader.readLine ( ) ; 

        // Create a HashMap to count the frequency of each character in the input string
        Map < Character , Integer > map = new HashMap < > ( ) ; 

        // Initialize a counter for characters with odd frequencies
        int oddCount = 0 ; 

        // Iterate through the input string to populate the frequency map
        for ( int i = 0 ; i < str.length ( ) ; i ++ ) { 
            char ch = str.charAt ( i ) ; 
            if ( map.containsKey ( ch ) ) { 
                map.put ( ch , map.get ( ch ) + 1 ) ; 
            } else { 
                map.put ( ch , 1 ) ; 
            } 
        } 

        // Iterate through the map to count characters with odd frequencies
        for ( Map.Entry < Character , Integer > entry : map.entrySet ( ) ) { 
            if ( entry.getValue ( ) % 2 != 0 ) { 
                oddCount ++ ; 
            } 
        } 

        // Determine the winner based on the count of characters with odd frequencies
        if ( oddCount <= 1 || oddCount % 2 != 0 ) { 
            writer.println ( "First" ) ; 
        } else { 
            writer.println ( "Second" ) ; 
        } 

        // Flush the output to ensure the result is printed immediately
        writer.flush ( ) ; 
    } 
}
