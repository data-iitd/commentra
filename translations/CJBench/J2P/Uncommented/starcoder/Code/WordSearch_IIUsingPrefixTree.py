import collections
class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_key = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for ch in word:
            node = node.children[ch]
        node.is_key = True

class Solution:
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        trie = Trie()
        for word in words:
            trie.insert(word)
        result = set()
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                self.dfs(board, i, j, trie.root, result)
        return list(result)

    def dfs(self, board, i, j, node, result):
        if node.is_key:
            result.add(node.word)
            node.is_key = False
        if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]):
            return
        if board[i][j] not in node.children:
            return
        board[i][j] = '#'
        self.dfs(board, i - 1, j, node.children[board[i][j]], result)
        self.dfs(board, i, j - 1, node.children[board[i][j]], result)
        self.dfs(board, i + 1, j, node.children[board[i][j]], result)
        self.dfs(board, i, j + 1, node.children[board[i][j]], result)
        board[i][j] = node.word[0]

if __name__ == '__main__':
    board = [
        ['o', 'a', 'a', 'n'],
        ['e', 't', 'a', 'e'],
        ['i', 'h', 'k', 'r'],
        ['i', 'f', 'l', 'v']
    ]
    words = ["oath", "pea", "eat", "rain"]
    solution = Solution()
    result = solution.findWords(board, words)
    print(result)

