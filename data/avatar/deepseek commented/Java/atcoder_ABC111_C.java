
import java.util.Arrays ; 
import java.util.Collections ; 
import java.util.Scanner ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = Integer.parseInt ( sc.next ( ) ) ; // Read the size of the array
        int [ ] v = new int [ 100010 ] ; // Initialize the array to store the values
        for ( int i = 0 ; i < n ; i ++ ) { 
            v [ i ] = Integer.parseInt ( sc.next ( ) ) ; // Read the values into the array
        } 
        Integer [ ] vo = new Integer [ 100010 ] ; // Initialize arrays to count odd and even numbers
        Integer [ ] ve = new Integer [ 100010 ] ; 
        Integer [ ] vt = new Integer [ 100010 ] ; 
        Arrays.fill ( vo , 0 ) ; // Initialize the count arrays to zero
        Arrays.fill ( ve , 0 ) ; 
        Arrays.fill ( vt , 0 ) ; 
        for ( int i = 0 ; i < n ; i ++ ) { 
            vt [ v [ i ] ] ++ ; // Count all numbers
            if ( i % 2 == 0 ) { 
                ve [ v [ i ] ] ++ ; // Count even numbers
            } else { 
                vo [ v [ i ] ] ++ ; // Count odd numbers
            } 
        } 
        Arrays.sort ( vo , Collections.reverseOrder ( ) ) ; // Sort the count arrays in descending order
        Arrays.sort ( ve , Collections.reverseOrder ( ) ) ; 
        Arrays.sort ( vt , Collections.reverseOrder ( ) ) ; 
        int ans = 0 ; 
        if ( vo [ 0 ] + ve [ 0 ] == vt [ 0 ] ) { // Check if the maximum counts are consecutive
            ans = Math.min ( n - vo [ 0 ] - ve [ 1 ] , n - vo [ 1 ] - ve [ 0 ] ) ; // Calculate the minimum difference
        } else { 
            ans = n - vo [ 0 ] - ve [ 0 ] ; // Calculate the difference if not consecutive
        } 
        System.out.println ( ans ) ; // Print the result
        sc.close ( ) ; // Close the scanner
    } 
}

