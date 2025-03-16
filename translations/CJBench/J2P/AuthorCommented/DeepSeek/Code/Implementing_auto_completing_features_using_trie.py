class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.isWordEnd = False

def getNode():
    return TrieNode()

def insert(root, key):
    pCrawl = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if pCrawl.children[index] is None:
            pCrawl.children[index] = getNode()
        pCrawl = pCrawl.children[index]
    pCrawl.isWordEnd = True

def search(root, key):
    pCrawl = root
    for level in range(len(key)):
        index = ord(key[level]) - ord('a')
        if pCrawl.children[index] is None:
            return False
        pCrawl = pCrawl.children[index]
    return pCrawl is not None and pCrawl.isWordEnd

def isLastNode(root):
    for i in range(26):
        if root.children[i] is not None:
            return False
    return True

def suggestionsRec(root, currPrefix):
    if root.isWordEnd:
        print(currPrefix)
    if isLastNode(root):
        return
    for i in range(26):
        if root.children[i] is not None:
            suggestionsRec(root.children[i], currPrefix + chr(97 + i))

def printAutoSuggestions(root, query):
    pCrawl = root
    for level in range(len(query)):
        index = ord(query[level]) - ord('a')
        if pCrawl.children[index] is None:
            return 0
        pCrawl = pCrawl.children[index]
    isWord = pCrawl.isWordEnd
    isLast = isLastNode(pCrawl)
    if isWord and isLast:
        print(query)
        return -1
    if not isLast:
        suggestionsRec(pCrawl, query)
        return 1
    return 0

# Driver code
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    root = getNode()

    for i in range(1, n + 1):
        insert(root, data[i])

    prefix = data[n + 1]

    comp = printAutoSuggestions(root, prefix)

    if comp == -1:
        print("No other strings found with this prefix\n")
    elif comp == 0:
        print("No string found with this prefix\n")

