class Node:
    def __init__(self, data):
        self.data = data  # Data stored in the node
        self.children = []  # List to hold child nodes

class Tree:
    def __init__(self):
        self.root = None  # Root node of the tree

    def create_tree(self, parent=None, child_index=0):
        if parent is None:
            data = int(input("Enter root's data: "))
        else:
            data = int(input(f"Enter data for child {child_index + 1} of {parent.data}: "))
        
        node = Node(data)  # Create a new node
        num_children = int(input(f"Enter the number of children for {node.data}: "))  # Number of children
        
        for i in range(num_children):
            child = self.create_tree(node, i)  # Create child node
            node.children.append(child)  # Add child to the current node
        
        if parent is None:
            self.root = node  # Set root if it's the first node
        
        return node  # Return the created node

    def display(self):
        self.display_tree(self.root)  # Start displaying from the root

    def display_tree(self, node):
        print(f"{node.data} => ", end="")  # Print current node's data
        for child in node.children:
            print(f"{child.data} ", end="")  # Print each child's data
        print(".")  # End of current node's children
        
        for child in node.children:
            self.display_tree(child)  # Recursively display each child node

    def size(self):
        return self.size_helper(self.root)  # Start size calculation from the root

    def size_helper(self, node):
        size = 0  # Initialize size count
        for child in node.children:
            size += self.size_helper(child)  # Add size of each child
        return size + 1  # Return total size including the current node

    def max(self):
        return self.max_helper(self.root)  # Start max calculation from the root

    def max_helper(self, node):
        max_value = node.data  # Initialize max with current node's data
        for child in node.children:
            max_value = max(max_value, self.max_helper(child))  # Compare with child's max
        return max_value  # Return the maximum value found

    def height(self):
        return self.height_helper(self.root) - 1  # Height is one less than the depth

    def height_helper(self, node):
        height = 0  # Initialize height count
        for child in node.children:
            height = max(height, self.height_helper(child))  # Get max height from children
        return height + 1  # Return height including the current node

    def find(self, value):
        return self.find_helper(self.root, value)  # Start search from the root

    def find_helper(self, node, value):
        if node.data == value:
            return True  # Value found
        for child in node.children:
            if self.find_helper(child, value):
                return True  # Value found in child
        return False  # Value not found

    def level_order(self):
        queue = [self.root]  # Queue for level order traversal
        while queue:
            current = queue.pop(0)  # Get the current node
            print(current.data, end=" ")  # Print current node's data
            queue.extend(current.children)  # Add all children to the queue
        print()  # New line after traversal

if __name__ == "__main__":
    tree = Tree()  # Create a new tree
    tree.create_tree()  # Create the tree from user input
    print("\nTree Display:")
    tree.display()  # Display the created tree
    print(f"\nSize of the tree: {tree.size()}")  # Print size of the tree
    print(f"Maximum value in the tree: {tree.max()}")  # Print max value in the tree
    print(f"Height of the tree: {tree.height()}")  # Print height of the tree
    search_value = int(input("\nEnter a value to search: "))  # Get value to search from user
    print(f"Is value present: {tree.find(search_value)}")  # Check if value is present
    print("\nLevel Order Traversal:")
    tree.level_order()  # Print level order traversal of the tree

# <END-OF-CODE>
