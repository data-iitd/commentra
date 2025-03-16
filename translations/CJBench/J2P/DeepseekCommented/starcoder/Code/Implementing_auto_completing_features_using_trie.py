import sys

# Defining the size of the alphabet.
ALPHABET_SIZE = 26

# Nested TrieNode class representing each node in the Trie.
class TrieNode:
    def __init__(self):
        self.children = [None] * ALPHABET_SIZE
        self.isWordEnd = False

# Method to get a new TrieNode initialized with default values.
def getNode():
    pNode = TrieNode()
    pNode.isWordEnd = False
    for i in range(ALPHABET_SIZE):
        pNode.children[i] = None
    return pNode

# Method to insert a word into the Trie.
def insert(root, key):
    pCrawl = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if pCrawl.children[index] == None:
            pCrawl.children[index] = getNode()
        pCrawl = pCrawl.children[index]
    pCrawl.isWordEnd = True

# Method to search for a word in the Trie.
def search(root, key):
    length = len(key)
    pCrawl = root
    for level in range(length):
        index = ord(key[level]) - ord('a')
        if pCrawl.children[index] == None:
            return False # Word not found.
        pCrawl = pCrawl.children[index]
    return (pCrawl!= None and pCrawl.isWordEnd) # Check if the word ends at this node.

# Method to check if a given node is the last node in the Trie.
def isLastNode(root):
    for i in range(ALPHABET_SIZE):
        if root.children[i]!= None:
            return False # Node has children.
    return True # Node has no children.

# Recursive method to generate suggestions from a given node.
def suggestionsRec(root, currPrefix):
    if root.isWordEnd:
        print(currPrefix) # Print the word if it ends at this node.
    if isLastNode(root):
        return # Stop recursion if this is the last node.
    for i in range(ALPHABET_SIZE):
        if root.children[i]!= None:
            suggestionsRec(root.children[i], currPrefix + chr(97 + i)) # Recursively call for each child.

# Method to print auto-suggestions based on a given prefix.
def printAutoSuggestions(root, query):
    pCrawl = root
    level = 0
    n = len(query)
    for level in range(n):
        index = ord(query[level]) - ord('a')
        if pCrawl.children[index] == None:
            return 0 # Prefix not found.
        pCrawl = pCrawl.children[index]
    isWord = (pCrawl.isWordEnd)
    isLast = isLastNode(pCrawl)
    if isWord and isLast:
        print(query) # The entire word is a suggestion.
        return -1
    if not isLast:
        suggestionsRec(pCrawl, query) # Print suggestions for the remaining characters.
        return 1
    return 0

# Main method to run the program.
if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        insert(root, input())
    prefix = input()
    comp = printAutoSuggestions(root, prefix)
    if comp == -1:
        print("No other strings found with this prefix\n")
    elif comp == 0:
        print("No string found with this prefix\n")

