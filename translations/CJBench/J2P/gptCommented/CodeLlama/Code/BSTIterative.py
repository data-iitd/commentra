
# Root node of the binary search tree
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

        while temp:
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
            self.root = newNode
        elif direction == 0:
            parent.left = newNode
        else:
            parent.right = newNode

    def remove(self, data):
        parent = None
        temp = self.root
        direction = -1

        while temp:
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

        if temp:
            replacement = None

            if temp.left is None and temp.right is None:
                replacement = None
            elif temp.left is None:
                replacement = temp.right
            elif temp.right is None:
                replacement = temp.left
            else:
                successorParent = temp
                successor = temp.right

                while successor.left:
                    successorParent = successor
                    successor = successor.left

                temp.data = successor.data
                if successorParent != temp:
                    successorParent.left = successor.right
                else:
                    successorParent.right = successor.right
                return

            if parent is None:
                self.root = replacement
            elif direction == 0:
                parent.left = replacement
            else:
                parent.right = replacement

    def find(self, data):
        temp = self.root

        while temp:
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
        if node:
            self.displayHelper(node.left)
            print(node.data, end=" ")
            self.displayHelper(node.right)

bst = BST()

while True:
    command = input().strip()
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