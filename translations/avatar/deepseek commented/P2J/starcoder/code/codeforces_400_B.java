
import java.util.*;
import java.io.*;

public class Main {

    public static void main ( String [ ] args ) throws Exception {

        Scanner sc = new Scanner ( System.in );

        int n = sc.nextInt ( );
        int m = sc.nextInt ( );
        // Read the dimensions of the grid (n: number of rows, m: number of columns)

        Set < Integer > c = new HashSet < > ( );
        for ( int i = 0; i < n; i++ ) {
            int s = sc.next ( ).indexOf ( 'S' );
            int g = sc.next ( ).indexOf ( 'G' );
            // For each of the n rows, read the string and find the index of 'S' and 'G'.
            c.add ( s - g );
            // Calculate the difference between the indices of 'S' and 'G' for each row.
            // Store these differences in a set 'c'.
        }

        System.out.println ( c.contains ( -1 )? -1 : c.size ( ) );
        // Check if there is any negative difference in the set 'c'.
        // If there is, print '-1'. Otherwise, print the number of unique non-negative differences.

    }

}

