
# Import the Scanner class from the java.util package
from java.util import Scanner

# Create a Scanner object to read input from the user
sc = Scanner(System.in)

# Read the number of nodes in the tree
n = sc.nextInt()

# Create a dictionary to hold the nodes of the tree
nodeMap = {}
root = None # Initialize the root of the tree

# Loop to read each node's value and its children
for i in range(n):
    value = sc.nextInt() # Read the value of the current node
    left = sc.nextInt()  # Read the left child value
    right = sc.nextInt() # Read the right child value
    
    # If the node does not exist in the dictionary, create and add it
    if value not in nodeMap:
        nodeMap[value] = NRKTree(value)
    current = nodeMap[value] # Get the current node
    
    # Set the root if it is not already set
    if root is None:
        root = current
    
    # If the left child value is valid, add it to the current node
    if left != -1:
        if left not in nodeMap:
            nodeMap[left] = NRKTree(left)
        current.left = nodeMap[left]
    
    # If the right child value is valid, add it to the current node
    if right != -1:
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
    print("Nearest Right Key: " + toPrint)

# Close the scanner to prevent resource leaks
sc.close()

# END-OF-CODE
