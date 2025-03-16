

#include < stdio.h >
#include < stdlib.h >

// Function to print the output.
void printOutput ( int numNode, int numEdge, int connect [ ] [ ], int visited [ ], int odd [ ] ) {
    for ( int i = 0 ; i < numEdge ; i ++ ) {
        printf ( "%d %d\n", connect [ i ] [ 0 ] + 1, connect [ i ] [ 1 ] + 1 ) ;
    }
}

// Recursive depth-first search method to perform bipartite traversal.
void dfs ( int crt, int parent, int numNode, int connect [ ] [ ], int visited [ ], int odd [ ] ) {
    visited [ crt ] = 1 ;
    for ( int i = 0 ; i < numNode ; i ++ ) {
        if ( connect [ crt ] [ i ] == 1 && i!= parent ) {
            if ( visited [ i ] == 2 ) {
                printf ( "%d %d\n", i + 1, crt + 1 ) ;
                odd [ crt ] =! odd [ crt ] ;
            } else {
                dfs ( i, crt, numNode, connect, visited, odd ) ;
                if ( odd [ i ] ) {
                    printf ( "%d %d\n", i + 1, crt + 1 ) ;
                    odd [ i ] =! odd [ i ] ;
                } else {
                    printf ( "%d %d\n", crt + 1, i + 1 ) ;
                    odd [ crt ] =! odd [ crt ] ;
                }
            }
        }
    }
    visited [ crt ] = 2 ;
}

// Main method where the program starts execution.
int main ( ) {
    int numNode, numEdge ;
    scanf ( "%d %d", & numNode, & numEdge ) ;
    int connect [ numEdge ] [ numNode ] ;
    for ( int i = 0 ; i < numEdge ; i ++ ) {
        for ( int j = 0 ; j < numNode ; j ++ ) {
            scanf ( "%d", & connect [ i ] [ j ] ) ;
        }
    }
    int visited [ numNode ] ;
    int odd [ numNode ] ;
    dfs ( 0, - 1, numNode, connect, visited, odd ) ;
    printOutput ( numNode, numEdge, connect, visited, odd ) ;
    return 0 ;
}

These comments should provide a clear understanding of the logic behind each block of code in the given C program.