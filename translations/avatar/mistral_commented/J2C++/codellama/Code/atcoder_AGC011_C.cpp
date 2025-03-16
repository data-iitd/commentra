
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std ;

class Main { // Defining a class named Main
  vector < vector < int > > graph ; // Declaring a vector named graph to store the adjacency list of the graph
  bool *visited ; // Declaring a boolean array named visited to keep track of the visited nodes
  int *color ; // Declaring an integer array named color to store the color of each node in the graph
  long one ; // Declaring a long variable named one to store the number of nodes in a single connected component
  long bipartite ; // Declaring a long variable named bipartite to store the number of bipartite connected components
  long count ; // Declaring a long variable named count to store the total number of nodes in the graph
  bool mujun ; // Declaring a boolean variable named mujun to check if there is an odd cycle in the graph

  public:
    void run ( ) { // Defining the run method to be executed when the thread is started
      int n , m ; // Declaring two integer variables named n and m to store the number of nodes and edges in the graph
      cin >> n >> m ; // Reading the number of nodes and edges in the graph from the standard input
      graph = vector < vector < int > > ( n ) ; // Initializing the graph vector with n sub-vectors
      for ( int i = 0 ; i < n ; ++ i ) graph [ i ] = vector < int > ( ) ; // Initializing each sub-vector with an empty vector
      for ( int i = 0 ; i < m ; ++ i ) { // Iterating through each edge in the graph
        int u , v ; // Declaring two integer variables named u and v to store the source and destination nodes of the edge
        cin >> u >> v ; // Reading the source and destination nodes of the edge from the standard input
        u -- , v -- ; // Decrementing the source and destination nodes by 1 to make them 0-based
        graph [ u ].push_back ( v ) ; // Adding the destination node to the adjacency list of the source node
        graph [ v ].push_back ( u ) ; // Adding the source node to the adjacency list of the destination node
      }
      visited = new bool [ n ] ; // Initializing the visited array with false values
      color = new int [ n ] ; // Initializing the color array with -1 values
      memset ( color , - 1 , sizeof ( int ) * n ) ; // Setting all the initial colors to -1
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
      cout << total << endl ; // Printing the total number of edges in the graph
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

    Main ( ) { // Defining the constructor to start the thread
      new thread ( [ ] ( ) { run ( ) ; } ) ; // Creating and starting a new thread to execute the run method
    }
} ;

int main ( ) { // Defining the main method to start the thread
  new Main ( ) ; // Creating and starting a new thread to execute the Main class
  return 0 ; // Returning 0 to the operating system
}

