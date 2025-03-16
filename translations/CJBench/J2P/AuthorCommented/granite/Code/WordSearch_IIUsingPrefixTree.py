
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
    # Deduplicate input words
    unique_words = set(words)

    # Build prefix tree (Trie)
    trie = Trie()
    for word in unique_words:
        trie.insert(word)

    # Use a prefix tree to determine result
    result = set()
    m, n = len(board), len(board[0])
    for i in range(m):
        for j in range(n):
            visited = [[False] * n for _ in range(m)]
            dfs(board, i, j, trie.root, visited, result)

    # Convert Set to List and return
    return list(result)

def dfs(board, i, j, node, visited, result):
    ch = board[i][j]
    if ch in node.children:
        child = node.children[ch]
        if child.is_word:
            result.add(ch)

        if i > 0 and not visited[i - 1][j]:
            visited[i - 1][j] = True
            dfs(board, i - 1, j, child, visited, result)
        if j > 0 and not visited[i][j - 1]:
            visited[i][j - 1] = True
            dfs(board, i, j - 1, child, visited, result)
        if i < len(board) - 1 and not visited[i + 1][j]:
            visited[i + 1][j] = True
            dfs(board, i + 1, j, child, visited, result)
        if j < len(board[0]) - 1 and not visited[i][j + 1]:
            visited[i][j + 1] = True
            dfs(board, i, j + 1, child, visited, result)

if __name__ == "__main__":
    import sys

    # Input the board dimensions
    rows, cols = map(int, input().split())

    # Input the board
    board = [list(input()) for _ in range(rows)]

    # Input the number of words
    word_count = int(input())

    # Input the words
    words = [input() for _ in range(word_count)]

    result = find_words(board, words)

    # Print the result
    print("\n".join(result))

