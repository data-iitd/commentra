class Trie:
    def __init__(self):
        self.value = None
        self.is_key = False
        self.children = {}

    def has_child(self, ch):
        return ch in self.children

    def add_child(self, ch):
        self.children[ch] = Trie()

    def get_child(self, ch):
        return self.children[ch]

    def insert(self, word):
        node = self
        for ch in word:
            if not node.has_child(ch):
                node.add_child(ch)
            node = node.get_child(ch)
        node.value = word
        node.is_key = True


class WordSearch:
    def find_words(self, board, words):
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
                visited[i][j] = True
                self.traverse(board, i, j, trie, visited, result)

        # Convert Set to List and return
        return list(result)

    def traverse(self, board, i, j, trie, visited, result):
        ch = board[i][j]
        if trie.has_child(ch):
            child = trie.get_child(ch)
            if child.is_key:
                result.add(child.value)

            self.check_new_pos(board, i - 1, j, child, visited, result)
            self.check_new_pos(board, i, j - 1, child, visited, result)
            self.check_new_pos(board, i + 1, j, child, visited, result)
            self.check_new_pos(board, i, j + 1, child, visited, result)

    def check_new_pos(self, board, i, j, trie, visited, result):
        m, n = len(board), len(board[0])

        if i < 0 or j < 0 or i >= m or j >= n:
            return

        if not visited[i][j]:
            visited[i][j] = True
            self.traverse(board, i, j, trie, visited, result)
            visited[i][j] = False


if __name__ == "__main__":
    import sys

    input = sys.stdin.read
    data = input().splitlines()

    # Input the board dimensions
    rows, cols = map(int, data[0].split())
    
    # Input the board
    board = [list(data[i + 1]) for i in range(rows)]

    # Input the number of words
    word_count = int(data[rows + 1])

    # Input the words
    words = [data[rows + 2 + i] for i in range(word_count)]

    word_search = WordSearch()
    result = word_search.find_words(board, words)

    # Print the result
    for word in result:
        print(word)

# <END-OF-CODE>
