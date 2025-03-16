import java.util.* ; 

public class Main { 
    // Define a constant for modulo operations
    final static long mod = 1000000007 ; 

    public static void main ( String [ ] args ) { 
        // Create a Scanner object to read input
        Scanner sc = new Scanner ( System.in ) ; 

        // Read the length of the string and the number of queries
        int n = sc.nextInt ( ) ; 
        int q = sc.nextInt ( ) ; 

        // Read the string as a character array
        char [ ] c = sc.next ( ).toCharArray ( ) ; 

        // Read the ranges for the queries and store them in a 2D array
        int [ ] [ ] range = new int [ q ] [ 2 ] ; 
        for ( int i = 0 ; i < q ; i ++ ) { 
            range [ i ] [ 0 ] = sc.nextInt ( ) ; 
            range [ i ] [ 1 ] = sc.nextInt ( ) ; 
        } 

        // Initialize arrays to count "AC" fragments and store cumulative sums
        int [ ] frag = new int [ n + 1 ] ; 
        int [ ] rui = new int [ n + 1 ] ; 

        // Process the string to find "AC" fragments
        for ( int i = 2 ; i <= n ; i ++ ) { 
            if ( c [ i - 2 ] == 'A' && c [ i - 1 ] == 'C' ) { 
                // Increment the count of "AC" fragments at position i
                frag [ i ] ++ ; 
            } 
            // Update the cumulative sum array
            rui [ i ] = rui [ i - 1 ] + frag [ i ] ; 
        } 

        // Process the queries
        for ( int i = 0 ; i < q ; i ++ ) { 
            int left = range [ i ] [ 0 ] ; 
            int right = range [ i ] [ 1 ] ; 
            // Calculate the number of "AC" fragments in the given range
            System.out.println ( rui [ right ] - rui [ left ] ) ; 
        } 
    } 
}
