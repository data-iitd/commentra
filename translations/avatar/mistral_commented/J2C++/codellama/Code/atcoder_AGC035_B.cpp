
#include <iostream>
#include <vector>
#include <string>

using namespace std ;

// Importing the utility class Scanner for reading input from the standard input stream.

int main ( ) {
    int numNode ; // Declaring the number of nodes variable.
    int numEdge ; // Declaring the number of edges variable.
    cin >> numNode >> numEdge ; // Reading the number of nodes and edges from the input.

    // Initializing the connect array to store the list of neighbors for each node.
    vector < vector < int > > connect ( numNode ) ;
    for ( int i = 0 ; i < numNode ; i ++ ) {
        connect [ i ] = vector < int > ( ) ;
    }

    // Reading the edges and adding them to the connect array.
    for ( int i = 0 ; i < numEdge ; i ++ ) {
        int a , b ; // Declaring the first and second node indices.
        cin >> a >> b ; // Reading the first and second node indices from the input.
        connect [ a - 1 ].push_back ( b - 1 ) ; // Adding the second node index to the first node's list of neighbors.
        connect [ b - 1 ].push_back ( a - 1 ) ; // Adding the first node index to the second node's list of neighbors.
    }

    // Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
    if ( numEdge % 2 != 0 ) {
        cout << - 1 << endl ;
        return 0 ;
    }

    // Initializing the visited, odd, and print arrays and objects.
    vector < int > visited ( numNode , 0 ) ;
    vector < bool > odd ( numNode , false ) ;
    string print ;

    // Calling the dfs method with the first node and -1 as the parent node.
    dfs ( 0 , - 1 ) ;

    // Printing the output.
    cout << print << endl ;
    return 0 ;
}

// Recursive depth-first search method to perform bipartite traversal.
void dfs ( int crt , int parent ) {
    // Marking the current node as visited.
    visited [ crt ] = 1 ;

    // Iterating through the neighbors of the current node.
    vector < int > crtConnect = connect [ crt ] ;
    for ( int child : crtConnect ) {
        // Skipping the neighbor if it is the parent node or already visited.
        if ( child == parent || visited [ child ] == 1 ) {
            continue ;
        }

        // If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
        // Otherwise, we swap the components and continue the traversal.
        if ( visited [ child ] == 2 ) {
            print += to_string ( crt + 1 ) + " " + to_string ( child + 1 ) + "\n" ;
            odd [ crt ] = ! odd [ crt ] ;
        } else {
            dfs ( child , crt ) ;
            if ( odd [ child ] ) {
                print += to_string ( child + 1 ) + " " + to_string ( crt + 1 ) + "\n" ;
                odd [ child ] = ! odd [ child ] ;
            } else {
                print += to_string ( crt + 1 ) + " " + to_string ( child + 1 ) + "\n" ;
                odd [ crt ] = ! odd [ crt ] ;
            }
        }
    }

    // Marking the current node as visited with component 2.
    visited [ crt ] = 2 ;
}

