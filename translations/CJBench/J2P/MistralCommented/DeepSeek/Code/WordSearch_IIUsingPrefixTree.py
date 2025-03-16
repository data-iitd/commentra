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
    # Create a set of unique words from the given list of words
    unique_words = set(words)

    # Initialize the trie data structure
    trie = Trie()

    # Insert all the unique words into the trie
    for word in unique_words:
        trie.insert(word)

    # Initialize an empty set to store the result
    result = set()

    # Get the dimensions of the board
    m, n = len(board), len(board[0])

    # Initialize a 2D boolean array to keep track of the visited cells
    visited = [[False] * n for _ in range(m)]

    # Iterate through each character in the board
    for i in range(m):
        for j in range(n):
            # Set the current cell as visited and start the traversal
            visited[i][j] = True
            traverse(board, i, j, trie.root, visited, result)
            visited[i][j] = False

    # Convert the set to a list and return it as the result
    return list(result)

def traverse(board, i, j, trie, visited, result):
    # Get the character at the current cell
    ch = board[i][j]

    # If the trie has a child with the current character, then it might be the start of a valid word
    if trie.has_child(ch):
        child = trie.get_child(ch)

        # If the current word is a valid word, add it to the result
        if child.is_key:
            result.add(child.value)

        # Traverse to the neighboring cells and check if they can form a valid word
        check_new_pos(board, i - 1, j, child, visited, result)
        check_new_pos(board, i, j - 1, child, visited, result)
        check_new_pos(board, i + 1, j, child, visited, result)
        check_new_pos(board, i, j + 1, child, visited, result)

def check_new_pos(board, i, j, trie, visited, result):
    # Get the dimensions of the board
    m, n = len(board), len(board[0])

    # Check if the given position is valid and has not been visited before
    if 0 <= i < m and 0 <= j < n and not visited[i][j]:
        visited[i][j] = True

        # Traverse to the neighboring cell and check if it can form a valid word
        traverse(board, i, j, trie, visited, result)

        visited[i][j] = False

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    # Read the dimensions of the board and the number of words
    rows = int(data[0])
    cols = int(data[1])
    index = 2

    # Read the characters of the board
    board = []
    for _ in range(rows):
        board.append(list(data[index]))
        index += 1

    # Read the number of words and their characters
    word_count = int(data[index])
    index += 1

    # Read the words and store them in an array
    words = []
    for _ in range(word_count):
        words.append(data[index])
        index += 1

    # Call the findWords method and print the result
    result = find_words(board, words)
    for word in result:
        print(word)
