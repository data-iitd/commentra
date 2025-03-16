class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False
        self.word = None

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
        node.word = word

class Solution:
    def findWords(self, board, words):
        trie = Trie()
        for word in words:
            trie.insert(word)
        
        m, n = len(board), len(board[0])
        result = set()
        visited = [[False] * n for _ in range(m)]

        def dfs(i, j, node):
            if i < 0 or j < 0 or i >= m or j >= n or visited[i][j]:
                return
            ch = board[i][j]
            if ch not in node.children:
                return
            visited[i][j] = True
            node = node.children[ch]
            if node.is_word:
                result.add(node.word)
            dfs(i + 1, j, node)
            dfs(i - 1, j, node)
            dfs(i, j + 1, node)
            dfs(i, j - 1, node)
            visited[i][j] = False

        for i in range(m):
            for j in range(n):
                dfs(i, j, trie.root)

        return list(result)

# Example usage:
# board = [
#     ['o', 'a', 'a', 'n'],
#     ['e', 't', 'a', 'e'],
#     ['i', 'h', 'k', 'r'],
#     ['i', 'f', 'l', 'v']
# ]
# words = ["oath", "pea", "eat", "rain"]
# solution = Solution()
# print(solution.findWords(board, words))  # Output: ["eat", "oath"]
