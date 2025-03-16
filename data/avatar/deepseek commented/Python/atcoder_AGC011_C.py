import queue
n , m = map ( int , input ( ).split ( ) )  # Reading the number of nodes and edges
vis , ci , cb , cc = [ 0 ] * ( n + 1 ) , 0 , 0 , 0  # Initializing visited list and counters for isolated, bipartite, and connected components
g = [ [ ] for i in range ( n + 1 ) ]  # Creating an adjacency list to represent the graph

# Depth-First Search (DFS) function to determine if a graph is bipartite
def dfs ( x ) :
    stk , flag = queue.LifoQueue ( ) , True  # Using a stack for DFS and a flag to check bipartiteness
    stk.put ( ( x , 1 ) )  # Starting DFS from node x with color 1
    while not stk.empty ( ) :
        u , col = stk.get ( )  # Getting the current node and its color from the stack
        if vis [ u ] :  # If the node has been visited, check if the color is consistent
            flag &= ( vis [ u ] == col )
            continue
        vis [ u ] = col  # Marking the node as visited with the current color
        for i in g [ u ] :
            stk.put ( ( i , 3 - col ) )  # Adding adjacent nodes to the stack with the opposite color
    return flag

# Constructing the graph by reading edges
for i in range ( m ) :
    u , v = map ( int , input ( ).split ( ) )
    g [ u ] += [ v ]  # Adding edge u-v
    g [ v ] += [ u ]  # Adding edge v-u (undirected graph)

# Traversing the graph to classify nodes
for i in range ( 1 , n + 1 ) :
    if vis [ i ] == 0 :  # If the node has not been visited
        if len ( g [ i ] ) == 0 :
            ci += 1  # Increment the count of isolated nodes
        else :
            if dfs ( i ) :
                cb += 1  # Increment the count of bipartite graphs
            else :
                cc += 1  # Increment the count of connected components that are not bipartite

# Calculating and printing the result based on the counts of isolated, bipartite, and connected components
print ( ci * ci + 2 * ci * ( n - ci ) + cc * cc + 2 * cb * cc + 2 * cb * cb )
