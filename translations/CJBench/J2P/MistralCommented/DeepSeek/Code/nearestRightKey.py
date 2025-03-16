class NRKTree:
    def __init__(self, x):
        self.left = None
        self.right = None
        self.data = x

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the number of nodes in the tree
    n = int(data[0])
    
    # Create a dictionary to store nodes in the tree
    node_map = {}
    
    # Initialize root node to None
    root = None
    
    # Read each node and create a new node if it doesn't exist in the map
    # Put the node in the map and set its left and right children if they exist
    index = 1
    for i in range(n):
        value = int(data[index])
        left = int(data[index + 1])
        right = int(data[index + 2])
        index += 3
        
        # Create a new node if it doesn't exist in the map
        if value not in node_map:
            node_map[value] = NRKTree(value)
        
        # Get the current node
        current = node_map[value]
        
        # If root is None, set the current node as the root
        if root is None:
            root = current
        
        # Set the left child of the current node if it exists
        if left != -1:
            if left not in node_map:
                node_map[left] = NRKTree(left)
            current.left = node_map[left]
        
        # Set the right child of the current node if it exists
        if right != -1:
            if right not in node_map:
                node_map[right] = NRKTree(right)
            current.right = node_map[right]
    
    # Read the input value x0
    input_x0 = int(data[-1])
    
    # Call the recursive function to find the nearest right key
    to_print = find_nearest_right_key(root, input_x0)
    
    # Print the result
    if to_print == 0:
        print("No nearest right key found.")
    else:
        print("Nearest Right Key: " + str(to_print))

def find_nearest_right_key(root, x0):
    # Base case: if root is None, return 0
    if root is None:
        return 0
    
    # If the current node's data is greater than x0, search in the left subtree
    if root.data > x0:
        temp = find_nearest_right_key(root.left, x0)
        
        # If the left subtree doesn't have the answer, return the current node's data
        if temp == 0:
            return root.data
        
        # Otherwise, return the answer from the left subtree
        return temp
    
    # Otherwise, search in the right subtree
    return find_nearest_right_key(root.right, x0)

main()
