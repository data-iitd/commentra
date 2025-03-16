class Trie:
    def __init__(self):
        self.value = None  # The word stored at this node
        self.is_key = False  # Indicates if this node represents the end of a valid word
        self.children = {}  # Children nodes

    def has_child(self, ch):
        return ch in self.children

    def add_child(self, ch):
        self.children[ch] = Trie()

    def get_child(self, ch):
        return self.children[ch]

    def insert(self, word):
        node = self  # Start from the root node
        for ch in word:  # Iterate through each character of the word
            if not node.has_child(ch):  # If the character is not already a child
                node.add_child(ch)  # Add it as a child
            node = node.get_child(ch)  # Move to the child node
        node.value = word  # Set the value of the node to the word
        node.is_key = True  # Mark this node as a key (end of a valid word)


class Main:
    def find_words(self, board, words):
        unique_words = set(words)  # Create a set of unique words to avoid duplicates
        trie = Trie()  # Create a new Trie
        for word in unique_words:
            trie.insert(word)  # Insert all unique words into the Trie

        result = set()  # Set to store found words
        m, n = len(board), len(board[0])  # Number of rows and columns in the board

        # Traverse each cell in the board
        for i in range(m):
            for j in range(n):
                visited = [[False] * n for _ in range(m)]  # Track visited cells
                visited[i][j] = True  # Mark the starting cell as visited
                self.traverse(board, i, j, trie, visited, result)  # Start the traversal

        return list(result)  # Return the found words as a list

    def traverse(self, board, i, j, trie, visited, result):
        ch = board[i][j]  # Get the character at the current position
        if trie.has_child(ch):  # Check if the Trie has a child for this character
            child = trie.get_child(ch)  # Get the child node
            if child.is_key:  # If this child node represents a valid word
                result.add(child.value)  # Add the word to the result set
            # Check all four possible directions (up, left, down, right)
            self.check_new_pos(board, i - 1, j, child, visited, result)  # Up
            self.check_new_pos(board, i, j - 1, child, visited, result)  # Left
            self.check_new_pos(board, i + 1, j, child, visited, result)  # Down
            self.check_new_pos(board, i, j + 1, child, visited, result)  # Right

    def check_new_pos(self, board, i, j, trie, visited, result):
        m, n = len(board), len(board[0])  # Number of rows and columns in the board
        # Check if the new position is out of bounds
        if i < 0 or j < 0 or i >= m or j >= n:
            return  # Exit if out of bounds
        # If the position is not visited, mark it as visited and continue traversal
        if not visited[i][j]:
            visited[i][j] = True  # Mark the cell as visited
            self.traverse(board, i, j, trie, visited, result)  # Continue traversal
            visited[i][j] = False  # Unmark the cell after traversal

# Main method to run the word search
if __name__ == "__main__":
    import sys

    input = sys.stdin.read
    data = input().splitlines()
    
    rows, cols = map(int, data[0].split())  # Read number of rows and columns
    board = [list(data[i + 1]) for i in range(rows)]  # Initialize the board

    word_count = int(data[rows + 1])  # Read the number of words
    words = [data[rows + 2 + i] for i in range(word_count)]  # Read the words input

    word_search = Main()  # Create an instance of Main
    result = word_search.find_words(board, words)  # Find words on the board
    for word in result:  # Print each found word
        print(word)

# <END-OF-CODE>
