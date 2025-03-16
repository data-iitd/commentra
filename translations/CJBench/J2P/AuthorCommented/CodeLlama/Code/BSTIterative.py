
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
                print(data, "is already present in BST.")
                return

        newNode = Node(data)
        if parent is None:
            self.root = newNode # Insert as root if BST is empty
        elif direction == 0:
            parent.left = newNode # Insert as left child
        else:
            parent.right = newNode # Insert as right child

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

        if temp is not None:
            replacement = None

            if temp.left is None and temp.right is None:
                replacement = None # Case 1: No children
            elif temp.left is None:
                replacement = temp.right # Case 2: Right child only
            elif temp.right is None:
                replacement = temp.left # Case 3: Left child only
            else:
                # Case 4: Two children
                successorParent = temp
                successor = temp.right

                while successor.left is not None:
                    successorParent = successor
                    successor = successor.left

                temp.data = successor.data # Replace with successor
                if successorParent != temp:
                    successorParent.left = successor.right
                else:
                    successorParent.right = successor.right
                return

            if parent is None:
                self.root = replacement # Replace root
            elif direction == 0:
                parent.left = replacement
            else:
                parent.right = replacement

    def find(self, data):
        temp = self.root

        while temp is not None:
            if data == temp.data:
                print(data, "is present in the BST.")
                return True
            elif data < temp.data:
                temp = temp.left
            else:
                temp = temp.right

        print(data, "not found.")
        return False

    def display(self):
        self.displayHelper(self.root)
        print()

    def displayHelper(self, node):
        if node is not None:
            self.displayHelper(node.left)
            print(node.data, end=" ")
            self.displayHelper(node.right)

bst = BST()

while True:
    command = input("Enter commands (add <value>, remove <value>, find <value>, display, exit): ")

    if command == "exit":
        break

    parts = command.split()
    try:
        if parts[0] == "add":
            bst.add(int(parts[1]))
            print("Added:", parts[1])
        elif parts[0] == "remove":
            bst.remove(int(parts[1]))
            print("Removed:", parts[1])
        elif parts[0] == "find":
            bst.find(int(parts[1]))
        elif parts[0] == "display":
            bst.display()
        else:
            print("Unknown command:", parts[0])
    except:
        print("Error: Invalid command or input.")

# 