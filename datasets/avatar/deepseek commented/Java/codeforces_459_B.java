import java.io.* ; 
import java.util.* ; 

public class Main { 
    public static void main ( String [ ] args ) { 
        Scanner in = new Scanner ( System.in ) ; 
        PrintWriter pw = new PrintWriter ( System.out ) ; 

        // Read the size of the array
        int N = in.nextInt() ; 

        // Read the elements of the array
        int [ ] A = new int [ N ] ; 
        for ( int n = 0 ; n < N ; n ++ ) { 
            A [ n ] = in.nextInt() ; 
        }

        // Sort the array
        Arrays.sort(A) ; 

        // Find the minimum and maximum values in the array
        int min = A [ 0 ] ; 
        int max = A [ N - 1 ] ; 

        // Count the occurrences of the minimum and maximum values
        long mins = 0 ; 
        long maxs = 0 ; 
        for ( int value : A ) { 
            if ( value == min ) mins ++ ; 
            if ( value == max ) maxs ++ ; 
        }

        // Special case: if min == max
        if ( min == max ) { 
            pw.println ( ( max - min ) + " " + mins * ( mins - 1 ) / 2 ) ; 
        } else { 
            // General case: if min != max
            pw.println ( ( max - min ) + " " + mins * maxs ) ; 
        }

        // Close the PrintWriter to flush the output
        pw.close() ; 
    }

    // Debugging method to print debug statements
    static void debug ( Object...obj ) { 
        System.err.println( Arrays.deepToString ( obj ) ) ; 
    }
}
