
import java.util.* ;

// Initialize scanner for user input
public class Main {

    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ;
        // Read the number of slimes N from user input
        int N = sc.nextInt ( ) ;
        // Calculate the size of the array S based on N
        int size = ( 1 << N ) ;
        // Initialize the array S with user input
        int [ ] S = new int [ size ] ;
        // Initialize a boolean array spawned to keep track of which slimes have been spawned
        boolean [ ] spawned = new boolean [ size ] ;
        // Set the last element of spawned to true, as it represents the position of the last slime
        spawned [ size - 1 ] = true ;

        // Read the initial positions of slimes from user input and store them in array S
        for ( int i = 0 ; i < size ; i ++ ) {
            S [ i ] = sc.nextInt ( ) ;
        }
        // Sort the array S in ascending order
        Arrays.sort ( S ) ;

        // Initialize an ArrayList named active to store the indices of the currently active slimes
        List < Integer > active = new ArrayList < > ( ) ;
        // Set the last element of spawned to true and add its index to the active list
        active.add ( size - 1 ) ;
        spawned [ size - 1 ] = true ;

        // Iterate through each generation of slimes
        for ( int i = 0 ; i < N ; i ++ ) {
            // Sort the ArrayList active in descending order
            active.sort ( Collections.reverseOrder ( ) ) ;

            // Initialize an ArrayList named activated to store the indices of the slimes that will be activated in the next generation
            List < Integer > activated = new ArrayList < > ( ) ;
            // Initialize a variable named next to keep track of the index of the current slime in array S
            int next = size - 1 ;

            // Iterate through each slime in the current generation
            for ( int slime : active ) {
                // While the current index next is greater than or equal to 0 and the slime size is greater than or equal to the size of the current slime or the current index has already been spawned
                while ( next >= 0 && ( S [ next ] >= slime || spawned [ next ] ) ) {
                    next -- ;
                }
                // If the current index next is less than 0, it means that there is no empty space for the new slime to spawn, so print "No" and exit the program
                if ( next < 0 ) {
                    System.out.println ( "No" ) ;
                    return ;
                }
                // Set the current index as spawned and add its index to the activated ArrayList
                spawned [ next ] = true ;
                activated.add ( S [ next ] ) ;
            }
            // Add all the indices of the activated slimes to the active ArrayList
            active.addAll ( activated ) ;
        }

        // Print "Yes" to indicate that the program has successfully determined the positions of all N slimes
        System.out.println ( "Yes" ) ;
    }
}