class TrieNode:
    def __init__(self):
        self.children = {}
        self.value = None
        self.is_key = False

    def has_child(self, ch):
        return ch in self.children

    def add_child(self, ch):
        self.children[ch] = TrieNode()

    def get_child(self, ch):
        return self.children.get(ch)

    def insert(self, word):
        node = self
        for ch in word:
            if not node.has_child(ch):
                node.add_child(ch)
            node = node.get_child(ch)
        node.value = word
        node.is_key = True


class Solution:
    def find_words(self, board, words):
        unique_words = set(words)
        trie = TrieNode()
        for word in unique_words:
            trie.insert(word)

        result = set()
        m, n = len(board), len(board[0])

        def traverse(i, j, node, visited):
            ch = board[i][j]
            if node.has_child(ch):
                child = node.get_child(ch)
                if child.is_key:
                    result.add(child.value)
                check_new_pos(i - 1, j, child, visited)
                check_new_pos(i, j - 1, child, visited)
                check_new_pos(i + 1, j, child, visited)
                check_new_pos(i, j + 1, child, visited)

        def check_new_pos(i, j, node, visited):
            if i < 0 or j < 0 or i >= m or j >= n:
                return
            if (i, j) not in visited:
                visited.add((i, j))
                traverse(i, j, node, visited)
                visited.remove((i, j))

        for i in range(m):
            for j in range(n):
                visited = set()
                visited.add((i, j))
                traverse(i, j, trie, visited)

        return list(result)


# Main function to run the word search
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

    solution = Solution()
    result = solution.find_words(board, words)
    for word in result:
        print(word)


if __name__ == "__main__":
    main()
