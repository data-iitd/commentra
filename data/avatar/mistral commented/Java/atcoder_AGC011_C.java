
import java.util.* ; // Importing the utility class Scanner and the ArrayList

class Main implements Runnable { // Defining a class named Main that implements the Runnable interface
  ArrayList < Integer > [ ] graph ; // Declaring an ArrayList named graph to store the adjacency list of the graph
  boolean [ ] visited ; // Declaring a boolean array named visited to keep track of the visited nodes
  int [ ] color ; // Declaring an integer array named color to store the color of each node in the graph
  long one ; // Declaring a long variable named one to store the number of nodes in a single connected component
  long bipartite ; // Declaring a long variable named bipartite to store the number of bipartite connected components
  long count ; // Declaring a long variable named count to store the total number of nodes in the graph
  boolean mujun ; // Declaring a boolean variable named mujun to check if there is an odd cycle in the graph

  public void run ( ) { // Defining the run method to be executed when the thread is started
    Scanner scan = new Scanner ( System.in ) ; // Creating a Scanner object to read the input from the standard input
    int n = scan.nextInt ( ) ; // Reading the number of nodes in the graph from the input
    int m = scan.nextInt ( ) ; // Reading the number of edges in the graph from the input
    this.graph = new ArrayList [ n ] ; // Initializing the graph array with n sub-arrays
    for ( int i = 0 ; i < n ; ++ i ) this.graph [ i ] = new ArrayList < Integer > ( ) ; // Initializing each sub-array with an empty ArrayList
    for ( int i = 0 ; i < m ; ++ i ) { // Iterating through each edge in the graph
      int u = scan.nextInt ( ) - 1 ; // Reading the source node of the edge from the input
      int v = scan.nextInt ( ) - 1 ; // Reading the destination node of the edge from the input
      this.graph [ u ].add ( v ) ; // Adding the destination node to the adjacency list of the source node
      this.graph [ v ].add ( u ) ; // Adding the source node to the adjacency list of the destination node
    }
    visited = new boolean [ n ] ; // Initializing the visited array with false values
    color = new int [ n ] ; // Initializing the color array with -1 values
    Arrays.fill ( color , - 1 ) ; // Setting all the initial colors to -1
    for ( int i = 0 ; i < n ; ++ i ) { // Iterating through each node in the graph
      if ( visited [ i ] ) continue ; // Skipping the node if it has already been visited
      count ++ ; // Incrementing the count of nodes in the graph
      mujun = false ; // Resetting the mujun flag
      int kind = dfs ( i , 0 ) ; // Calling the depth-first search algorithm to find the connected component and its bipartiteness
      if ( kind == 1 ) one ++ ; // Incrementing the count of nodes in a single connected component if it is a single connected component
      else if ( ! mujun ) bipartite ++ ; // Incrementing the count of bipartite connected components if the current component is bipartite and not an odd cycle
    }
    long total = one * ( 2 * n - one ) ; // Calculating the total number of edges in the graph
    total += ( count - one ) * ( count - one ) ; // Calculating the number of edges in the isolated nodes
    total += bipartite * bipartite ; // Calculating the number of edges in the bipartite connected components
    System.out.println ( total ) ; // Printing the total number of edges in the graph
  }

  int dfs ( int a , int c ) { // Defining the depth-first search algorithm to find the connected component and its bipartiteness
    if ( visited [ a ] ) { // Checking if the current node has already been visited
      if ( color [ a ] >= 0 && color [ a ] != c ) mujun = true ; // Setting the mujun flag if there is an odd cycle in the graph
      return 0 ; // Returning 0 if the current node is already visited
    }
    visited [ a ] = true ; // Marking the current node as visited
    color [ a ] = c ; // Setting the color of the current node
    int total = 1 ; // Initializing the total number of nodes in the connected component to 1
    for ( int b : graph [ a ] ) { // Iterating through each neighbor of the current node
      total += dfs ( b , 1 - c ) ; // Recursively calling the depth-first search algorithm on the neighbor and adding the total number of nodes in its connected component
    }
    return total ; // Returning the total number of nodes in the connected component
  }

  public static void main ( String [ ] args ) { // Defining the main method to start the thread
    new Thread ( null , new Main ( ) , "" , 128 * 1024 * 1024 ).start ( ) ; // Creating and starting a new thread to execute the Main class
  }
}