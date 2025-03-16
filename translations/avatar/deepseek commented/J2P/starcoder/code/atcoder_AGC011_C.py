import sys ; // Importing necessary utilities for the program
class Main: // Main class
    def __init__ ( self ):
        self.graph = [ ] ; // Adjacency list to represent the graph
        self.visited = [ ] ; // Array to keep track of visited nodes
        self.color = [ ] ; // Array to store colors for bipartite check
        self.one = 0 ; // Counter for components with exactly one node
        self.bipartite = 0 ; // Counter for bipartite components
        self.count = 0 ; // Counter for total number of connected components
        self.mujun = False ; // Flag to check for non-bipartite conditions

    # Depth-first search method to color nodes and check for bipartiteness
    def dfs ( self, a, c ):
        if ( self.visited [ a ] ): # If node is already visited
            if ( self.color [ a ] >= 0 and self.color [ a ]!= c ): self.mujun = True ; # Check if color conflict and set mujun flag
            return 0 ; # Return 0 as we don't want to count this node again
        self.visited [ a ] = True ; # Mark node as visited
        self.color [ a ] = c ; # Assign color to the node
        total = 1 ; # Initialize total count for this component
        for b in self.graph [ a ]: # Iterate through neighbors
            total += self.dfs ( b, 1 - c ) ; # Recursively call dfs and accumulate total
        return total ; # Return total count for this component

    # Main method to execute the program
    def run ( self ):
        scan = sys.stdin ; # Initialize scanner for input
        n = int ( scan.readline ( ) ) # Read number of nodes
        m = int ( scan.readline ( ) ) # Read number of edges
        self.graph = [ [ ] for i in range ( n ) ] # Initialize graph adjacency list
        for i in range ( m ): # Read each edge and add to graph
            u = int ( scan.readline ( ) ) - 1 # Read node u
            v = int ( scan.readline ( ) ) - 1 # Read node v
            self.graph [ u ].append ( v ) # Add edge u -> v
            self.graph [ v ].append ( u ) # Add edge v -> u
        self.visited = [ False for i in range ( n ) ] # Initialize visited array
        self.color = [ - 1 for i in range ( n ) ] # Initialize color array
        for i in range ( n ): # Iterate through all nodes
            if ( self.visited [ i ] ): continue ; # Skip if already visited
            self.count += 1 ; # Increment component count
            self.mujun = False ; # Reset mujun flag
            kind = self.dfs ( i, 0 ) # Perform DFS and get component size
            if ( kind == 1 ): self.one += 1 ; # If component has exactly one node, increment one counter
            else if ( not self.mujun ): self.bipartite += 1 ; # If component is bipartite, increment bipartite counter
        total = self.one * ( 2 * n - self.one ) # Calculate total for components with exactly one node
        total += ( self.count - self.one ) * ( self.count - self.one ) # Calculate total for components with more than one node
        total += self.bipartite * self.bipartite # Add total for bipartite components
        print ( total ) # Print the total number of valid configurations

# Main method to start the program in a new thread
if __name__ == "__main__":
    Main ( ).run ( )

