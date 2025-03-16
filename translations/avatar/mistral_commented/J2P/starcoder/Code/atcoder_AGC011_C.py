
import sys ; // Importing the sys module to read the input from the standard input

class Main: // Defining a class named Main
  def __init__ ( self ): // Defining the constructor to initialize the graph and the visited array
    self.graph = [ [] for i in range ( 10000 ) ] ; // Initializing the graph array with 10000 sub-arrays
    self.visited = [ False for i in range ( 10000 ) ] ; // Initializing the visited array with false values
    self.color = [ - 1 for i in range ( 10000 ) ] ; // Initializing the color array with -1 values
    self.one = 0 ; // Initializing the number of nodes in a single connected component to 0
    self.bipartite = 0 ; // Initializing the number of bipartite connected components to 0
    self.count = 0 ; // Initializing the total number of nodes in the graph to 0
    self.mujun = False ; // Initializing the mujun flag to false

  def run ( self ): // Defining the run method to be executed when the thread is started
    n = int ( sys.stdin.readline ( ) ) ; // Reading the number of nodes in the graph from the input
    m = int ( sys.stdin.readline ( ) ) ; // Reading the number of edges in the graph from the input
    for i in range ( m ): # Iterating through each edge in the graph
      u = int ( sys.stdin.readline ( ) ) - 1 ; // Reading the source node of the edge from the input
      v = int ( sys.stdin.readline ( ) ) - 1 ; // Reading the destination node of the edge from the input
      self.graph [ u ].append ( v ) ; // Adding the destination node to the adjacency list of the source node
      self.graph [ v ].append ( u ) ; // Adding the source node to the adjacency list of the destination node
    for i in range ( n ): # Iterating through each node in the graph
      if ( self.visited [ i ] ): continue ; # Skipping the node if it has already been visited
      self.count += 1 ; # Incrementing the count of nodes in the graph
      self.mujun = False ; # Resetting the mujun flag
      kind = self.dfs ( i, 0 ) ; # Calling the depth-first search algorithm to find the connected component and its bipartiteness
      if ( kind == 1 ): self.one += 1 ; # Incrementing the count of nodes in a single connected component if it is a single connected component
      else if ( not self.mujun ): self.bipartite += 1 ; # Incrementing the count of bipartite connected components if the current component is bipartite and not an odd cycle
    total = self.one * ( 2 * n - self.one ) ; # Calculating the total number of edges in the graph
    total += ( self.count - self.one ) * ( self.count - self.one ) ; # Calculating the number of edges in the isolated nodes
    total += self.bipartite * self.bipartite ; # Calculating the number of edges in the bipartite connected components
    print ( total ) ; # Printing the total number of edges in the graph

  def dfs ( self, a, c ): # Defining the depth-first search algorithm to find the connected component and its bipartiteness
    if ( self.visited [ a ] ): # Checking if the current node has already been visited
      if ( self.color [ a ] >= 0 and self.color [ a ]!= c ): self.mujun = True ; # Setting the mujun flag if there is an odd cycle in the graph
      return 0 ; # Returning 0 if the current node is already visited
    self.visited [ a ] = True ; # Marking the current node as visited
    self.color [ a ] = c ; # Setting the color of the current node
    total = 1 ; # Initializing the total number of nodes in the connected component to 1
    for b in self.graph [ a ]: # Iterating through each neighbor of the current node
      total += self.dfs ( b, 1 - c ) ; # Recursively calling the depth-first search algorithm on the neighbor and adding the total number of nodes in its connected component
    return total ; # Returning the total number of nodes in the connected component

if __name__ == "__main__": # Checking if the current file is the main file to execute the code
  Main ( ).run ( ) ; // Creating and starting a new thread to execute the Main class

