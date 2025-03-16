

import sys

# Python program to implement Auto-Complete Feature using Trie

# Alphabet size (# of symbols)
ALPHABET_SIZE = 26

# Trie node
class TrieNode:
    def __init__(self):
        self.children = [None] * ALPHABET_SIZE
        self.isWordEnd = False

# Returns new trie node (initialized to NULLs)
def getNode():
    pNode = TrieNode()
    pNode.isWordEnd = False

    for i in range(ALPHABET_SIZE):
        pNode.children[i] = None

    return pNode

# If not present, inserts key into trie. If the key is prefix of trie node, just marks leaf node
def insert(root, key):
    pCrawl = root

    for level in range(len(key)):
        index = ord(key[level]) - ord('a')

        if pCrawl.children[index] == None:
            pCrawl.children[index] = getNode()

        pCrawl = pCrawl.children[index]

    # Mark last node as leaf
    pCrawl.isWordEnd = True

# Returns true if key presents in trie, else false
def search(root, key):
    length = len(key)
    pCrawl = root

    for level in range(length):
        index = ord(key[level]) - ord('a')

        if pCrawl.children[index] == None:
            return False
        pCrawl = pCrawl.children[index]

    return pCrawl!= None and pCrawl.isWordEnd

# Returns 0 if current node has a child. If all children are NULL, return 1.
def isLastNode(root):
    for i in range(ALPHABET_SIZE):
        if root.children[i]!= None:
            return False
    return True

# Recursive function to print auto-suggestions for given node.
def suggestionsRec(root, currPrefix):
    # Found a string in Trie with the given prefix
    if root.isWordEnd:
        print(currPrefix)

    # All children struct node pointers are NULL
    if isLastNode(root):
        return

    for i in range(ALPHABET_SIZE):
        if root.children[i]!= None:
            # Append current character to currPrefix string
            suggestionsRec(root.children[i], currPrefix + chr(i + ord('a')))

# Function to print suggestions for given query prefix.
def printAutoSuggestions(root, query):
    pCrawl = root

    # Check if prefix is present and find the node (of last level) with last character of given string.
    length = len(query)
    level = 0

    for level in range(length):
        index = ord(query[level]) - ord('a')

        # No string in the Trie has this prefix
        if pCrawl.children[index] == None:
            return 0

        pCrawl = pCrawl.children[index]

    # If prefix is present as a word.
    isWord = pCrawl.isWordEnd

    # If prefix is last node of tree (has no children)
    isLast = isLastNode(pCrawl)

    # If prefix is present as a word, but there is no subtree below the last matching node.
    if isWord and isLast:
        print(query)
        return -1

    # If there are nodes below the last matching character.
    if not isLast:
        suggestionsRec(pCrawl, query)
        return 1

    return 0

# Driver code
if __name__ == '__main__':
    n = int(input())
    sys.stdin.readline() # Consume newline

    root = getNode()

    for i in range(n):
        insert(root, sys.stdin.readline().strip())

    prefix = sys.stdin.readline().strip()

    comp = printAutoSuggestions(root, prefix)

    if comp == -1:
        print("No other strings found with this prefix\n")
    elif comp == 0:
        print("No string found with this prefix\n")

