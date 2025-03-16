
import collections

class Trie:
    def __init__(self):
        self.value = None
        self.is_key = False
        self.children = collections.defaultdict(Trie)

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

def find_words(board, words):
    # Deduplicate input words
    unique_words = set(words)

    # Build prefix tree (Trie)
    trie = Trie()
    for word in unique_words:
        trie.insert(word)

    # Use a prefix tree to determine result
    result = set()
    m = len(board)
    n = len(board[0])
    for i in range(m):
        for j in range(n):
            visited = [[False] * n for _ in range(m)]
            visited[i][j] = True

            traverse(board, i, j, trie, visited, result)

    # Convert Set to List and return
    return list(result)

def traverse(board, i, j, trie, visited, result):
    ch = board[i][j]
    if trie.has_child(ch):
        child = trie.get_child(ch)
        if child.is_key:
            result.add(child.value)

        check_new_pos(board, i - 1, j, child, visited, result)
        check_new_pos(board, i, j - 1, child, visited, result)
        check_new_pos(board, i + 1, j, child, visited, result)
        check_new_pos(board, i, j + 1, child, visited, result)

def check_new_pos(board, i, j, trie, visited, result):
    m = len(board)
    n = len(board[0])

    if i < 0 or j < 0 or i >= m or j >= n:
        return

    if not visited[i][j]:
        visited[i][j] = True
        traverse(board, i, j, trie, visited, result)
        visited[i][j] = False

def main():
    # Input the board dimensions
    rows = int(input())
    cols = int(input())

    # Input the board
    board = []
    for _ in range(rows):
        board.append(input())

    # Input the number of words
    word_count = int(input())

    # Input the words
    words = []
    for _ in range(word_count):
        words.append(input())

    result = find_words(board, words)

    # Print the result
    print('\n'.join(result))

if __name__ == '__main__':
    main()

