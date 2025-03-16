import java.util.* ; // Importing necessary utilities for the program
class Main implements Runnable { // Main class implementing Runnable interface
    ArrayList < Integer > [ ] graph ; // Adjacency list to represent the graph
    boolean [ ] visited ; // Array to keep track of visited nodes
    int [ ] color ; // Array to store colors for bipartite check
    long one ; // Counter for components with exactly one node
    long bipartite ; // Counter for bipartite components
    long count ; // Counter for total number of connected components
    boolean mujun ; // Flag to check for non-bipartite conditions

    // Depth-first search method to color nodes and check for bipartiteness
    int dfs ( int a , int c ) {
        if ( visited [ a ] ) { // If node is already visited
            if ( color [ a ] >= 0 && color [ a ] != c ) mujun = true ; // Check if color conflict and set mujun flag
            return 0 ; // Return 0 as we don't want to count this node again
        }
        visited [ a ] = true ; // Mark node as visited
        color [ a ] = c ; // Assign color to the node
        int total = 1 ; // Initialize total count for this component
        for ( int b : graph [ a ] ) { // Iterate through neighbors
            total += dfs ( b , 1 - c ) ; // Recursively call dfs and accumulate total
        }
        return total ; // Return total count for this component
    }

    // Main method to execute the program
    public void run ( ) {
        Scanner scan = new Scanner ( System.in ) ; // Initialize scanner for input
        int n = scan.nextInt ( ) ; // Read number of nodes
        int m = scan.nextInt ( ) ; // Read number of edges
        this.graph = new ArrayList [ n ] ; // Initialize graph adjacency list
        for ( int i = 0 ; i < n ; ++ i ) this.graph [ i ] = new ArrayList < Integer > ( ) ; // Initialize each node's adjacency list
        for ( int i = 0 ; i < m ; ++ i ) { // Read each edge and add to graph
            int u = scan.nextInt ( ) - 1 ; // Read node u
            int v = scan.nextInt ( ) - 1 ; // Read node v
            this.graph [ u ].add ( v ) ; // Add edge u -> v
            this.graph [ v ].add ( u ) ; // Add edge v -> u
        }
        visited = new boolean [ n ] ; // Initialize visited array
        color = new int [ n ] ; // Initialize color array
        Arrays.fill ( color , - 1 ) ; // Set all colors to -1 (uncolored)
        one = 0 ; // Initialize one counter
        bipartite = 0 ; // Initialize bipartite counter
        count = 0 ; // Initialize component counter
        for ( int i = 0 ; i < n ; ++ i ) { // Iterate through all nodes
            if ( visited [ i ] ) continue ; // Skip if already visited
            count ++ ; // Increment component count
            mujun = false ; // Reset mujun flag
            int kind = dfs ( i , 0 ) ; // Perform DFS and get component size
            if ( kind == 1 ) one ++ ; // If component has exactly one node, increment one counter
            else if ( ! mujun ) bipartite ++ ; // If component is bipartite, increment bipartite counter
        }
        long total = one * ( 2 * n - one ) ; // Calculate total for components with exactly one node
        total += ( count - one ) * ( count - one ) ; // Calculate total for components with more than one node
        total += bipartite * bipartite ; // Add total for bipartite components
        System.out.println ( total ) ; // Print the total number of valid configurations
    }

    // Main method to start the program in a new thread
    public static void main ( String [ ] args ) {
        new Thread ( null , new Main ( ) , "" , 128 * 1024 * 1024 ).start ( ) ;
    }
}
