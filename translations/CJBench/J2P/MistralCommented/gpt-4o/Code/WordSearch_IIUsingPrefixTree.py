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


class Main:
    def find_words(self, board, words):
        unique_words = set(words)
        trie = Trie()

        for word in unique_words:
            trie.insert(word)

        result = set()
        m, n = len(board), len(board[0])

        for i in range(m):
            for j in range(n):
                visited = [[False] * n for _ in range(m)]
                visited[i][j] = True
                self.traverse(board, i, j, trie, visited, result)

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

        if 0 <= i < m and 0 <= j < n and not visited[i][j]:
            visited[i][j] = True
            self.traverse(board, i, j, trie, visited, result)
            visited[i][j] = False

if __name__ == "__main__":
    import sys

    input = sys.stdin.read
    data = input().splitlines()

    rows, cols = map(int, data[0].split())
    board = [list(data[i + 1]) for i in range(rows)]
    word_count = int(data[rows + 1])
    words = [data[rows + 2 + i] for i in range(word_count)]

    word_search = Main()
    result = word_search.find_words(board, words)

    for word in result:
        print(word)

# <END-OF-CODE>
