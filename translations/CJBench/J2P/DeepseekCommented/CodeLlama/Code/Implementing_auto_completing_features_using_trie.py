
import sys

class Trieac:
    ALPHABET_SIZE = 26

    class TrieNode:
        def __init__(self):
            self.children = [None] * Trieac.ALPHABET_SIZE
            self.isWordEnd = False

    @staticmethod
    def getNode():
        pNode = Trieac.TrieNode()
        pNode.isWordEnd = False
        for i in range(Trieac.ALPHABET_SIZE):
            pNode.children[i] = None
        return pNode

    @staticmethod
    def insert(root, key):
        pCrawl = root
        for level in range(len(key)):
            index = ord(key[level]) - ord('a')
            if pCrawl.children[index] is None:
                pCrawl.children[index] = Trieac.getNode()
            pCrawl = pCrawl.children[index]
        pCrawl.isWordEnd = True

    @staticmethod
    def search(root, key):
        length = len(key)
        pCrawl = root
        for level in range(length):
            index = ord(key[level]) - ord('a')
            if pCrawl.children[index] is None:
                return False
            pCrawl = pCrawl.children[index]
        return pCrawl.isWordEnd

    @staticmethod
    def isLastNode(root):
        for i in range(Trieac.ALPHABET_SIZE):
            if root.children[i] is not None:
                return False
        return True

    @staticmethod
    def suggestionsRec(root, currPrefix):
        if root.isWordEnd:
            print(currPrefix)
        if Trieac.isLastNode(root):
            return
        for i in range(Trieac.ALPHABET_SIZE):
            if root.children[i] is not None:
                Trieac.suggestionsRec(root.children[i], currPrefix + chr(97 + i))

    @staticmethod
    def printAutoSuggestions(root, query):
        pCrawl = root
        n = len(query)
        for level in range(n):
            index = ord(query[level]) - ord('a')
            if pCrawl.children[index] is None:
                return 0
            pCrawl = pCrawl.children[index]
        isWord = pCrawl.isWordEnd
        isLast = Trieac.isLastNode(pCrawl)
        if isWord and isLast:
            print(query)
            return -1
        if not isLast:
            Trieac.suggestionsRec(pCrawl, query)
            return 1
        return 0

    @staticmethod
    def main():
        sc = sys.stdin
        n = int(sc.readline())
        sc.readline()
        root = Trieac.getNode()
        for i in range(n):
            Trieac.insert(root, sc.readline().strip())
        prefix = sc.readline().strip()
        comp = Trieac.printAutoSuggestions(root, prefix)
        if comp == -1:
            print("No other strings found with this prefix\n")
        elif comp == 0:
            print("No string found with this prefix\n")
        sc.close()

if __name__ == "__main__":
    Trieac.main()

