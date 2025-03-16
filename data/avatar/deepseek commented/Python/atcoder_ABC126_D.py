
import sys
sys.setrecursionlimit ( 10 ** 5 )

# Define the Node class to represent each node in the graph
class Node :
    def __init__ ( self ) :
        self.val = None
        self.color = None
        self.a = [ ]

# Read the number of nodes in the graph
n = int ( input ( ) )

# Create a list to store all nodes
nodes = [ ]
for i in range ( n ) :
    nodes.append ( Node ( ) )

# Read each edge in the graph and establish connections between nodes
for i in range ( n - 1 ) :
    u , v , w = map ( int , input ( ).split ( ) )
    node1 = nodes [ u - 1 ]
    node2 = nodes [ v - 1 ]
    node1.val = u
    node2.val = v
    node1.a.append ( [ node2 , w ] )
    node2.a.append ( [ node1 , w ] )

# Set the root node to the first node in the list
root = nodes [ 0 ]

# Set the color of the root node to True
root.color = True

# Initialize a set to keep track of visited nodes
nodeSet = set ( )

# Define the traverse function to recursively traverse the graph
def traverse ( node , distance ) :
    if node in nodeSet :
        return
    else :
        nodeSet.add ( node )
    for pair in node.a :
        adjNode = pair [ 0 ]
        dis = pair [ 1 ]
        if ( distance + dis ) % 2 == 0 :
            adjNode.color = root.color
        else :
            adjNode.color = not root.color
        traverse ( adjNode , distance + dis )

# Call the traverse function starting from the root node with a distance of 0
traverse ( root , 0 )

# Print the color of each node
for i in range ( n ) :
    node = nodes [ i ]
    if node.color :
        print ( 1 )
    else :
        print ( 0 )