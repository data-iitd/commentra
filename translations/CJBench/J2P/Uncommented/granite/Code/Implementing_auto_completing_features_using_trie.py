

import sys
class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isWordEnd = False
def getNode():
    pNode = TrieNode()
    pNode.isWordEnd = False
    for i in range(26):
        pNode.children[i] = None
    return pNode
def insert(root, key):
    pCrawl = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if pCrawl.children[index] == None:
            pCrawl.children[index] = getNode()
        pCrawl = pCrawl.children[index]
    pCrawl.isWordEnd = True
def search(root, key):
    length = len(key)
    pCrawl = root
    for level in range(length):
        index = ord(key[level]) - ord('a')
        if pCrawl.children[index] == None:
            return False
        pCrawl = pCrawl.children[index]
    return (pCrawl!= None and pCrawl.isWordEnd)
def isLastNode(root):
    for i in range(26):
        if root.children[i]!= None:
            return False
    return True
def suggestionsRec(root, currPrefix):
    if root.isWordEnd:
        print(currPrefix)
    if isLastNode(root):
        return
    for i in range(26):
        if root.children[i]!= None:
            suggestionsRec(root.children[i], currPrefix + chr(i + ord('a')))
def printAutoSuggestions(root, query):
    pCrawl = root
    n = len(query)
    for level in range(n):
        index = ord(query[level]) - ord('a')
        if pCrawl.children[index] == None:
            return 0
        pCrawl = pCrawl.children[index]
    isWord = (pCrawl.isWordEnd)
    isLast = isLastNode(pCrawl)
    if isWord and isLast:
        print(query)
        return -1
    if not isLast:
        suggestionsRec(pCrawl, query)
        return 1
    return 0
if __name__ == '__main__':
    n = int(input())
    root = getNode()
    for i in range(n):
        insert(root, input())
    prefix = input()
    comp = printAutoSuggestions(root, prefix)
    if comp == -1:
        print("No other strings found with this prefix\n")
    elif comp == 0:
        print("No string found with this prefix\n")
