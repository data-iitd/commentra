
import sys

# Java Program to implement Auto-Complete Feature using Trie
class Trieac:

    # Alphabet size (# of symbols)
    ALPHABET_SIZE = 26

    # Trie node
    class TrieNode:

        # Trie node
        def __init__(self):
            self.children = [None] * Trieac.ALPHABET_SIZE

            # isWordEnd is true if the node represents end of a word
            self.isWordEnd = False

    # Returns new trie node (initialized to NULLs)
    def getNode(self):
        pNode = Trieac.TrieNode()
        pNode.isWordEnd = False

        for i in range(Trieac.ALPHABET_SIZE):
            pNode.children[i] = None

        return pNode

    # If not present, inserts key into trie. If the key is prefix of trie node, just marks leaf node
    def insert(self, root, key):
        pCrawl = root

        for level in range(len(key)):
            index = ord(key[level]) - ord('a')
            if pCrawl.children[index] == None:
                pCrawl.children[index] = self.getNode()
            pCrawl = pCrawl.children[index]

        # Mark last node as leaf
        pCrawl.isWordEnd = True

    # Returns true if key presents in trie, else false
    def search(self, root, key):
        length = len(key)
        pCrawl = root

        for level in range(length):
            index = ord(key[level]) - ord('a')

            if pCrawl.children[index] == None:
                pCrawl = pCrawl.children[index]

        return (pCrawl != None and pCrawl.isWordEnd)

    # Returns 0 if current node has a child. If all children are NULL, return 1.
    def isLastNode(self, root):
        for i in range(Trieac.ALPHABET_SIZE):
            if root.children[i] != None:
                return False
        return True

    # Recursive function to print auto-suggestions for given node.
    def suggestionsRec(self, root, currPrefix):
        # Found a string in Trie with the given prefix
        if root.isWordEnd:
            print(currPrefix)

        # All children struct node pointers are NULL
        if self.isLastNode(root):
            return

        for i in range(Trieac.ALPHABET_SIZE):
            if root.children[i] != None:
                # Append current character to currPrefix string
                self.suggestionsRec(root.children[i], currPrefix + chr(97 + i))

    # Function to print suggestions for given query prefix.
    def printAutoSuggestions(self, root, query):
        pCrawl = root

        # Check if prefix is present and find the node (of last level) with last character of given string.
        level = 0
        n = len(query)

        for level in range(n):
            index = ord(query[level]) - ord('a')

            # No string in the Trie has this prefix
            if pCrawl.children[index] == None:
                return 0

            pCrawl = pCrawl.children[index]

        # If prefix is present as a word.
        isWord = pCrawl.isWordEnd

        # If prefix is last node of tree (has no children)
        isLast = self.isLastNode(pCrawl)

        # If prefix is present as a word, but there is no subtree below the last matching node.
        if isWord and isLast:
            print(query)
            return -1

        # If there are nodes below the last matching character.
        if not isLast:
            self.suggestionsRec(pCrawl, query)
            return 1

        return 0

    # Driver code
    def main(self):
        sc = sys.stdin

        n = int(sc.readline())
        sc.readline()  # Consume newline

        root = self.getNode()

        for i in range(n):
            self.insert(root, sc.readline().strip())

        prefix = sc.readline().strip()

        comp = self.printAutoSuggestions(root, prefix)

        if comp == -1:
            print("No other strings found with this prefix\n")
        elif comp == 0:
            print("No string found with this prefix\n")

        sc.close()


# Driver code
if __name__ == "__main__":
    obj = Trieac()
    obj.main()


