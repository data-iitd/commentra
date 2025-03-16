import sys

class Trie:
    def __init__(self):
        self.value = None
        self.isKey = False
        self.children = {}

    def hasChild(self, ch):
        return ch in self.children

    def addChild(self, ch):
        self.children[ch] = Trie()

    def getChild(self, ch):
        return self.children[ch]

    def insert(self, word):
        node = self
        for ch in word:
            if not node.hasChild(ch):
                node.addChild(ch)
            node = node.getChild(ch)
        node.value = word
        node.isKey = True

class Main:
    def findWords(self, board, words):
        # Deduplicate input words
        uniqueWords = set(words)

        # Build prefix tree (Trie)
        trie = Trie()
        for word in uniqueWords:
            trie.insert(word)

        # Use a prefix tree to determine result
        result = set()
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                visited = [[False] * n for _ in range(m)]
                visited[i][j] = True

                self.traverse(board, i, j, trie, visited, result)

        # Convert Set to List and return
        return list(result)

    def traverse(self, board, i, j, trie, visited, result):
        ch = board[i][j]
        if trie.hasChild(ch):
            child = trie.getChild(ch)
            if child.isKey:
                result.add(child.value)

            self.checkNewPos(board, i - 1, j, child, visited, result)
            self.checkNewPos(board, i, j - 1, child, visited, result)
            self.checkNewPos(board, i + 1, j, child, visited, result)
            self.checkNewPos(board, i, j + 1, child, visited, result)

    def checkNewPos(self, board, i, j, trie, visited, result):
        m = len(board)
        n = len(board[0])

        if i < 0 or j < 0 or i >= m or j >= n:
            return

        if not visited[i][j]:
            visited[i][j] = True
            self.traverse(board, i, j, trie, visited, result)
            visited[i][j] = False

if __name__ == '__main__':
    # Input the board dimensions
    rows = int(input())
    cols = int(input())
    input() # Consume the newline

    # Input the board
    board = []
    for i in range(rows):
        board.append(input().strip())

    # Input the number of words
    wordCount = int(input())
    input() # Consume the newline

    # Input the words
    words = []
    for i in range(wordCount):
        words.append(input().strip())

    wordSearch = Main()
    result = wordSearch.findWords(board, words)

    # Print the result
    for word in result:
        print(word)

