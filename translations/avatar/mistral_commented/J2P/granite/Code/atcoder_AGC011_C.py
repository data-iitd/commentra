

import sys
from collections import deque

class Main: # Defining a class named Main
  def __init__ ( self ) : # Defining the constructor method
    self.graph = [ ] # Initializing the graph as an empty list
    self.visited = [ False ] * 100000 # Initializing the visited array with false values
    self.color = [ - 1 ] * 100000 # Initializing the color array with -1 values
    self.one = 0 # Initializing the count of nodes in a single connected component to 0
    self.bipartite = 0 # Initializing the count of bipartite connected components to 0
    self.count = 0 # Initializing the total count of nodes in the graph to 0
    self.mujun = False # Initializing the mujun flag to false

  def run ( self ) : # Defining the run method to be executed when the thread is started
    n, m = map ( int, input ( ).split ( ) ) # Reading the number of nodes and edges from the input
    for i in range ( n ) : # Iterating through each node in the graph
      self.graph.append ( [ ] ) # Adding an empty list to the graph array for each node
    for i in range ( m ) : # Iterating through each edge in the graph
      u, v = map ( int, input ( ).split ( ) ) # Reading the source and destination nodes of the edge from the input
      self.graph [ u - 1 ].append ( v - 1 ) # Adding the destination node to the adjacency list of the source node
      self.graph [ v - 1 ].append ( u - 1 ) # Adding the source node to the adjacency list of the destination node
    for i in range ( n ) : # Iterating through each node in the graph
      if ( self.visited [ i ] ) continue # Skipping the node if it has already been visited
      self.count ++ # Incrementing the count of nodes in the graph
      self.mujun = False # Resetting the mujun flag
      kind = self.dfs ( i, 0 ) # Calling the depth-first search algorithm to find the connected component and its bipartiteness
      if ( kind == 1 ) self.one ++ # Incrementing the count of nodes in a single connected component if it is a single connected component
      else if ( not self.mujun ) self.bipartite ++ # Incrementing the count of bipartite connected components if the current component is bipartite and not an odd cycle
    total = self.one * ( 2 * n - self.one ) # Calculating the total number of edges in the graph
    total += ( self.count - self.one ) * ( self.count - self.one ) # Calculating the number of edges in the isolated nodes
    total += self.bipartite * self.bipartite # Calculating the number of edges in the bipartite connected components
    print ( total ) # Printing the total number of edges in the graph

  def dfs ( self, a, c ) : # Defining the depth-first search algorithm to find the connected component and its bipartiteness
    if ( self.visited [ a ] ) : # Checking if the current node has already been visited
      if ( self.color [ a ] >= 0 and self.color [ a ]!= c ) self.mujun = True # Setting the mujun flag if there is an odd cycle in the graph
      return 0 # Returning 0 if the current node is already visited
    self.visited [ a ] = True # Marking the current node as visited
    self.color [ a ] = c # Setting the color of the current node
    total = 1 # Initializing the total number of nodes in the connected component to 1
    for b in self.graph [ a ] : # Iterating through each neighbor of the current node
      total += self.dfs ( b, 1 - c ) # Recursively calling the depth-first search algorithm on the neighbor and adding the total number of nodes in its connected component
    return total # Returning the total number of nodes in the connected component

  def main ( ) : # Defining the main method to start the thread
    sys.setrecursionlimit ( 100000 ) # Setting the maximum recursion depth to 1,000,000
    Main ( ).run ( ) # Creating an instance of the Main class and calling the run method to start the thread

Main ( ).main ( ) # Calling the main method to start the thread

