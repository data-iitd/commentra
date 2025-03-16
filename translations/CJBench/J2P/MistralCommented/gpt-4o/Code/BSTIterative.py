class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def add(self, data):
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
            self.root = new_node
        elif direction == 0:
            parent.left = new_node
        else:
            parent.right = new_node

    def remove(self, data):
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

        if temp is None:
            print(f"{data} not found.")
            return

        replacement = None
        if temp.left is None and temp.right is None:
            replacement = None
        elif temp.left is None:
            replacement = temp.right
        elif temp.right is None:
            replacement = temp.left
        else:
            successor_parent = temp
            successor = temp.right

            while successor.left is not None:
                successor_parent = successor
                successor = successor.left

            temp.data = successor.data

            if successor_parent != temp:
                successor_parent.left = successor.right
            else:
                successor_parent.right = successor.right

        if parent is None:
            self.root = replacement
        elif direction == 0:
            parent.left = replacement
        else:
            parent.right = replacement

    def find(self, data):
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
        self.display_helper(self.root)

    def display_helper(self, node):
        if node is not None:
            self.display_helper(node.left)
            print(node.data, end=" ")
            self.display_helper(node.right)

def main():
    bst = BST()
    
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
                print()  # For a new line after display
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception:
            print("Error: Invalid command or input.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
