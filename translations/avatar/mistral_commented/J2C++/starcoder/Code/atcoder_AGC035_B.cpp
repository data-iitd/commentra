
#include <bits/stdc++.h>

using namespace std ;

// Function to check if the graph is bipartite or not.
bool isBipartite ( int numNode, int numEdge ) {
    // Initializing the connect array to store the list of neighbors for each node.
    vector < vector < int > > connect ( numNode, vector < int > ( ) ) ;

    // Reading the edges and adding them to the connect array.
    for ( int i = 0 ; i < numEdge ; i ++ ) {
        int a, b ;
        cin >> a >> b ;
        connect [ a - 1 ].push_back ( b - 1 ) ;
        connect [ b - 1 ].push_back ( a - 1 ) ;
    }

    // Initializing the visited, odd, and print arrays and objects.
    vector < int > visited ( numNode, 0 ) ;
    vector < bool > odd ( numNode, false ) ;
    string print ;

    // Calling the dfs method with the first node and -1 as the parent node.
    dfs ( 0, - 1, connect, visited, odd, print ) ;

    // Returning true if the number of edges is odd.
    return ( numEdge % 2 == 0 ) ;
}

// Recursive depth-first search method to perform bipartite traversal.
void dfs ( int crt, int parent, vector < vector < int > > & connect, vector < int > & visited, vector < bool > & odd, string & print ) {
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
            odd [ crt ] =! odd [ crt ] ;
        } else {
            dfs ( child, crt, connect, visited, odd, print ) ;
            if ( odd [ child ] ) {
                print += to_string ( child + 1 ) + " " + to_string ( crt + 1 ) + "\n" ;
                odd [ child ] =! odd [ child ] ;
            } else {
                print += to_string ( crt + 1 ) + " " + to_string ( child + 1 ) + "\n" ;
                odd [ crt ] =! odd [ crt ] ;
            }
        }
    }

    // Marking the current node as visited with component 2.
    visited [ crt ] = 2 ;
}

// Main function where the program starts execution.
int main ( ) {
    int numNode, numEdge ;
    cin >> numNode >> numEdge ;

    // Checking if the graph is bipartite or not.
    if ( isBipartite ( numNode, numEdge ) ) {
        cout << print ;
    } else {
        cout << - 1 ;
    }

    return 0 ;
}

