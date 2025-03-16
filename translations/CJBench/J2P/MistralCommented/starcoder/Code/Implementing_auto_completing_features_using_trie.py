
import sys

# Class to represent a node in Trie
class TrieNode:
    ALPHABET_SIZE = 26
    def __init__(self):
        self.children = [None] * TrieNode.ALPHABET_SIZE
        self.isWordEnd = False

# Function to get a new TrieNode
def getNode():
    return TrieNode()

# Function to insert a word into Trie
def insert(root, key):
    currentNode = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if not currentNode.children[index]:
            currentNode.children[index] = getNode()
        currentNode = currentNode.children[index]
    currentNode.isWordEnd = True

# Function to search a word in Trie
def search(root, key):
    currentNode = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if not currentNode.children[index]:
            return False
        currentNode = currentNode.children[index]
    return currentNode!= None and currentNode.isWordEnd

# Function to check if the current node is the last node
def isLastNode(root):
    for i in range(TrieNode.ALPHABET_SIZE):
        if root.children[i]:
            return False
    return True

# Function to print suggestions based on the given prefix
def suggestionsRec(root, currPrefix):
    if root.isWordEnd:
        print(currPrefix)
    if isLastNode(root):
        return
    for i in range(TrieNode.ALPHABET_SIZE):
        if root.children[i]:
            suggestionsRec(root.children[i], currPrefix + chr(ord('a') + i))

# Function to print auto-suggestions based on the given prefix
def printAutoSuggestions(root, query):
    currentNode = root
    level = 0
    n = len(query)
    for level in range(n):
        index = ord(query[level]) - ord('a')
        if not currentNode.children[index]:
            return 0
        currentNode = currentNode.children[index]
    isWord = currentNode.isWordEnd
    isLast = isLastNode(currentNode)
    if isWord and isLast:
        print(query)
        return -1
    if not isLast:
        suggestionsRec(currentNode, query)
        return 1
    return 0

# Main function
if __name__ == '__main__':
    n = int(input())
    for i in range(n):
        word = input()
        insert(root, word)
    prefix = input()
    suggestionsCount = printAutoSuggestions(root, prefix)
    if suggestionsCount == -1:
        print("No other strings found with this prefix\n")
    elif suggestionsCount == 0:
        print("No string found with this prefix\n")

