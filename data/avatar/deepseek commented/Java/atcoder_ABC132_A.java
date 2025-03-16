
import java.util.HashMap ; import java.util.Map.Entry ; import java.util.Scanner ; 
// Import statements for Scanner and HashMap

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; 
        // Initialize Scanner object to read input

        String s = in.next ( ) ; 
        // Read the input string

        char [ ] targ = s.toCharArray ( ) ; 
        // Convert the string to a character array

        HashMap < Character , Integer > map = new HashMap < > ( ) ; 
        // Initialize a HashMap to store character counts

        for ( int i = 0 ; i < targ.length ; i ++ ) { 
            // Loop through each character in the character array
            if ( ! map.containsKey ( targ [ i ] ) ) { 
                // If the character is not already in the map, add it with a count of 1
                map.put ( targ [ i ] , 1 ) ; 
            } else { 
                // If the character is already in the map, increment its count
                map.put ( targ [ i ] , map.get ( targ [ i ] ) + 1 ) ; 
            } 
        }

        boolean ok = true ; 
        // Initialize a boolean flag to check the conditions

        for ( Entry < Character , Integer > c : map.entrySet ( ) ) { 
            // Loop through each entry in the HashMap
            if ( c.getValue ( ) != 2 ) { 
                // If any character count is not 2, set ok to false and break the loop
                ok = false ; 
                break ; 
            } 
        }

        if ( ok && map.size ( ) == 2 ) { 
            // Check if all characters appear exactly twice and there are exactly 2 unique characters
            System.out.println ( "Yes" ) ; 
            // Print "Yes" if the conditions are met
        } else { 
            System.out.println ( "No" ) ; 
            // Print "No" otherwise
        }

        in.close ( ) ; 
        // Close the Scanner object
    } 
}

