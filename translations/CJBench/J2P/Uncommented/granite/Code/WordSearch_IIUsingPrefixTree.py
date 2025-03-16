
import sys
sys.setrecursionlimit(10**6)
class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_word = True

def find_words(board, words):
    m, n = len(board), len(board[0])
    visited = [[False] * n for _ in range(m)]
    trie = Trie()
    for word in words:
        trie.insert(word)
    result = set()
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def dfs(i, j, node):
        if i < 0 or i >= m or j < 0 or j >= n or visited[i][j] or board[i][j] not in node.children:
            return
        visited[i][j] = True
        child = node.children[board[i][j]]
        if child.is_word:
            result.add(board[i][j])
        for di, dj in directions:
            dfs(i + di, j + dj, child)
        visited[i][j] = False

    for i in range(m):
        for j in range(n):
            dfs(i, j, trie.root)

    return result

if __name__ == "__main__":
    rows, cols = map(int, input().split())
    board = [list(input()) for _ in range(rows)]
    word_count = int(input())
    words = [input() for _ in range(word_count)]
    result = find_words(board, words)
    for word in result:
        print(word)
