
import java.util.* ; 
import java.io.* ; 

public class Main { 
    public static void main ( String args [ ] ) throws IOException { 
        Scanner sc = new Scanner ( System.in ) ; 
        int n = sc.nextInt ( ) ; // Read the size of the array
        int arr [ ] = new int [ n ] ; 
        arr [ 0 ] = sc.nextInt ( ) ; // Initialize the first element of the array

        // Read the rest of the elements and calculate the prefix sum
        for ( int i = 1 ; i < n ; i ++ ) { 
            int x = sc.nextInt ( ) ; 
            arr [ i ] = x + arr [ i - 1 ] ; 
        } 

        int m = sc.nextInt ( ) ; // Read the number of queries
        int q [ ] = new int [ m ] ; 

        // Read the queries
        for ( int i = 0 ; i < m ; i ++ ) { 
            q [ i ] = sc.nextInt ( ) ; 
        } 

        // Perform binary search for each query and print the result adjusted by +1
        for ( int k = 0 ; k < m ; k ++ ) { 
            System.out.println ( fun ( arr , q [ k ] , n , m ) + 1 ) ; 
        } 
    } 

    // Binary search function to find the position of q in arr
    static int fun ( int arr [ ] , int q , int n , int m ) { 
        int res = 0 ; 
        int i = 0 , j = n ; 
        while ( i <= j ) { 
            int md = i + ( j - i ) / 2 ; 
            if ( arr [ md ] == q ) return md ; 
            else if ( arr [ md ] > q ) { 
                res = md ; 
                j = md - 1 ; 
            } else { 
                i = md + 1 ; 
            } 
        } 
        return res ; 
    } 
}
