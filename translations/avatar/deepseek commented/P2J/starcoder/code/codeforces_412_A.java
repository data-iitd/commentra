
import java.util.Scanner;

public class Main {

    public static void main ( String [ ] args ) {

        Scanner sc = new Scanner ( System.in );

        int n = sc.nextInt ( );
        // Input the number of elements (n)

        int k = sc.nextInt ( );
        // Input the position index (k)

        String v = sc.next ( );
        // Input the string v

        String [ ] d = { "LEFT", "RIGHT" };
        // Define a list containing the directions "LEFT" and "RIGHT"

        boolean f = k - 1 < n - k;
        // Determine the boolean value of f based on the comparison between k-1 and n-k

        int m = Math.min ( k - 1, n - k );
        // Assign m as the minimum of k-1 and n-k

        String [ ] a = new String [ m * 2 + 1 ];
        // Initialize an empty list a to store the sequence of actions

        for ( int i = 0 ; i < m ; i ++ )
            a [ i ] = d [! f ];
        // Append the opposite direction to a based on the value of f

        for ( int i = v.length ( ) - 1 ; i >= 0 ; i -= 2 * f - 1 )
            a [ m + i / ( 2 * f - 1 ) * 2 ] = "PRINT " + v.charAt ( i );
        // Iterate over the reversed string v with a step of 2*f-1, appending "PRINT" and the current character, followed by the direction f

        for ( int i = 0 ; i < a.length ; i ++ )
            System.out.println ( a [ i ] );
        // Print all elements in a except the last one, separated by newlines

    }

}

