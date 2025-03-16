
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the graph is bipartite.
int checkBipartite ( int numNode, int numEdge, int connect [ ] [ ] ) {
    // Initializing the visited array and odd array.
    int visited [ numNode ] ;
    int odd [ numNode ] ;

    // Initializing the print array.
    char print [ numNode * numNode * 10 ] ;
    int printIndex = 0 ;

    // Iterating through the nodes.
    for ( int crt = 0 ; crt < numNode ; crt ++ ) {
        // Initializing the visited and odd arrays for the current node.
        memset ( visited, 0, sizeof ( visited ) ) ;
        memset ( odd, 0, sizeof ( odd ) ) ;

        // Calling the dfs function with the current node and -1 as the parent node.
        dfs ( crt, - 1, numNode, numEdge, connect, visited, odd, print, & printIndex ) ;

        // If the number of edges is odd, then the graph is not bipartite, and we return -1.
        if ( printIndex % 2!= 0 ) {
            return - 1 ;
        }
    }

    // Printing the output.
    printf ( "%s", print ) ;

    // Returning 0 to indicate that the graph is bipartite.
    return 0 ;
}

// Recursive depth-first search function to perform bipartite traversal.
void dfs ( int crt, int parent, int numNode, int numEdge, int connect [ ] [ ], int visited [ ], int odd [ ], char print [ ], int * printIndex ) {
    // Marking the current node as visited.
    visited [ crt ] = 1 ;

    // Iterating through the neighbors of the current node.
    for ( int child = 0 ; child < numNode ; child ++ ) {
        // Skipping the neighbor if it is the parent node or already visited.
        if ( child == parent || visited [ child ] == 1 ) {
            continue ;
        }

        // If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
        // Otherwise, we swap the components and continue the traversal.
        if ( visited [ child ] == 2 ) {
            print [ * printIndex ] = ( crt + 48 ) ;
            print [ * printIndex + 1 ] = ( child + 48 ) ;
            print [ * printIndex + 2 ] = ( 10 ) ;
            * printIndex += 3 ;
            odd [ crt ] =! odd [ crt ] ;
        } else {
            dfs ( child, crt, numNode, numEdge, connect, visited, odd, print, printIndex ) ;
            if ( odd [ child ] ) {
                print [ * printIndex ] = ( child + 48 ) ;
                print [ * printIndex + 1 ] = ( crt + 48 ) ;
                print [ * printIndex + 2 ] = ( 10 ) ;
                * printIndex += 3 ;
                odd [ child ] =! odd [ child ] ;
            } else {
                print [ * printIndex ] = ( crt + 48 ) ;
                print [ * printIndex + 1 ] = ( child + 48 ) ;
                print [ * printIndex + 2 ] = ( 10 ) ;
                * printIndex += 3 ;
                odd [ crt ] =! odd [ crt ] ;
            }
        }
    }

    // Marking the current node as visited with component 2.
    visited [ crt ] = 2 ;
}

// Driver code.
int main ( ) {
    // Reading the number of nodes and edges from the input.
    int numNode, numEdge ;
    scanf ( "%d %d", & numNode, & numEdge ) ;

    // Initializing the connect array to store the list of neighbors for each node.
    int connect [ numNode ] [ numNode ] ;
    for ( int i = 0 ; i < numNode ; i ++ ) {
        for ( int j = 0 ; j < numNode ; j ++ ) {
            connect [ i ] [ j ] = 0 ;
        }
    }

    // Reading the edges and adding them to the connect array.
    for ( int i = 0 ; i < numEdge ; i ++ ) {
        int a, b ;
        scanf ( "%d %d", & a, & b ) ;
        connect [ a - 1 ] [ b - 1 ] = 1 ;
        connect [ b - 1 ] [ a - 1 ] = 1 ;
    }

    // Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
    if ( numEdge % 2!= 0 ) {
        printf ( "-1" ) ;
        return 0 ;
    }

    // Checking if the graph is bipartite.
    if ( checkBipartite ( numNode, numEdge, connect ) == - 1 ) {
        printf ( "-1" ) ;
    }

    // Returning 0 to indicate successful execution.
    return 0 ;
}

