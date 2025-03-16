import collections
import sys

# Class representing a node in the Main
class MainNode:
    def __init__(self, value):
        self.value = value
        self.child = collections.defaultdict(MainNode)
        self.end = False

# Main class for the Main data structure
class Main:
    def __init__(self):
        self.root = MainNode('*')

    # Method to insert a word into the Main
    def insert(self, word):
        currentNode = self.root
        for i in range(len(word)):
            # Get the child node corresponding to the current character
            node = currentNode.child.get(word[i], None)
            # If the node does not exist, create a new one
            if node is None:
                node = MainNode(word[i])
                currentNode.child[word[i]] = node
            currentNode = node
        currentNode.end = True

    # Method to search for a word in the Main
    def search(self, word):
        currentNode = self.root
        for i in range(len(word)):
            # Get the child node corresponding to the current character
            node = currentNode.child.get(word[i], None)
            # If the node does not exist, the word is not in the Main
            if node is None:
                return False
            currentNode = node
        return currentNode.end

    # Method to delete a word from the Main
    def delete(self, word):
        currentNode = self.root
        for i in range(len(word)):
            # Get the child node corresponding to the current character
            node = currentNode.child.get(word[i], None)
            # If the node does not exist, the word cannot be deleted
            if node is None:
                return False
            currentNode = node
        # If the current node marks the end of a word, unmark it
        if currentNode.end:
            currentNode.end = False
            return True
        return False

    # Method to count the total number of words in the Main
    def countWords(self):
        return self.countWords(self.root)

    # Helper method to recursively count words from a given node
    def countWords(self, node):
        if node is None:
            return 0
        count = 0
        if node.end:
            count += 1
        for child in node.child.values():
            count += self.countWords(child)
        return count

    # Method to check if any word in the Main starts with a given prefix
    def startsWithPrefix(self, prefix):
        currentNode = self.root
        for i in range(len(prefix)):
            # Get the child node corresponding to the current character
            node = currentNode.child.get(prefix[i], None)
            # If the node does not exist, no word starts with the prefix
            if node is None:
                return False
            currentNode = node
        return True

    # Method to count the number of words that start with a given prefix
    def countWordsWithPrefix(self, prefix):
        currentNode = self.root
        for i in range(len(prefix)):
            # Get the child node corresponding to the current character
            node = currentNode.child.get(prefix[i], None)
            # If the node does not exist, return 0 as no words match the prefix
            if node is None:
                return 0
            currentNode = node
        return self.countWords(currentNode)

    # Main method to run the Main operations based on user input
    def main(self):
        scanner = sys.stdin
        n = int(scanner.readline())
        for i in range(n):
            operation = scanner.readline().strip()
            if operation == 'insert':
                word = scanner.readline().strip()
                self.insert(word)
            elif operation =='search':
                word = scanner.readline().strip()
                print(self.search(word))
            elif operation == 'delete':
                word = scanner.readline().strip()
                print(self.delete(word))
            elif operation == 'countWords':
                print(self.countWords())
            elif operation =='startsWith':
                prefix = scanner.readline().strip()
                print(self.startsWithPrefix(prefix))
            elif operation == 'countWithPrefix':
                prefix = scanner.readline().strip()
                print(self.countWordsWithPrefix(prefix))

# Main method to run the Main operations based on user input
if __name__ == '__main__':
    trie = Main()
    trie.main()

