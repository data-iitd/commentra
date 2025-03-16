

import sys

class Node:  # Defining a class Node
    def __init__ ( self, i ) :  # Constructor to initialize a new node
        self.index = i
        self.pattern = 0
        self.parent = - 1
        self.children = []

    def setParent ( self, K, parent, use, nodes ) :  # Method to set the parent of this node and calculate its pattern
        self.pattern = K - use
        self.parent = parent
        count = 1
        if ( parent!= - 1 ) :  # If this node has a parent
            count += 1
        for n in self.children :  # For each child
            if ( n == self.parent ) :  # If the child is the parent of this node (avoiding self-loop)
                continue
            nodes [ n ].setParent ( K, self.index, count, nodes )  # Recursively setting the parent and calculating the pattern for the child
            count += 1

    def solve ( self ) :  # Method to solve the problem by calculating the pattern for the entire tree
        N = int ( input ( ) )  # Reading the number of nodes in the tree
        K = int ( input ( ) )  # Reading the sum of edges' weights

        nodes = [ Node ( i ) for i in range ( N ) ]  # Creating an array of Node objects to store the nodes

        for i in range ( N - 1 ) :  # Reading the edges and adding them to the linked list of children for both nodes
            a = int ( input ( ) ) - 1
            b = int ( input ( ) ) - 1
            nodes [ a ].children.append ( b )
            nodes [ b ].children.append ( a )

        nodes [ 0 ].setParent ( K, - 1, 0, nodes )  # Setting the parent and calculating the pattern for the root node
        patterns = 1  # Initializing the result variable

        for i in range ( N ) :  # Calculating the pattern for the entire tree by multiplying the patterns of subtrees and taking the modulo with 1,000,000,007
            patterns = ( patterns * nodes [ i ].pattern ) % 1_000_000_007

        print ( patterns )  # Printing the result

if __name__ == "__main__" :  # Main method to call the solve method
    main = Node ( )
    main.solve ( )

