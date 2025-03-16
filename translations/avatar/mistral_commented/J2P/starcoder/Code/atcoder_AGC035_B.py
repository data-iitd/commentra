
import sys

# Importing the utility class Scanner for reading input from the standard input stream.

# Class to represent a graph.
class Graph:
    # Constructor to initialize the graph.
    def __init__ ( self, numNode, numEdge ):
        self.numNode = numNode
        self.numEdge = numEdge
        self.connect = [ [] for i in range ( numNode ) ]

        # Reading the edges and adding them to the connect array.
        for i in range ( numEdge ):
            a = int ( sys.stdin.readline ( ) ) - 1
            b = int ( sys.stdin.readline ( ) ) - 1
            self.connect [ a ].append ( b )
            self.connect [ b ].append ( a )

    # Method to check if the graph is bipartite.
    def isBipartite ( self ):
        # Initializing the visited, odd, and print arrays and objects.
        visited = [ 0 for i in range ( self.numNode ) ]
        odd = [ False for i in range ( self.numNode ) ]
        print = ""

        # Calling the dfs method with the first node and -1 as the parent node.
        self.dfs ( 0, - 1, visited, odd, print )

        # Printing the output.
        print ( print )

    # Recursive depth-first search method to perform bipartite traversal.
    def dfs ( self, crt, parent, visited, odd, print ):
        # Marking the current node as visited.
        visited [ crt ] = 1

        # Iterating through the neighbors of the current node.
        crtConnect = self.connect [ crt ]
        for child in crtConnect:
            # Skipping the neighbor if it is the parent node or already visited.
            if ( child == parent or visited [ child ] == 1 ):
                continue

            # If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
            # Otherwise, we swap the components and continue the traversal.
            if ( visited [ child ] == 2 ):
                print += ( str ( crt + 1 ) + " " + str ( child + 1 ) + "\n" )
                odd [ crt ] = not odd [ crt ]
            else:
                self.dfs ( child, crt, visited, odd, print )
                if ( odd [ child ] ):
                    print += ( str ( child + 1 ) + " " + str ( crt + 1 ) + "\n" )
                    odd [ child ] = not odd [ child ]
                else:
                    print += ( str ( crt + 1 ) + " " + str ( child + 1 ) + "\n" )
                    odd [ crt ] = not odd [ crt ]

        # Marking the current node as visited with component 2.
        visited [ crt ] = 2

# Main method where the program starts execution.
if __name__ == "__main__":
    numNode = int ( sys.stdin.readline ( ) )
    numEdge = int ( sys.stdin.readline ( ) )
    graph = Graph ( numNode, numEdge )
    graph.isBipartite ( )

# 