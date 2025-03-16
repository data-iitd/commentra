
import java.io.BufferedReader ; 
import java.io.IOException ; 
import java.io.InputStreamReader ; 
import java.util.ArrayList ; 
import java.util.HashMap ; 

public class Main { 
    public static void main ( String [ ] args ) throws IOException { 
        // Create a BufferedReader to read input from the standard input
        BufferedReader reader = new BufferedReader ( new InputStreamReader ( System.in ) ) ; 
        
        // Read the input and split it into an array of strings
        String input [ ] = reader.readLine ( ).split ( " " ) ; 
        
        // Parse the required integers from the input
        int m = Integer.parseInt ( input [ 1 ] ) ; 
        int s = Integer.parseInt ( input [ 2 ] ) ; 
        int f = Integer.parseInt ( input [ 3 ] ) ; 
        
        // Initialize the maximum time and a HashMap to store the intervals
        int maxT = - 1 ; 
        HashMap < Integer , ArrayList < Integer >> map = new HashMap < > ( ) ; 
        
        // Read the intervals from the input and store them in the HashMap
        while ( m > 0 ) { 
            String mth [ ] = reader.readLine ( ).split ( " " ) ; 
            int k = Integer.parseInt ( mth [ 0 ] ) ; 
            map.put ( k , new ArrayList < > ( ) ) ; 
            map.get ( k ).add ( Integer.parseInt ( mth [ 1 ] ) ) ; 
            map.get ( k ).add ( Integer.parseInt ( mth [ 2 ] ) ) ; 
            maxT = Math.max ( maxT , k ) ; 
            m -- ; 
        } 
        
        // Initialize a StringBuilder to build the sequence of actions
        StringBuilder actions = new StringBuilder ( ) ; 
        
        // Determine the direction of movement and initialize the current position
        final char M = ( s < f ) ? 'R' : 'L' ; 
        int d = ( s < f ) ? + 1 : - 1 ; 
        int cur = s ; 
        
        // Variables to store the current interval's start and end
        int a = - 1 ; 
        int b = - 1 ; 
        
        // Build the sequence of actions based on the intervals and the current position
        for ( int t = 1 ; t <= maxT ; t ++ ) { 
            if ( map.containsKey ( t ) ) { 
                a = map.get ( t ).get ( 0 ).intValue ( ) ; 
                b = map.get ( t ).get ( 1 ).intValue ( ) ; 
            } 
            if ( map.containsKey ( t ) && ( ( cur >= a && cur <= b ) || ( cur + d >= a && cur + d <= b ) ) ) { 
                actions.append ( 'X' ) ; 
            } else { 
                actions.append ( M ) ; 
                cur += d ; 
            } 
            if ( cur == f ) break ; 
        } 
        
        // Continue moving in the determined direction until reaching the final position
        while ( cur != f ) { 
            actions.append ( M ) ; 
            cur += d ; 
        } 
        
        // Print the sequence of actions
        System.out.println ( actions ) ; 
    } 
}