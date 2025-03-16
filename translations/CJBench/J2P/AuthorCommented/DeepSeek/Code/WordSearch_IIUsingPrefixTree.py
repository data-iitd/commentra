class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False
        self.word = None

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True
        node.word = word

    def search(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                return False
            node = node.children[char]
        return node.is_end_of_word

    def starts_with(self, prefix):
        node = self.root
        for char in prefix:
            if char not in node.children:
                return False
            node = node.children[char]
        return True

def find_words(board, words):
    trie = Trie()
    for word in words:
        trie.insert(word)

    m, n = len(board), len(board[0])
    result = set()

    def dfs(i, j, node):
        if node.is_end_of_word:
            result.add(node.word)

        if i < 0 or i >= m or j < 0 or j >= n:
            return

        temp = board[i][j]
        if temp not in node.children:
            return

        board[i][j] = '#'
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            dfs(i + dx, j + dy, node.children[temp])
        board[i][j] = temp

    for i in range(m):
        for j in range(n):
            dfs(i, j, trie.root)

    return list(result)

# Main function to take input and print output
def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    rows = int(data[0])
    cols = int(data[1])
    board = []
    word_index = 2
    for i in range(rows):
        board.append(list(data[word_index]))
        word_index += 1

    word_count = int(data[word_index])
    words = data[word_index + 1:]

    result = find_words(board, words)
    for word in result:
        print(word)

if __name__ == "__main__":
    main()
