
import sys

class Trieac:
    # Class to represent a node in Trie
    ALPHABET_SIZE = 26
    class TrieNode:
        def __init__(self):
            self.children = [None] * Trieac.ALPHABET_SIZE
            self.isWordEnd = False

    # Function to get a new TrieNode
    @staticmethod
    def getNode():
        return Trieac.TrieNode()

    # Function to insert a word into Trie
    @staticmethod
    def insert(root, key):
        currentNode = root
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')
            if currentNode.children[index] is None:
                currentNode.children[index] = Trieac.getNode()
            currentNode = currentNode.children[index]
        currentNode.isWordEnd = True

    # Function to search a word in Trie
    @staticmethod
    def search(root, key):
        currentNode = root
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')
            if currentNode.children[index] is None:
                return False
            currentNode = currentNode.children[index]
        return currentNode is not None and currentNode.isWordEnd

    # Function to check if the current node is the last node
    @staticmethod
    def isLastNode(root):
        for i in range(Trieac.ALPHABET_SIZE):
            if root.children[i] is not None:
                return False
        return True

    # Function to print suggestions based on the given prefix
    @staticmethod
    def suggestionsRec(root, currPrefix):
        if root.isWordEnd:
            print(currPrefix)
        if Trieac.isLastNode(root):
            return
        for i in range(Trieac.ALPHABET_SIZE):
            if root.children[i] is not None:
                Trieac.suggestionsRec(root.children[i], currPrefix + chr(ord('a') + i))

    # Function to print auto-suggestions based on the given prefix
    @staticmethod
    def printAutoSuggestions(root, query):
        currentNode = root
        level = 0
        n = len(query)
        for level in range(n):
            index = ord(query[level]) - ord('a')
            if currentNode.children[index] is None:
                return 0
            currentNode = currentNode.children[index]
        isWord = currentNode.isWordEnd
        isLast = Trieac.isLastNode(currentNode)
        if isWord and isLast:
            print(query)
            return -1
        if not isLast:
            Trieac.suggestionsRec(currentNode, query)
            return 1
        return 0

    # Main function
    @staticmethod
    def main():
        sc = sys.stdin
        n = int(sc.readline())  # Read the number of words to be inserted into Trie
        sc.readline()  # Read the newline character left after reading integer

        root = Trieac.getNode()  # Create the root node of Trie

        # Insert words into Trie
        for i in range(n):
            word = sc.readline().strip()  # Read a word from the input
            Trieac.insert(root, word)  # Insert the word into Trie

        prefix = sc.readline().strip()  # Read the prefix for suggestions
        suggestionsCount = Trieac.printAutoSuggestions(root, prefix)  # Print auto-suggestions based on the prefix

        if suggestionsCount == -1:
            print("No other strings found with this prefix\n")  # If the prefix is a word and there are no other words with the same prefix
        elif suggestionsCount == 0:
            print("No string found with this prefix\n")  # If there is no word with the given prefix

        sc.close()  # Close the Scanner

if __name__ == "__main__":
    Trieac.main()
    print("