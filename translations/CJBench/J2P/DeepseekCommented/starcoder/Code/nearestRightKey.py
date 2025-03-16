import java.util.HashMap; // Importing HashMap for managing nodes
import java.util.Map; // Importing Map for generic map operations
import java.util.Scanner; // Importing Scanner for input

def main():
    sc = Scanner(System.in); // Creating a Scanner object for input
    n = sc.nextInt(); // Reading the number of nodes
    nodeMap = HashMap(); // Creating a HashMap to store nodes by their values
    root = None; // Initializing the root of the tree

    # Reading each node's value, left child, and right child, and constructing the tree
    for i in range(n):
        value = sc.nextInt();
        left = sc.nextInt();
        right = sc.nextInt();
        nodeMap.putIfAbsent(value, NRKTree(value)); # Adding the node to the map if it doesn't exist
        current = nodeMap.get(value); # Getting the current node
        if root == None:
            root = current; # Setting the root if it's the first node
        if left!= -1:
            nodeMap.putIfAbsent(left, NRKTree(left)); # Adding left child if it exists
            current.left = nodeMap.get(left); # Linking the left child
        if right!= -1:
            nodeMap.putIfAbsent(right, NRKTree(right)); # Adding right child if it exists
            current.right = nodeMap.get(right); # Linking the right child

    inputX0 = sc.nextInt(); # Reading the value to find the nearest right key for
    toPrint = Main(root, inputX0); # Calling the Main method to find the nearest right key
    if toPrint == 0:
        print("No nearest right key found."); # Printing if no key is found
    else:
        print("Nearest Right Key: " + toPrint); # Printing the nearest right key
    sc.close(); # Closing the Scanner

# Recursive method to find the nearest right key greater than x0
def Main(root, x0):
    if root == None:
        return 0; # Returning 0 if the tree is empty
    else:
        if root.data > x0:
            temp = Main(root.left, x0); # Recursively searching in the left subtree
            if temp == 0:
                return root.data; # Returning the current node's data if no greater key is found in the left subtree
            return temp; # Returning the found key from the left subtree
        else:
            return Main(root.right, x0); # Recursively searching in the right subtree

class NRKTree:
    def __init__(self, x):
        self.left = None; # Initializing left child as null
        self.right = None; # Initializing right child as null
        self.data = x; # Setting the data value

if __name__ == "__main__":
    main();

