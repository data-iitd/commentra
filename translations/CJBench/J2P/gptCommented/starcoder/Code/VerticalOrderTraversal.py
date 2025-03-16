import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

# Class representing a binary tree
class BinaryTree:
    # Inner class representing a node in the binary tree
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

# Method to perform vertical traversal of the binary tree
def verticalTraversal(root):
    # If the root is null, return an empty list
    if root == None:
        return new ArrayList<>()

    # Queues to hold nodes and their corresponding vertical indices
    queue = LinkedList<>()
    index = LinkedList<>()
    
    # Map to hold lists of node values at each vertical index
    map = HashMap<Integer, ArrayList<Integer>>()
    
    # Variables to track the maximum and minimum vertical indices
    max = 0
    min = 0

    # Start with the root node at index 0
    queue.offer(root)
    index.offer(0)

    # Perform a level-order traversal of the tree
    while not queue.isEmpty():
        node = queue.poll() # Get the current node
        idx = index.poll() # Get the corresponding index

        # Add the node's value to the list for the current index
        map.putIfAbsent(idx, new ArrayList<>())
        map.get(idx).add(node.data)

        # Update the maximum and minimum indices
        max = max(max, idx)
        min = min(min, idx)

        # Add left child to the queue with index decremented by 1
        if node.left!= None:
            queue.offer(node.left)
            index.offer(idx - 1)
        # Add right child to the queue with index incremented by 1
        if node.right!= None:
            queue.offer(node.right)
            index.offer(idx + 1)

    # Prepare the result list for vertical traversal output
    result = new ArrayList<>()
    # Collect values from the map in order of vertical indices
    for i in range(min, max + 1):
        result.addAll(map.get(i))
    return result # Return the final result list

if __name__ == '__main__':
    # Create a scanner to read input
    scanner = Scanner(System.in)
    
    # Read the number of nodes in the binary tree
    n = scanner.nextInt()
    
    # Array to hold references to the nodes
    nodes = [None] * (n + 1)
    
    # Initialize nodes with their respective values
    for i in range(1, n + 1):
        nodes[i] = BinaryTree.Node(i)
    
    # Read the edges and construct the binary tree
    for i in range(0, n - 1):
        parent = scanner.nextInt() # Parent node value
        child = scanner.nextInt() # Child node value
        direction = scanner.next() # Direction (L or R)

        # Link the child to the parent based on the direction
        if direction.equals("L"):
            nodes[parent].left = nodes[child] # Set left child
        else if direction.equals("R"):
            nodes[parent].right = nodes[child] # Set right child

    # Perform vertical traversal starting from the root node
    result = verticalTraversal(nodes[1])
    
    # Print the result of the vertical traversal
    for value in result:
        print(value, end = " ")
    
    # Close the scanner
    scanner.close()

