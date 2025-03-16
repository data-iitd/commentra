
# <START-OF-CODE>

# Class representing a node in the NRK tree
class NRKTree:
    def __init__(self, x):
        self.left = None
        self.right = None
        self.data = x

# Method to find the nearest right key greater than x0 in the tree
def Main(root, x0):
    # Base case: if the current node is null, return 0
    if root == None:
        return 0
    else:
        # If the current node's data is greater than x0
        if root.data > x0:
            # Recursively search in the left subtree
            temp = Main(root.left, x0)
            # If no key was found in the left subtree, return the current node's data
            if temp == 0:
                return root.data
            return temp # Otherwise, return the found key
        else:
            # If the current node's data is not greater, search in the right subtree
            return Main(root.right, x0)

# Main method to read input and call the method Main()
def main():
    # Create a Scanner object to read input from the user
    sc = Scanner(System.in)
    
    # Read the number of nodes in the tree
    n = sc.nextInt()
    
    # Create a map to hold the nodes of the tree
    nodeMap = {}
    root = None # Initialize the root of the tree
    
    # Loop to read each node's value and its children
    for i in range(n):
        value = sc.nextInt() # Read the value of the current node
        left = sc.nextInt()  # Read the left child value
        right = sc.nextInt() # Read the right child value
        
        # If the node does not exist in the map, create and add it
        if value not in nodeMap:
            nodeMap[value] = NRKTree(value)
        current = nodeMap[value] # Get the current node
        
        # Set the root if it is not already set
        if root == None:
            root = current
        
        # If the left child value is valid, add it to the current node
        if left!= -1:
            if left not in nodeMap:
                nodeMap[left] = NRKTree(left)
            current.left = nodeMap[left]
        
        # If the right child value is valid, add it to the current node
        if right!= -1:
            if right not in nodeMap:
                nodeMap[right] = NRKTree(right)
            current.right = nodeMap[right]
    
    # Read the value for which we need to find the nearest right key
    inputX0 = sc.nextInt()
    
    # Call the method to find the nearest right key and store the result
    toPrint = Main(root, inputX0)
    
    # Print the result based on whether a nearest right key was found
    if toPrint == 0:
        print("No nearest right key found.")
    else:
        print("Nearest Right Key: " + str(toPrint))
    
    # Close the scanner to prevent resource leaks
    sc.close()

# Entry point of the program
if __name__ == "__main__":
    main()

# 