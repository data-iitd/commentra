import sys
from collections import deque
sys.setrecursionlimit ( 10 ** 9 )  # Set the recursion limit to handle deep recursion
INF = 10 ** 18  # Define a constant for infinity
def input ( ) :
    return sys.stdin.readline ( ).rstrip ( )  # Function to read input line and strip whitespace
def main ( ) :
    N , M = map ( int , input ( ).split ( ) )  # Read the number of nodes and edges
    edge = [ [ ] for _ in range ( N ) ]  # Initialize the edge list to represent the graph
    for i in range ( M ) :
        X , Y , Z = map ( lambda x : int ( x ) - 1 , input ( ).split ( ) )  # Read each edge and adjust indices
        edge [ X ].append ( Y )  # Add edge in both directions for an undirected graph
        edge [ Y ].append ( X )
    used = [ False ] * N  # Initialize a list to track visited nodes
    ans = 0  # Initialize the counter for connected components
    for i in range ( N ) :
        if not used [ i ] :
            ans += 1  # Increment the counter for each new connected component found
            queue = deque ( )  # Initialize a queue for BFS
            queue.append ( i )  # Start BFS from the current node
            while queue :
                node = queue.popleft ( )  # Get the next node from the queue
                used [ node ] = True  # Mark the node as visited
                for nextnode in edge [ node ] :
                    if not used [ nextnode ] :
                        queue.append ( nextnode )  # Add unvisited neighbors to the queue
    print ( ans )  # Output the total number of connected components
if __name__ == '__main__' :
    main ( )  # Call the main function to execute the program
