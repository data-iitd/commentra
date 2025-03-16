class Node:
    """Node class represents each node in the BST."""
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinarySearchTree:
    """Main implements a Binary Search Tree using an iterative approach."""
    def __init__(self):
        self.root = None

    def add(self, data):
        """Adds a value to the BST."""
        parent = None
        temp = self.root
        direction = -1

        while temp is not None:
            if data < temp.data:
                parent = temp
                temp = temp.left
                direction = 0
            elif data > temp.data:
                parent = temp
                temp = temp.right
                direction = 1
            else:
                print(f"{data} is already present in BST.")
                return

        new_node = Node(data)
        if parent is None:
            self.root = new_node  # Insert as root if BST is empty
        elif direction == 0:
            parent.left = new_node  # Insert as left child
        else:
            parent.right = new_node  # Insert as right child

    def remove(self, data):
        """Removes a value from the BST."""
        parent = None
        temp = self.root
        direction = -1

        while temp is not None:
            if temp.data == data:
                break
            elif data < temp.data:
                parent = temp
                temp = temp.left
                direction = 0
            else:
                parent = temp
                temp = temp.right
                direction = 1

        if temp is not None:
            replacement = None

            if temp.left is None and temp.right is None:
                replacement = None  # Case 1: No children
            elif temp.left is None:
                replacement = temp.right  # Case 2: Right child only
            elif temp.right is None:
                replacement = temp.left  # Case 3: Left child only
            else:
                # Case 4: Two children
                successor_parent = temp
                successor = temp.right

                while successor.left is not None:
                    successor_parent = successor
                    successor = successor.left

                temp.data = successor.data  # Replace with successor
                if successor_parent != temp:
                    successor_parent.left = successor.right
                else:
                    successor_parent.right = successor.right
                return

            if parent is None:
                self.root = replacement  # Replace root
            elif direction == 0:
                parent.left = replacement
            else:
                parent.right = replacement

    def find(self, data):
        """Searches for a value in the BST."""
        temp = self.root

        while temp is not None:
            if data == temp.data:
                print(f"{data} is present in the BST.")
                return True
            elif data < temp.data:
                temp = temp.left
            else:
                temp = temp.right

        print(f"{data} not found.")
        return False

    def display(self):
        """Displays the BST in in-order traversal."""
        self.display_helper(self.root)
        print()

    def display_helper(self, node):
        if node is not None:
            self.display_helper(node.left)
            print(node.data, end=" ")
            self.display_helper(node.right)


def main():
    bst = BinarySearchTree()
    print("Enter commands (add <value>, remove <value>, find <value>, display, exit):")

    while True:
        command = input().strip()

        if command.lower() == "exit":
            break

        parts = command.split()
        try:
            if parts[0] == "add":
                bst.add(int(parts[1]))
                print(f"Added: {parts[1]}")
            elif parts[0] == "remove":
                bst.remove(int(parts[1]))
                print(f"Removed: {parts[1]}")
            elif parts[0] == "find":
                bst.find(int(parts[1]))
            elif parts[0] == "display":
                bst.display()
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception:
            print("Error: Invalid command or input.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
