
class Main:
    # Declare a private nested class Node for AVL tree node
    class Node:
        def __init__(self, data):
            self.data = data
            self.height = 1
            self.left = None
            self.right = None
    
    # Declare a reference for root node
    root = None
    
    # Method to insert a new node with given data into the tree
    def insert(self, data):
        self.root = self.insert(self.root, data)
    
    # Recursive method to insert a new node with given data into the tree
    def insert(self, node, item):
        # Base case: if node is null, create a new node with given data
        if node == None:
            return Node(item)
        
        # Recursive case: if the new data is less than the current node's data, traverse left
        if node.data > item:
            node.left = self.insert(node.left, item)
        elif node.data < item: # if the new data is greater than the current node's data, traverse right
            node.right = self.insert(node.right, item)
        
        # Update the height of the current node
        node.height = max(self.height(node.left), self.height(node.right)) + 1
        
        # Check for balance factor and perform rotations if necessary
        bf = self.bf(node)
        if bf > 1: # if the balance factor is greater than 1, perform right rotation
            if item < node.left.data:
                return self.rightRotate(node)
            node.right = self.rightRotate(node.right) # perform right rotation on the right subtree if needed
            return self.leftRotate(node) # perform left rotation on the current node
        elif bf < -1: # if the balance factor is less than -1, perform left rotation
            if item > node.right.data:
                return self.leftRotate(node)
            node.left = self.leftRotate(node.left) # perform left rotation on the left subtree if needed
            return self.rightRotate(node) # perform right rotation on the current node
        return node # if the tree is balanced, return the current node
    
    # Method to display the tree structure and its height
    def display(self):
        self.display(self.root)
        print("Tree Height: " + str(self.root.height))
    
    # Recursive method to display the tree structure
    def display(self, node):
        if node == None:
            return
        str = ""
        # If the current node has a left child, append its data to the string
        if node.left!= None:
            str += str(node.left.data) + " => "
        else:
            str += "END => " # if the left child is null, append "END" to the string
        # Append the current node's data to the string
        str += str(node.data)
        # If the current node has a right child, append its data to the string with a separator
        if node.right!= None:
            str += " <= " + str(node.right.data)
        else:
            str += " <= END" # if the right child is null, append "<= END" to the string
        print(str) # print the string to the console
        # Recursively display the left and right subtrees
        if node.left!= None:
            self.display(node.left)
        if node.right!= None:
            self.display(node.right)
    
    # Helper method to calculate the height of a node
    def height(self, node):
        if node == None:
            return 0
        return node.height
    
    # Helper method to calculate the balance factor of a node
    def bf(self, node):
        if node == None:
            return 0
        return self.height(node.left) - self.height(node.right)
    
    # Method to perform right rotation on a node
    def rightRotate(self, c):
        b = c.left
        t3 = b.right
        
        # Update the references of the nodes
        b.right = c
        c.left = t3
        
        # Update the heights of the nodes
        c.height = max(self.height(c.left), self.height(c.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1
        
        return b # return the new root of the subtree
    
    # Method to perform left rotation on a node
    def leftRotate(self, c):
        b = c.right
        t3 = b.left
        
        # Update the references of the nodes
        b.left = c
        c.right = t3
        
        # Update the heights of the nodes
        c.height = max(self.height(c.left), self.height(c.right)) + 1
        b.height = max(self.height(b.left), self.height(b.right)) + 1
        
        return b # return the new root of the subtree

# Main method to read user input and call the methods
if __name__ == "__main__":
    tree = Main()
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break
        parts = command.split(" ")
        try:
            if parts[0].lower() == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                else:
                    value = int(parts[1])
                    tree.insert(value)
                    print("Inserted: " + str(value))
            elif parts[0].lower() == "display":
                tree.display()
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + str(e))

