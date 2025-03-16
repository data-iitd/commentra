// Import necessary Java libraries
import java.io.*;
import java.util.*;

// Define lambda functions for reading input
static BufferedReader br = new BufferedReader ( new InputStreamReader ( System.in ) );
static StringTokenizer st = new StringTokenizer ( "", " " );
static String nextToken ( ) throws IOException {
    while ( ! st.hasMoreTokens ( ) ) {
        st = new StringTokenizer ( br.readLine ( ), " " );
    }
    return st.nextToken ( );
}
static int nextInt ( ) throws IOException {
    return Integer.parseInt ( nextToken ( ) );
}
static long nextLong ( ) throws IOException {
    return Long.parseLong ( nextToken ( ) );
}
static double nextDouble ( ) throws IOException {
    return Double.parseDouble ( nextToken ( ) );
}

// Read the number of test cases
int n = nextInt ( );

// Initialize id variable to 0
int id = 0;

// Read left and right boundary values for the first test case
int l = nextInt ( );
int r = nextInt ( );

// Iterate through the remaining test cases
for ( int i = 1 ; i < n ; i++ ) {
    // Read left and right boundary values for the current test case
    int li = nextInt ( );
    int ri = nextInt ( );

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
System.out.println ( -1 == id ? n : id + 1 );

