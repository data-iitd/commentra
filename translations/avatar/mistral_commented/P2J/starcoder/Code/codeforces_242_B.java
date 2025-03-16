// Import necessary Java libraries
import java.util.*;

// Define lambda functions for reading input
Supplier<Integer> I = ( ) -> Integer.parseInt ( new BufferedReader ( new InputStreamReader ( System.in ) ).readLine ( ) );
Supplier<String> IS = ( ) -> new BufferedReader ( new InputStreamReader ( System.in ) ).readLine ( );
Function<String, Integer> IN = ( x ) -> Integer.parseInt ( x );
Function<String, Double> IF = ( x ) -> Double.parseDouble ( x );

// Read the number of test cases
int n = IN.apply ( IS.get ( ) );

// Initialize id variable to 0
int id = 0;

// Read left and right boundary values for the first test case
int l = I.get ( ), r = I.get ( );

// Iterate through the remaining test cases
for ( int i = 1 ; i < n ; i++ ) {
    // Read left and right boundary values for the current test case
    int li = I.get ( ), ri = I.get ( );

    // Check if the current test case overlaps with the previously defined boundary values
    if ( li <= l && r <= ri ) {
        // Update id variable to the index of the current test case
        id = i;
    }

    // If the current test case does not overlap, keep id as n
    else if ( li < l || r < ri ) {
        id = n;
    }

    // Update boundary values based on the current test case
    l = Math.min ( l, li );
    r = Math.max ( r, ri );
}

// Print the index of the test case that satisfies the condition, or -1 if no such test case exists
System.out.println ( -1 if id == n else id + 1 );

