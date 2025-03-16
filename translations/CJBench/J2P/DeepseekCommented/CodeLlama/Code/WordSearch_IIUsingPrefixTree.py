import sys
import collections

class Trie:
    def __init__(self):
        self.value = None
        self.isKey = False
        self.children = collections.defaultdict(Trie)

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

def findWords(board, words):
    uniqueWords = set(words)
    trie = Trie()
    for word in uniqueWords:
        trie.insert(word)
    result = set()
    m = len(board)
    n = len(board[0])

    for i in range(m):
        for j in range(n):
            visited = [[False] * n for _ in range(m)]
            visited[i][j] = True
            traverse(board, i, j, trie, visited, result)

    return list(result)

def traverse(board, i, j, trie, visited, result):
    ch = board[i][j]
    if trie.hasChild(ch):
        child = trie.getChild(ch)
        if child.isKey:
            result.add(child.value)
        checkNewPos(board, i - 1, j, child, visited, result)
        checkNewPos(board, i, j - 1, child, visited, result)
        checkNewPos(board, i + 1, j, child, visited, result)
        checkNewPos(board, i, j + 1, child, visited, result)

def checkNewPos(board, i, j, trie, visited, result):
    m = len(board)
    n = len(board[0])
    if i < 0 or j < 0 or i >= m or j >= n:
        return
    if not visited[i][j]:
        visited[i][j] = True
        traverse(board, i, j, trie, visited, result)
        visited[i][j] = False

def main():
    rows = int(sys.stdin.readline())
    cols = int(sys.stdin.readline())
    board = [sys.stdin.readline().strip() for _ in range(rows)]
    wordCount = int(sys.stdin.readline())
    words = [sys.stdin.readline().strip() for _ in range(wordCount)]
    result = findWords(board, words)
    print('\n'.join(result))

if __name__ == '__main__':
    main()

