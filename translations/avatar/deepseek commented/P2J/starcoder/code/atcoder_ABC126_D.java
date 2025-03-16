
import java.util.*;

public class Main {

    public static void main ( String [ ] args ) {

        // Read the number of nodes in the graph
        Scanner sc = new Scanner ( System.in );
        int n = sc.nextInt ( );

        // Create a list to store all nodes
        Node [ ] nodes = new Node [ n ];
        for ( int i = 0 ; i < n ; i ++ ) {
            nodes [ i ] = new Node ( );
        }

        // Read each edge in the graph and establish connections between nodes
        for ( int i = 0 ; i < n - 1 ; i ++ ) {
            int u = sc.nextInt ( );
            int v = sc.nextInt ( );
            int w = sc.nextInt ( );
            Node node1 = nodes [ u - 1 ];
            Node node2 = nodes [ v - 1 ];
            node1.val = u;
            node2.val = v;
            node1.a.add ( new NodePair ( node2, w ) );
            node2.a.add ( new NodePair ( node1, w ) );
        }

        // Set the root node to the first node in the list
        Node root = nodes [ 0 ];

        // Set the color of the root node to True
        root.color = true;

        // Initialize a set to keep track of visited nodes
        Set < Node > nodeSet = new HashSet < > ( );

        // Define the traverse function to recursively traverse the graph
        void traverse ( Node node, int distance ) {
            if ( nodeSet.contains ( node ) ) {
                return;
            } else {
                nodeSet.add ( node );
            }
            for ( NodePair pair : node.a ) {
                Node adjNode = pair.node;
                int dis = pair.dis;
                if ( ( distance + dis ) % 2 == 0 ) {
                    adjNode.color = root.color;
                } else {
                    adjNode.color =!root.color;
                }
                traverse ( adjNode, distance + dis );
            }
        }

        // Call the traverse function starting from the root node with a distance of 0
        traverse ( root, 0 );

        // Print the color of each node
        for ( int i = 0 ; i < n ; i ++ ) {
            Node node = nodes [ i ];
            if ( node.color ) {
                System.out.println ( 1 );
            } else {
                System.out.println ( 0 );
            }
        }

    }

}

class Node {

    int val;
    boolean color;
    List < NodePair > a;

    public Node ( ) {
        val = 0;
        color = false;
        a = new ArrayList < > ( );
    }

}

class NodePair {

    Node node;
    int dis;

    public NodePair ( Node node, int dis ) {
        this.node = node;
        this.dis = dis;
    }

}

