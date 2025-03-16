
import java.io.BufferedReader ; import java.io.InputStreamReader ; import java.io.IOException ; import java.util.Arrays ; import java.util.TreeMap ; 

public class Main {
    private int n ; // Number of elements in the array
    private int [ ] a ; // The array itself
    private TreeMap < Integer , Integer > s ; // TreeMap to keep track of counts of elements

    public static void main ( String [ ] args ) {
        Main m = new Main ( ) ;
        m.solve ( ) ;
    }

    // Reads input values for n and the array a
    private void set ( ) {
        try ( BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) ) ) {
            n = Integer.parseInt ( br.readLine ( ) ) ;
            a = Arrays.stream ( br.readLine ( ).split ( " " ) ).mapToInt ( Integer :: parseInt ).toArray ( ) ;
            s = new TreeMap < > ( ) ;
        } catch ( IOException e ) {
            e.printStackTrace ( ) ;
        }
    }

    // Solves the problem by finding the maximum k such that the array can be partitioned into k non-empty subarrays
    private void solve ( ) {
        set ( ) ;
        int ng = 0 ; // Lower bound for binary search
        int ok = n ; // Upper bound for binary search
        while ( ok - ng > 1 ) {
            int k = ( ng + ok ) / 2 ; // Midpoint of the current search range
            if ( isPossible ( k ) ) {
                ok = k ; // Adjust the upper bound if k is possible
            } else {
                ng = k ; // Adjust the lower bound if k is not possible
            }
        }
        System.out.println ( ok ) ; // Print the result of the binary search
    }

    // Checks if it is possible to partition the array into k subarrays
    private boolean isPossible ( int k ) {
        s.clear ( ) ; // Clear the TreeMap for each new k
        int current = 0 ; // Current index in the array
        for ( int ai : a ) {
            if ( ai <= current ) { // Check if the current element can be part of the previous subarray
                if ( k == 1 ) return false ; // If k is 1, it's not possible to partition
                while ( ! s.isEmpty ( ) && s.lastKey ( ) >= ai ) s.pollLastEntry ( ) ; // Remove elements from the TreeMap that are greater than or equal to the current element
                int p = ai - 1 ; // Start checking from the previous element
                while ( true ) {
                    if ( p < 0 ) return false ; // If p goes below 0, it's not possible to partition
                    int sp = s.getOrDefault ( p , 0 ) + 1 ; // Get or default the count of p and add 1
                    s.put ( p , sp ) ; // Put the updated count back into the TreeMap
                    if ( sp == k ) { // If the count of p is equal to k
                        s.remove ( p ) ; // Remove p from the TreeMap
                        p -- ; // Move to the previous element
                    } else {
                        break ; // Break the loop if the count is not equal to k
                    }
                }
            }
            current = ai ; // Update the current element
        }
        return true ; // Return true if it's possible to partition the array into k subarrays
    }
}

