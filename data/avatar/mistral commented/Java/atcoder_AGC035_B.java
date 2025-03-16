
import java.util.* ;

// Importing the utility class Scanner for reading input from the standard input stream.

public class Main {

    @SuppressWarnings ( "unchecked" ) // Suppressing the warning for unchecked ArrayList usage.

    // Main method where the program starts execution.
    public static void main ( String [ ] args ) {
        Scanner sc = new Scanner ( System.in ) ; // Creating a new Scanner object to read input.
        int numNode = sc.nextInt ( ) ; // Reading the number of nodes from the input.
        int numEdge = sc.nextInt ( ) ; // Reading the number of edges from the input.

        // Initializing the connect array to store the list of neighbors for each node.
        connect = new ArrayList [ numNode ] ;
        for ( int i = 0 ; i < numNode ; i ++ ) {
            connect [ i ] = new ArrayList < > ( ) ;
        }

        // Reading the edges and adding them to the connect array.
        for ( int i = 0 ; i < numEdge ; i ++ ) {
            int a = sc.nextInt ( ) - 1 ; // Reading the first node index.
            int b = sc.nextInt ( ) - 1 ; // Reading the second node index.
            connect [ a ].add ( b ) ; // Adding the second node index to the first node's list of neighbors.
            connect [ b ].add ( a ) ; // Adding the first node index to the second node's list of neighbors.
        }

        // Checking if the number of edges is odd. If it is, then the graph is not bipartite, and we print -1 and exit.
        if ( numEdge % 2 != 0 ) {
            System.out.println ( - 1 ) ;
            return ;
        }

        // Initializing the visited, odd, and print arrays and objects.
        visited = new int [ numNode ] ;
        odd = new boolean [ numNode ] ;
        print = new StringBuilder ( ) ;

        // Calling the dfs method with the first node and -1 as the parent node.
        dfs ( 0 , - 1 ) ;

        // Printing the output.
        System.out.println ( print ) ;
    }

    // Static array to store the connectivity information for each node.
    static ArrayList < Integer > connect [ ] ;

    // Static arrays to store the visited status and odd component for each node.
    static int visited [ ] ;
    static boolean odd [ ] ;

    // Static StringBuilder object to store the output.
    static StringBuilder print ;

    // Recursive depth-first search method to perform bipartite traversal.
    static void dfs ( int crt , int parent ) {
        // Marking the current node as visited.
        visited [ crt ] = 1 ;

        // Iterating through the neighbors of the current node.
        ArrayList < Integer > crtConnect = connect [ crt ] ;
        for ( int child : crtConnect ) {
            // Skipping the neighbor if it is the parent node or already visited.
            if ( child == parent || visited [ child ] == 1 ) {
                continue ;
            }

            // If the neighbor has already been assigned an odd component, then we add an edge between the current and neighbor nodes.
            // Otherwise, we swap the components and continue the traversal.
            if ( visited [ child ] == 2 ) {
                print.append ( ( crt + 1 ) + " " + ( child + 1 ) + "\n" ) ;
                odd [ crt ] = ! odd [ crt ] ;
            } else {
                dfs ( child , crt ) ;
                if ( odd [ child ] ) {
                    print.append ( ( child + 1 ) + " " + ( crt + 1 ) + "\n" ) ;
                    odd [ child ] = ! odd [ child ] ;
                } else {
                    print.append ( ( crt + 1 ) + " " + ( child + 1 ) + "\n" ) ;
                    odd [ crt ] = ! odd [ crt ] ;
                }
            }
        }

        // Marking the current node as visited with component 2.
        visited [ crt ] = 2 ;
    }
}

These comments should provide a clear understanding of the logic behind each block of code in the given Java program.