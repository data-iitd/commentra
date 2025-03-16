class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def add(self, data):
        parent = None
        temp = self.root
        direction = -1
        while temp!= None:
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
        if parent == None:
            self.root = newNode
        else:
            if direction == 0:
                parent.left = newNode
            else:
                parent.right = newNode

    def remove(self, data):
        parent = None
        temp = self.root
        direction = -1
        while temp!= None:
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
        if temp!= None:
            replacement = None
            if temp.left == None and temp.right == None:
                replacement = None
            elif temp.left == None:
                replacement = temp.right
            elif temp.right == None:
                replacement = temp.left
            else:
                successorParent = temp
                successor = temp.right
                while successor.left!= None:
                    successorParent = successor
                    successor = successor.left
                temp.data = successor.data
                if successorParent!= temp:
                    successorParent.left = successor.right
                else:
                    successorParent.right = successor.right
                return
            if parent == None:
                self.root = replacement
            else:
                if direction == 0:
                    parent.left = replacement
                else:
                    parent.right = replacement

    def find(self, data):
        temp = self.root
        while temp!= None:
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
        if node!= None:
            self.displayHelper(node.left)
            print(node.data, end=" ")
            self.displayHelper(node.right)

if __name__ == "__main__":
    bst = BinarySearchTree()
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break
        parts = command.split(" ")
        try:
            if parts[0].lower() == "add":
                bst.add(int(parts[1]))
                print("Added:", parts[1])
            elif parts[0].lower() == "remove":
                bst.remove(int(parts[1]))
                print("Removed:", parts[1])
            elif parts[0].lower() == "find":
                bst.find(int(parts[1]))
            elif parts[0].lower() == "display":
                bst.display()
            else:
                print("Unknown command:", parts[0])
        except Exception:
            print("Error: Invalid command or input.")

