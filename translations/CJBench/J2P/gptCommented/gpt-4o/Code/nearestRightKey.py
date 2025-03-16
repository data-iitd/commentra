class NRKTree:
    def __init__(self, x):
        self.left = None  # Initialize left child as None
        self.right = None  # Initialize right child as None
        self.data = x  # Set the node's value

def find_nearest_right_key(root, x0):
    # Base case: if the current node is None, return 0
    if root is None:
        return 0
    else:
        # If the current node's data is greater than x0
        if root.data > x0:
            # Recursively search in the left subtree
            temp = find_nearest_right_key(root.left, x0)
            # If no key was found in the left subtree, return the current node's data
            if temp == 0:
                return root.data
            return temp  # Otherwise, return the found key
        else:
            # If the current node's data is not greater, search in the right subtree
            return find_nearest_right_key(root.right, x0)

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    # Read the number of nodes in the tree
    n = int(data[0])
    
    # Create a map to hold the nodes of the tree
    node_map = {}
    root = None  # Initialize the root of the tree
    
    # Loop to read each node's value and its children
    for i in range(1, n + 1):
        value, left, right = map(int, data[i].split())
        
        # If the node does not exist in the map, create and add it
        if value not in node_map:
            node_map[value] = NRKTree(value)
        current = node_map[value]  # Get the current node
        
        # Set the root if it is not already set
        if root is None:
            root = current
        
        # If the left child value is valid, add it to the current node
        if left != -1:
            if left not in node_map:
                node_map[left] = NRKTree(left)
            current.left = node_map[left]
        
        # If the right child value is valid, add it to the current node
        if right != -1:
            if right not in node_map:
                node_map[right] = NRKTree(right)
            current.right = node_map[right]
    
    # Read the value for which we need to find the nearest right key
    input_x0 = int(data[n + 1])
    
    # Call the method to find the nearest right key and store the result
    to_print = find_nearest_right_key(root, input_x0)
    
    # Print the result based on whether a nearest right key was found
    if to_print == 0:
        print("No nearest right key found.")
    else:
        print("Nearest Right Key:", to_print)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
