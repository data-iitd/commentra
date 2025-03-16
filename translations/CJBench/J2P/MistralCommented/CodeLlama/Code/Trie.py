
class MainNode:
    # Initialize a MainNode with a given value, an empty dictionary for children, and a boolean flag indicating if it's an end node
    def __init__(self, value):
        self.value = value
        self.child = {}
        self.end = False

class Main:
    # Initialize a private final root node with the value '*'
    ROOT_NODE_VALUE = '*'

    def __init__(self):
        # Initialize the root node
        self.root = MainNode(Main.ROOT_NODE_VALUE)

    # Method to insert a word into the Main
    def insert(self, word):
        currentNode = self.root # Initialize currentNode as the root

        for i in range(len(word)):
            node = currentNode.child.get(word[i], None)
            # If the node for the current character doesn't exist, create a new node and add it as a child to the current node
            if node is None:
                node = MainNode(word[i])
                currentNode.child[word[i]] = node
            currentNode = node # Move to the next node
        # Set the end flag for the last node
        currentNode.end = True

    # Method to search for a word in the Main
    def search(self, word):
        currentNode = self.root # Initialize currentNode as the root

        for i in range(len(word)):
            node = currentNode.child.get(word[i], None)
            # If the node for the current character doesn't exist, return false
            if node is None:
                return False
            currentNode = node # Move to the next node
        # Return true if the last node is an end node
        return currentNode.end

    # Method to delete a word from the Main
    def delete(self, word):
        currentNode = self.root # Initialize currentNode as the root

        for i in range(len(word)):
            node = currentNode.child.get(word[i], None)
            # If the node for the current character doesn't exist, return false
            if node is None:
                return False
            currentNode = node # Move to the next node
        # If the last node is not an end node, return false
        if not currentNode.end:
            return False
        # If the last node has no children, set its parent's child reference to None and return true
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

    # Method to count the number of words in the Main
    def countWords(self):
        return self.countWords(self.root)

    # Recursive method to count the number of words in the Main
    def countWords(self, node):
        count = 0
        # If the node is an end node, increment the count
        if node.end:
            count += 1
        # Recursively count the number of words in the children of the node
        for child in node.child.values():
            count += self.countWords(child)
        return count

    # Method to check if a word starts with a given prefix in the Main
    def startsWithPrefix(self, prefix):
        currentNode = self.root # Initialize currentNode as the root

        for i in range(len(prefix)):
            node = currentNode.child.get(prefix[i], None)
            # If the node for the current character doesn't exist, return false
            if node is None:
                return False
            currentNode = node # Move to the next node
        # Return true if the last node is an end node
        return currentNode.end

    # Method to count the number of words in the Main that start with a given prefix
    def countWordsWithPrefix(self, prefix):
        currentNode = self.root # Initialize currentNode as the root

        for i in range(len(prefix)):
            node = currentNode.child.get(prefix[i], None)
            # If the node for the current character doesn't exist, return 0
            if node is None:
                return 0
            currentNode = node # Move to the next node
        # Return the number of words in the sub-Main rooted at the last node
        return self.countWords(currentNode)

    # Main method to read input and perform operations on the Main
    def main():
        n = int(input()) # Read the number of operations

        trie = Main() # Initialize a new Main object to represent the Main

        for i in range(n):
            operation = input().split() # Read the operation

            if operation[0] == "insert":
                word = operation[1] # Read the word to be inserted
                trie.insert(word) # Perform the insertion
            elif operation[0] == "search":
                word = operation[1] # Read the word to be searched
                print(trie.search(word)) # Print the search result
            elif operation[0] == "delete":
                word = operation[1] # Read the word to be deleted
                print(trie.delete(word)) # Print the deletion result
            elif operation[0] == "countWords":
                print(trie.countWords()) # Print the number of words in the Main
            elif operation[0] == "startsWith":
                prefix = operation[1] # Read the prefix
                print(trie.startsWithPrefix(prefix)) # Print whether the Main starts with the prefix
            elif operation[0] == "countWithPrefix":
                prefix = operation[1] # Read the prefix
                print(trie.countWordsWithPrefix(prefix)) # Print the number of words in the Main that start with the prefix

if __name__ == "__main__":
    Main.main()

