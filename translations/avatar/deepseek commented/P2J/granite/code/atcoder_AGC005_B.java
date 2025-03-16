
// Define the root function to find the root of a given element in a disjoint set
int root ( int x ) {
    return x == par [ x ]? x : ( par [ x ] = root ( par [ x ] ) );
}

// Define the same function to check if two elements are in the same set
boolean same ( int x, int y ) {
    return root ( x ) == root ( y );
}

// Define the unite function to merge two sets containing the given elements
void unite ( int... z ) {
    int x = root ( z [ 0 ] ), y = root ( z [ 1 ] );
    if ( x!= y ) {
        if ( rank [ x ] < rank [ y ] ) {
            par [ x ] = y;
            size [ y ] += size [ x ];
        } else {
            par [ y ] = x;
            size [ x ] += size [ y ];
            if ( rank [ x ] == rank [ y ] ) rank [ x ] += 1;
        }
    }
}

// Read the input, initialize the disjoint set, and process the array
Scanner in = new Scanner ( System. in );
int n = in.nextInt ( );
int[] par = new int [ n ];
int[] rank = new int [ n ];
int[] size = new int [ n ];
int[] b = new int [ n ];
for ( int i = 0 ; i < n ; i ++ ) {
    int t = in.nextInt ( ) - 1;
    b [ t ] = i;
}
long c = 0;

// Process the array in reverse order to calculate the result
for ( int k = n - 1 ; k >= 0 ; k -- ) {
    int l = r = 1;
    if ( k > 0 && b [ k - 1 ] > b [ k ] ) {
        l += size [ root ( k - 1 ) ];
        unite ( k - 1, k );
    }
    if ( k + 1 < n && b [ k + 1 ] > b [ k ] ) {
        r += size [ root ( k + 1 ) ];
        unite ( k + 1, k );
    }
    c += ( long ) l * r * ( b [ k ] + 1 );
}

// Print the final result
System.out.println ( c );
