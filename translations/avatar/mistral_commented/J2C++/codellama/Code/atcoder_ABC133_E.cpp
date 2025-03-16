
#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std ;

class Node {  // Defining a private inner class Node
    public:
        long pattern = 0 ;   // Pattern to store the result of the subtree rooted at this node
        int index ;          // Index of the node in the array
        list < int > children ; // Linked list to store the indices of children
        int parent = - 1 ;    // Index of the parent node

        Node ( int i ) {  // Constructor to initialize a new node
            this->index = i ;
        }

        void setParent ( int K , int parent , int use , vector < Node > &nodes ) {  // Method to set the parent of this node and calculate its pattern
            this->pattern = K - use ;
            this->parent = parent ;
            int count = 1 ;
            if ( parent != - 1 ) {  // If this node has a parent
                count++ ;
            }
            for ( int n : children ) {  // For each child
                if ( n == this->parent ) {  // If the child is the parent of this node (avoiding self-loop)
                    continue ;
                }
                nodes [ n ].setParent ( K , this->index , count , nodes ) ; // Recursively setting the parent and calculating the pattern for the child
                count++ ;
            }
        }

        void solve ( ) {  // Method to solve the problem by calculating the pattern for the entire tree
            int N ; // Reading the number of nodes in the tree
            int K ; // Reading the sum of edges' weights
            cin >> N >> K ;

            vector < Node > nodes ( N ) ; // Creating an array of Node objects to store the nodes
            for ( int i = 0 ; i < N ; i ++ ) { // Initializing the nodes
                nodes [ i ] = Node ( i ) ;
            }

            for ( int i = 0 ; i < N - 1 ; i ++ ) { // Reading the edges and adding them to the linked list of children for both nodes
                int a , b ;
                cin >> a >> b ;
                nodes [ a - 1 ].children.push_back ( b - 1 ) ;
                nodes [ b - 1 ].children.push_back ( a - 1 ) ;
            }

            nodes [ 0 ].setParent ( K , - 1 , 0 , nodes ) ; // Setting the parent and calculating the pattern for the root node
            long patterns = 1 ; // Initializing the result variable

            for ( int i = 0 ; i < N ; i ++ ) { // Calculating the pattern for the entire tree by multiplying the patterns of subtrees and taking the modulo with 1,000,000,007
                patterns = ( patterns * nodes [ i ].pattern ) % 1000000007 ;
            }

            cout << patterns << endl ; // Printing the result
        }
};

int main ( ) { // Main method to call the solve method
    Node main ;
    main.solve ( ) ;
    return 0 ;
}

