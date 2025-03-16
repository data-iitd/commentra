

#include <stdio.h>
#include <stdlib.h>

int dfs ( int ** links, int n, int k, int v, int p ) {  // Step 1: Define the DFS function
    int height_from_leaf = 0;  // Initialize the height from the leaf node
    int cut_count = 0;  // Initialize the count of cuts
    for ( int i = 0 ; i < n ; i ++ ) {  // Step 2: Traverse the tree
        if ( links [ v ] [ i ] == 0 ) {  // Skip if the node is the root (0)
            continue;
        }
        int hgt = dfs ( links, n, k, i, v );  // Recursively call DFS
        height_from_leaf = ( height_from_leaf > hgt )? height_from_leaf : hgt;  // Update the height from the leaf
        cut_count += hgt;  // Count the number of cuts
    }
    height_from_leaf += 1;  // Increment the height from the leaf node
    if ( p!= 0 && height_from_leaf == k ) {  // Step 3: Check if a cut is needed
        height_from_leaf = 0;  // Reset the height
        cut_count += 1;  // Increment the cut count
    }
    return height_from_leaf;  // Step 4: Return the height
}

int main ( ) {  // Step 5: Read input data
    int n, k;
    scanf ( "%d %d", & n, & k );
    int * * links = ( int * * ) malloc ( sizeof ( int * ) * n );  // Initialize the tree structure
    for ( int i = 0 ; i < n ; i ++ ) {
        links [ i ] = ( int * ) malloc ( sizeof ( int ) * n );
        for ( int j = 0 ; j < n ; j ++ ) {
            links [ i ] [ j ] = 0;
        }
    }
    for ( int i = 0 ; i < n ; i ++ ) {
        int a;
        scanf ( "%d", & a );
        a --;
        links [ a ] [ i ] = 1;
    }
    int ans = dfs ( links, n, k, 0, 0 );  // Step 6: Perform DFS starting from the root
    if ( ans == k ) {  // Step 7: Adjust the answer if necessary
        ans += 1;
    }
    printf ( "%d\n", ans );  // Step 8: Output the final result
    return 0;
}

