

#include <bits/stdc++.h>

using namespace std;

// Static array to store the connectivity information for each node.
static vector < int > connect [ ] ;

// Static arrays to store the visited status and odd component for each node.
static int visited [ ] ;
static bool odd [ ] ;

// Static StringBuilder object to store the output.
static stringstream print ;

// Recursive depth-first search method to perform bipartite traversal.
static void dfs ( int crt, int parent ) {
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
            print << ( crt + 1 ) << " " << ( child + 1 ) << "\n" ;
            odd [ crt ] =! odd [ crt ] ;
        } else {
            dfs ( child, crt ) ;
            if ( odd [ child ] ) {
                print << ( child + 1 ) << " " << ( crt + 1 ) << "\n" ;
                odd [ child ] =! odd [ child ] ;
            } else {
                print << ( crt + 1 ) << " " << ( child + 1 ) << "\n" ;
                odd [ crt ] =! odd [ crt ] ;
            }
        }
    }

    // Marking the current node as visited with component 2.
    visited [ crt ] = 2 ;
}

int main ( ) {
    int numNode, numEdge ;
    cin >> numNode >> numEdge ;

    // Initializing the connect array to store the list of neighbors for each node.
    connect = vector < int > [ numNode ] ;
    for ( int i = 0 ; i < numNode ; i ++ ) {
        connect [ i ] = vector < int > ( ) ;
    }

    // Reading the edges and adding them to the connect array.
    for ( int i = 0 ; i < numEdge ; i ++ ) {
        int a, b ;
        cin >> a >> b ;
        connect [ a - 1 ].push_back ( b - 1 ) ;
        connect [ b - 1 ].push_back ( a - 1 ) ;
    }

    // Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
    if ( numEdge % 2!= 0 ) {
        cout << - 1 << endl ;
        return 0 ;
    }

    // Initializing the visited, odd, and print arrays and objects.
    visited = new int [ numNode ] ;
    odd = new bool [ numNode ] ;

    // Calling the dfs method with the first node and -1 as the parent node.
    dfs ( 0, - 1 ) ;

    // Printing the output.
    cout << print.str ( ) ;

    return 0 ;
}

These comments should provide a clear understanding of the logic behind each block of code in the given C++ program.