
import java.io.PrintWriter ; import java.util.* ; import java.util.stream.Collectors ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        try ( Scanner in = new Scanner ( System.in ) ; 
              PrintWriter out = new PrintWriter ( System.out ) ) { 
            int n = in.nextInt ( ) ; // Read the number of integers
            List < Integer > a = new ArrayList < > ( ) ; // Create a list to store the integers
            for ( int i = 0 ; i < n ; i ++ ) { 
                int value = in.nextInt ( ) ; // Read each integer value
                a.add ( value ) ; // Add the value to the list
            } 
            a = a.stream ( ).distinct ( ).sorted ( ).collect ( Collectors.toList ( ) ) ; 
            // Remove duplicates and sort the list
            boolean found = false ; // Initialize a flag to check for consecutive integers
            for ( int i = 0 ; i < a.size ( ) ; i ++ ) { 
                if ( i + 1 < a.size ( ) && i + 2 < a.size ( ) ) { 
                    if ( a.get ( i ) + 1 == a.get ( i + 1 ) && a.get ( i + 1 ) + 1 == a.get ( i + 2 ) ) { 
                        found = true ; // Set the flag if three consecutive integers are found
                    } 
                } 
            } 
            out.println ( found ? "YES" : "NO" ) ; // Print "YES" if consecutive integers are found, otherwise print "NO"
        } 
    } 
}
