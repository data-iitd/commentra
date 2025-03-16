
class Trie:
    # Trie node
    def __init__(self):
        self.value = None
        self.isKey = False
        self.children = {}

    # Check if the trie has a child with the given character
    def hasChild(self, ch):
        return ch in self.children

    # Add a new child to the trie with the given character
    def addChild(self, ch):
        self.children[ch] = Trie()

    # Get the child of the trie with the given character
    def getChild(self, ch):
        return self.children[ch]

    # Insert a new word into the trie
    def insert(self, word):
        node = self
        for ch in word:
            if not node.hasChild(ch):
                node.addChild(ch)
            node = node.getChild(ch)
        node.value = word
        node.isKey = True

# Find all the words in the given board that are present in the list of words
def findWords(board, words):
    # Create a set of unique words from the given list of words
    uniqueWords = set(words)

    # Initialize the trie data structure
    trie = Trie()

    # Insert all the unique words into the trie
    for word in uniqueWords:
        trie.insert(word)

    # Initialize an empty set to store the result
    result = set()

    # Get the dimensions of the board
    m = len(board)
    n = len(board[0])

    # Iterate through each character in the board
    for i in range(m):
        for j in range(n):
            # Initialize a 2D boolean array to keep track of the visited cells
            visited = [[False] * n for _ in range(m)]

            # Set the current cell as visited and start the traversal
            visited[i][j] = True
            traverse(board, i, j, trie, visited, result)

    # Convert the set to a list and return it as the result
    return list(result)

# A recursive method to traverse the board and find all the words that can be formed from the current cell and its neighbors
def traverse(board, i, j, trie, visited, result):
    # Get the character at the current cell
    ch = board[i][j]

    # If the trie has a child with the current character, then it might be the start of a valid word
    if trie.hasChild(ch):
        child = trie.getChild(ch)

        # If the current word is a valid word, add it to the result
        if child.isKey:
            result.add(child.value)

        # Traverse to the neighboring cells and check if they can form a valid word
        checkNewPos(board, i - 1, j, child, visited, result)
        checkNewPos(board, i, j - 1, child, visited, result)
        checkNewPos(board, i + 1, j, child, visited, result)
        checkNewPos(board, i, j + 1, child, visited, result)

# A helper method to check if the given position is within the bounds of the board and has not been visited before
def checkNewPos(board, i, j, trie, visited, result):
    # Get the dimensions of the board
    m = len(board)
    n = len(board[0])

    # Check if the given position is valid and has not been visited before
    if 0 <= i < m and 0 <= j < n and not visited[i][j]:
        visited[i][j] = True

        # Traverse to the neighboring cell and check if it can form a valid word
        traverse(board, i, j, trie, visited, result)

        visited[i][j] = False

# Main method to read the input and call the findWords method
def main():
    # Read the dimensions of the board and the number of words
    rows, cols = map(int, input().split())
    board = [input() for _ in range(rows)]
    wordCount = int(input())
    words = [input() for _ in range(wordCount)]

    # Create an instance of the Main class and call the findWords method
    result = findWords(board, words)

    # Print the result
    for word in result:
        print(word)

# Main method to read the input and call the findWords method
if __name__ == "__main__":
    main()

