
import java.util.*;

public class Editorial {

    public static void main ( String [ ] args ) {
        // Read the number of elements N
        Scanner sc = new Scanner ( System.in );
        int N = sc.nextInt ( );
        // Read the list of integers P
        int [ ] P = new int [ N ];
        for ( int i = 0 ; i < N ; i++ ) {
            P [ i ] = sc.nextInt ( );
        }
        // Call the editorial function with N and P as arguments
        editorial ( N, P );
    }

    public static void editorial ( int N, int [ ] P ) {
        // If there is only one element, print 0 and return
        if ( N == 1 ) {
            System.out.println ( 0 );
            return;
        }
        // Initialize an array to store positions of elements in P
        int [ ] a = new int [ N + 1 ];
        // Populate the array with positions of elements in P
        for ( int i = 0 ; i < N ; i++ ) {
            a [ P [ i ] ] = i;
        }
        // Initialize temporary and maximum length variables
        int tmp = 1;
        int max_len = 1;
        // Iterate through the positions to find the maximum length of consecutive increasing elements
        for ( int i = 1 ; i < N ; i++ ) {
            if ( a [ i ] < a [ i + 1 ] ) {
                tmp += 1;
                max_len = Math.max ( max_len, tmp );
            } else {
                tmp = 1;
            }
        }
        // Calculate the answer as N - max_len
        int ans = N - max_len;
        // Print the answer
        System.out.println ( ans );
    }
}

