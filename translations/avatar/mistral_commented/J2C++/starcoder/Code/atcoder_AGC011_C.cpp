
#include <bits/stdc++.h> // Importing the standard library

using namespace std ; // Using the standard namespace

class Main { // Defining a class named Main
  vector < vector < int > > graph ; // Declaring a vector of vectors named graph to store the adjacency list of the graph
  vector < bool > visited ; // Declaring a vector of booleans named visited to keep track of the visited nodes
  vector < int > color ; // Declaring a vector of integers named color to store the color of each node in the graph
  long long one ; // Declaring a long long variable named one to store the number of nodes in a single connected component
  long long bipartite ; // Declaring a long long variable named bipartite to store the number of bipartite connected components
  long long count ; // Declaring a long long variable named count to store the total number of nodes in the graph
  bool mujun ; // Declaring a boolean variable named mujun to check if there is an odd cycle in the graph

  public:
    void run ( ) { // Defining the run method to be executed when the thread is started
      cin >> count ; // Reading the number of nodes in the graph from the input
      int m = count * ( count - 1 ) / 2 ; // Calculating the number of edges in the graph
      int n = count ; // Setting the number of nodes in the graph to the number of nodes in the graph
      graph.resize ( n ) ; // Initializing the graph vector with n sub-vectors
      for ( int i = 0 ; i < n ; ++ i ) graph [ i ].resize ( 0 ) ; // Initializing each sub-vector with an empty vector
      for ( int i = 0 ; i < m ; ++ i ) { // Iterating through each edge in the graph
        int u, v ;
        cin >> u >> v ; // Reading the source node and destination node of the edge from the input
        u -- ; // Converting the source node to a zero-based index
        v -- ; // Converting the destination node to a zero-based index
        graph [ u ].push_back ( v ) ; // Adding the destination node to the adjacency list of the source node
        graph [ v ].push_back ( u ) ; // Adding the source node to the adjacency list of the destination node
      }
      visited.resize ( n, false ) ; // Initializing the visited vector with false values
      color.resize ( n, - 1 ) ; // Initializing the color vector with -1 values
      for ( int i = 0 ; i < n ; ++ i ) { // Iterating through each node in the graph
        if ( visited [ i ] ) continue ; // Skipping the node if it has already been visited
        count ++ ; // Incrementing the count of nodes in the graph
        mujun = false ; // Resetting the mujun flag
        int kind = dfs ( i, 0 ) ; // Calling the depth-first search algorithm to find the connected component and its bipartiteness
        if ( kind == 1 ) one ++ ; // Incrementing the count of nodes in a single connected component if it is a single connected component
        else if (! mujun ) bipartite ++ ; // Incrementing the count of bipartite connected components if the current component is bipartite and not an odd cycle
      }
      long long total = one * ( 2 * n - one ) ; // Calculating the total number of edges in the graph
      total += ( count - one ) * ( count - one ) ; // Calculating the number of edges in the isolated nodes
      total += bipartite * bipartite ; // Calculating the number of edges in the bipartite connected components
      cout << total << endl ; // Printing the total number of edges in the graph
    }

    int dfs ( int a, int c ) { // Defining the depth-first search algorithm to find the connected component and its bipartiteness
      if ( visited [ a ] ) { // Checking if the current node has already been visited
        if ( color [ a ] >= 0 && color [ a ]!= c ) mujun = true ; // Setting the mujun flag if there is an odd cycle in the graph
        return 0 ; // Returning 0 if the current node is already visited
      }
      visited [ a ] = true ; // Marking the current node as visited
      color [ a ] = c ; // Setting the color of the current node
      int total = 1 ; // Initializing the total number of nodes in the connected component to 1
      for ( int b : graph [ a ] ) { // Iterating through each neighbor of the current node
        total += dfs ( b, 1 - c ) ; // Recursively calling the depth-first search algorithm on the neighbor and adding the total number of nodes in its connected component
      }
      return total ; // Returning the total number of nodes in the connected component
    }
}

int main ( ) { // Defining the main method to start the thread
  thread ( & Main :: run, new Main ( ) ) ; // Creating and starting a new thread to execute the Main class
  return 0 ;
}

