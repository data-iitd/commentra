
import java.util.LinkedList ;  // Importing LinkedList class for creating linked lists
import java.util.Scanner ;   // Importing Scanner class for reading input

public class Main {

    private class Node {  // Defining a private inner class Node
        long pattern = 0 ;   // Pattern to store the result of the subtree rooted at this node
        int index ;          // Index of the node in the array
        LinkedList < Integer > children = new LinkedList < Integer > ( ) ; // Linked list to store the indices of children
        int parent = - 1 ;    // Index of the parent node

        public Node ( int i ) {  // Constructor to initialize a new node
            this.index = i ;
        }

        public void setParent ( int K , int parent , int use , Node [ ] nodes ) {  // Method to set the parent of this node and calculate its pattern
            this.pattern = K - use ;
            this.parent = parent ;
            int count = 1 ;
            if ( parent != - 1 ) {  // If this node has a parent
                count++ ;
            }
            for ( int n : children ) {  // For each child
                if ( n == this.parent ) {  // If the child is the parent of this node (avoiding self-loop)
                    continue ;
                }
                nodes [ n ].setParent ( K , this.index , count , nodes ) ; // Recursively setting the parent and calculating the pattern for the child
                count++ ;
            }
        }

        public void solve ( ) {  // Method to solve the problem by calculating the pattern for the entire tree
            Scanner in = new Scanner ( System.in ) ; // Creating a new Scanner object to read input
            int N = in.nextInt ( ) ; // Reading the number of nodes in the tree
            int K = in.nextInt ( ) ; // Reading the sum of edges' weights

            Node [ ] nodes = new Node [ N ] ; // Creating an array of Node objects to store the nodes
            for ( int i = 0 ; i < N ; i ++ ) { // Initializing the nodes
                nodes [ i ] = new Node ( i ) ;
            }

            for ( int i = 0 ; i < N - 1 ; i ++ ) { // Reading the edges and adding them to the linked list of children for both nodes
                int a = in.nextInt ( ) - 1 ;
                int b = in.nextInt ( ) - 1 ;
                nodes [ a ].children.add ( b ) ;
                nodes [ b ].children.add ( a ) ;
            }

            in.close ( ) ; // Closing the Scanner object after reading all input

            nodes [ 0 ].setParent ( K , - 1 , 0 , nodes ) ; // Setting the parent and calculating the pattern for the root node
            long patterns = 1 ; // Initializing the result variable

            for ( int i = 0 ; i < N ; i ++ ) { // Calculating the pattern for the entire tree by multiplying the patterns of subtrees and taking the modulo with 1,000,000,007
                patterns = ( patterns * nodes [ i ].pattern ) % 1_000_000_007 ;
            }

            System.out.println ( patterns ) ; // Printing the result
        }
    }

    public static void main ( String [ ] args ) { // Main method to call the solve method
        Main main = new Main ( ) ;
        main.solve ( ) ;
    }
}