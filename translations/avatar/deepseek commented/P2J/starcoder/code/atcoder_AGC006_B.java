// Read N and X from input
Scanner sc = new Scanner ( System.in );
int N = sc.nextInt ( );
int X = sc.nextInt ( );

// Import the permutations function from itertools
import static java.util.stream.Collectors.toList;
import java.util.List;
import java.util.stream.IntStream;

// Define the calc function which processes a list x
static int calc ( List < Integer > x ) {
    // Define a nested sub function within calc for further processing
    static int sub ( List < Integer > y, boolean debug ) {
        // Print the current state of y if debug mode is on
        if ( debug ) {
            System.out.println ( "D" + y );
        }
        // Reduce y by repeatedly taking triplets, sorting them, and keeping the middle element
        while ( y.size ( ) > 1 ) {
            y = IntStream.range ( 0, y.size ( ) - 2 ).mapToObj ( i -> y.get ( i + 1 ) ).sorted ( ).collect ( toList ( ) );
            // Print the current state of y if debug mode is on
            if ( debug ) {
                System.out.println ( "D" + y );
            }
        }
        // Return the final single element of y
        return y.get ( 0 );
    }
    // Process the input list x using sub function
    int y = sub ( x, true );
    // Check if the final element of y is 2
    if ( y == 2 ) {
        // Call sub again with debug mode on and print the result
        sub ( x, true );
        System.out.println ( "=" + x );
    }
    // Return the first element of the final y
    return y;
}

// Check if X is 1 or N * 2 - 1, print "No" if true
if ( X == 1 || X == N * 2 - 1 ) {
    System.out.println ( "No" );
} else {
    // Print "Yes" if X is not 1 or N * 2 - 1
    System.out.println ( "Yes" );
    // Construct the list xs based on the value of X
    List < Integer > xs;
    if ( X == N * 2 - 2 ) {
        xs = IntStream.range ( N - 1, X + 2 ).boxed ( ).collect ( toList ( ) );
        xs.addAll ( IntStream.range ( 1, N - 1 ).boxed ( ).collect ( toList ( ) ) );
    } else {
        List < Integer > ys = IntStream.range ( 1, X - 1 ).boxed ( ).collect ( toList ( ) );
        ys.addAll ( IntStream.range ( X + 3, N * 2 ).boxed ( ).collect ( toList ( ) ) );
        xs = ys.subList ( 0, N - 3 );
        xs.addAll ( Arrays.asList ( X + 2, X - 1, X, X + 1 ) );
        xs.addAll ( ys.subList ( N - 3, ys.size ( ) ) );
    }
    // Print each element of xs
    for ( int x : xs ) {
        System.out.println ( x );
    }
}

