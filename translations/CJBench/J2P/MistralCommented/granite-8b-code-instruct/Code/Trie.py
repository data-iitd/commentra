

class MainNode:
    # Initialize a MainNode with a given value, an empty dictionary for children, and a boolean flag indicating if it's an end node
    def __init__(self, value):
        self.value = value
        self.child = {}
        self.end = False

class Main:
    # Initialize a private final root node with the value '*'
    ROOT_NODE_VALUE = '*'
    root = MainNode(ROOT_NODE_VALUE)

    def insert(self, word):
        # Initialize currentNode as the root
        currentNode = self.root

        for char in word:
            # If the node for the current character doesn't exist, create a new node and add it as a child to the current node
            if char not in currentNode.child:
                currentNode.child[char] = MainNode(char)
            currentNode = currentNode.child[char]

        # Set the end flag for the last node
        currentNode.end = True

    def search(self, word):
        # Initialize currentNode as the root
        currentNode = self.root

        for char in word:
            # If the node for the current character doesn't exist, return False
            if char not in currentNode.child:
                return False
            currentNode = currentNode.child[char]

        # Return True if the last node is an end node
        return currentNode.end

    def delete(self, word):
        # Initialize currentNode as the root
        currentNode = self.root

        for char in word:
            # If the node for the current character doesn't exist, return False
            if char not in currentNode.child:
                return False
            currentNode = currentNode.child[char]

        # If the last node is not an end node, return False
        if not currentNode.end:
            return False

        # If the last node has no children, remove it from its parent's child dictionary and return True
        if not currentNode.child:
            del currentNode.parent.child[currentNode.value]
            return True

        # Find the node with the smallest character value among the children of the last node
        smallestNode = currentNode
        for child in currentNode.child.values():
            if child.value < smallestNode.value:
                smallestNode = child

        # Merge the children of the last node into the smallest node
        smallestNode.child.update(currentNode.child)

        # Set the end flag for the smallest node
        smallestNode.end = currentNode.end

        # Remove the last node
        del currentNode.parent.child[currentNode.value]

        return True

    def countWords(self):
        return self.countWordsHelper(self.root)

    def countWordsHelper(self, node):
        count = 0

        # If the node is an end node, increment the count
        if node.end:
            count += 1

        # Recursively count the number of words in the children of the node
        for child in node.child.values():
            count += self.countWordsHelper(child)

        return count

    def startsWithPrefix(self, prefix):
        # Initialize currentNode as the root
        currentNode = self.root

        for char in prefix:
            # If the node for the current character doesn't exist, return False
            if char not in currentNode.child:
                return False
            currentNode = currentNode.child[char]

        # Return True if the last node is an end node
        return currentNode.end

    def countWordsWithPrefix(self, prefix):
        # Initialize currentNode as the root
        currentNode = self.root

        for char in prefix:
            # If the node for the current character doesn't exist, return 0
            if char not in currentNode.child:
                return 0
            currentNode = currentNode.child[char]

        # Return the number of words in the sub-Main rooted at the last node
        return self.countWordsHelper(currentNode)

# Main method to read input and perform operations on the Main
if __name__ == "__main__":
    import sys

    n = int(input())  # Read the number of operations
    input()  # Read the newline character

    main = Main()  # Initialize a new Main object to represent the Main

    for _ in range(n):
        operation = input().split()  # Read the operation

        if operation[0] == "insert":
            word = operation[1]  # Read the word to be inserted
            main.insert(word)  # Perform the insertion
        elif operation[0] == "search":
            word = operation[1]  # Read the word to be searched
            print(main.search(word))  # Print the search result
        elif operation[0] == "delete":
            word = operation[1]  # Read the word to be deleted
            print(main.delete(word))  # Print the deletion result
        elif operation[0] == "countWords":
            print(main.countWords())  # Print the number of words in the Main
        elif operation[0] == "startsWith":
            prefix = operation[1]  # Read the prefix
            print(main.startsWithPrefix(prefix))  # Print whether the Main starts with the prefix
        elif operation[0] == "countWithPrefix":
            prefix = operation[1]  # Read the prefix
            print(main.countWordsWithPrefix(prefix))  # Print the number of words in the Main that start with the prefix

    sys.stdout.flush()  # Flush the output buffer

