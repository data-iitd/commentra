class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_key = False
        self.value = None

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def has_child(self, ch):
        return ch in self.root.children

    def add_child(self, ch):
        self.root.children[ch] = TrieNode()

    def get_child(self, ch):
        return self.root.children.get(ch)

    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_key = True
        node.value = word

def find_words(board, words):
    unique_words = set(words)
    trie = Trie()
    for word in unique_words:
        trie.insert(word)
    result = set()
    m, n = len(board), len(board[0])

    def traverse(i, j, trie_node, visited):
        ch = board[i][j]
        if ch in trie_node.children:
            child_node = trie_node.children[ch]
            if child_node.is_key:
                result.add(child_node.value)
            check_new_pos(i - 1, j, child_node, visited)
            check_new_pos(i, j - 1, child_node, visited)
            check_new_pos(i + 1, j, child_node, visited)
            check_new_pos(i, j + 1, child_node, visited)

    def check_new_pos(i, j, trie_node, visited):
        if i < 0 or j < 0 or i >= m or j >= n:
            return
        if (i, j) not in visited:
            visited.add((i, j))
            traverse(i, j, trie_node, visited)
            visited.remove((i, j))

    visited = set()
    for i in range(m):
        for j in range(n):
            traverse(i, j, trie.root, visited.copy())
    return list(result)

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
    word_index += 1
    words = data[word_index:word_index + word_count]
    result = find_words(board, words)
    for word in result:
        print(word)

if __name__ == "__main__":
    main()
