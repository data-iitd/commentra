import sys

# Constant representing the size of the alphabet (26 letters)
ALPHABET_SIZE = 26

# TrieNode class representing each node in the Trie
class TrieNode:
    # Array of children nodes
    children = [None] * ALPHABET_SIZE
    # Boolean flag to indicate if the node marks the end of a word
    isWordEnd = False

# Method to create and initialize a new TrieNode
def getNode():
    pNode = TrieNode()
    pNode.isWordEnd = False # Initially, it is not the end of a word
    # Initialize all children to null
    for i in range(ALPHABET_SIZE):
        pNode.children[i] = None
    return pNode

# Method to insert a new key (word) into the Trie
def insert(root, key):
    pCrawl = root # Start from the root node
    # Iterate through each character of the key
    for level in range(len(key)):
        index = ord(key[level]) - ord('a') # Calculate index for the character
        # If the child node does not exist, create a new node
        if pCrawl.children[index] == None:
            pCrawl.children[index] = getNode()
        # Move to the child node
        pCrawl = pCrawl.children[index]
    # Mark the end of the word
    pCrawl.isWordEnd = True

# Method to search for a key (word) in the Trie
def search(root, key):
    length = len(key)
    pCrawl = root # Start from the root node
    # Iterate through each character of the key
    for level in range(length):
        index = ord(key[level]) - ord('a') # Calculate index for the character
        # If the child node does not exist, return false
        if pCrawl.children[index] == None:
            return False # Key not found
        # Move to the child node
        pCrawl = pCrawl.children[index]
    # Return true if the current node marks the end of a word
    return (pCrawl!= None and pCrawl.isWordEnd)

# Method to check if the current node is the last node (no children)
def isLastNode(root):
    for i in range(ALPHABET_SIZE):
        # If any child exists, return false
        if root.children[i]!= None:
            return False
    return True # No children exist

# Recursive method to find and print suggestions based on the current prefix
def suggestionsRec(root, currPrefix):
    # If the current node marks the end of a word, print the prefix
    if root.isWordEnd:
        print(currPrefix)
    # If the current node is the last node, return
    if isLastNode(root):
        return
    # Iterate through all possible children nodes
    for i in range(ALPHABET_SIZE):
        # If the child node exists, recursively call suggestionsRec
        if root.children[i]!= None:
            suggestionsRec(root.children[i], currPrefix + chr(97 + i))

# Method to print auto-suggestions for a given query
def printAutoSuggestions(root, query):
    pCrawl = root # Start from the root node
    level = 0
    n = len(query)
    # Traverse the Trie according to the characters in the query
    for level in range(n):
        index = ord(query[level]) - ord('a') # Calculate index for the character
        # If the child node does not exist, return 0 (no suggestions)
        if pCrawl.children[index] == None:
            return 0
        # Move to the child node
        pCrawl = pCrawl.children[index]
    # Check if the current node is a word and if it is the last node
    isWord = (pCrawl.isWordEnd)
    isLast = isLastNode(pCrawl)
    # If the query is a word and also the last node, print it and return -1
    if isWord and isLast:
        print(query)
        return -1
    # If not the last node, print suggestions
    if not isLast:
        suggestionsRec(pCrawl, query)
        return 1 # Suggestions found
    return 0 # No suggestions found

# Main method to run the Trie operations
if __name__ == '__main__':
    n = int(input()) # Read the number of words to insert
    for i in range(n):
        insert(root, input())
    prefix = input() # Read the prefix for suggestions
    comp = printAutoSuggestions(root, prefix) # Get suggestions based on the prefix
    # Handle the output based on the suggestions found
    if comp == -1:
        print("No other strings found with this prefix\n")
    elif comp == 0:
        print("No string found with this prefix\n")

