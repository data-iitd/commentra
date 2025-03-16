
import sys

class Trie:
    def __init__(self):
        self.value = None
        self.isKey = False
        self.children = {}

    def hasChild(self, ch):
        return ch in self.children

    def addChild(self, ch):
        self.children[ch] = Trie()

    def getChild(self, ch):
        return self.children[ch]

    def insert(self, word):
        node = self
        for ch in word:
            if not node.hasChild(ch):
                node.addChild(ch)
            node = node.getChild(ch)
        node.value = word
        node.isKey = True

class Main:
    def findWords(self, board, words):
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
                self.traverse(board, i, j, trie, visited, result)

        # Convert the set to a list and return it as the result
        return list(result)

    def traverse(self, board, i, j, trie, visited, result):
        # Get the character at the current cell
        ch = board[i][j]

        # If the trie has a child with the current character, then it might be the start of a valid word
        if trie.hasChild(ch):
            child = trie.getChild(ch)

            # If the current word is a valid word, add it to the result
            if child.isKey:
                result.add(child.value)

            # Traverse to the neighboring cells and check if they can form a valid word
            self.checkNewPos(board, i - 1, j, child, visited, result)
            self.checkNewPos(board, i, j - 1, child, visited, result)
            self.checkNewPos(board, i + 1, j, child, visited, result)
            self.checkNewPos(board, i, j + 1, child, visited, result)

    def checkNewPos(self, board, i, j, trie, visited, result):
        # Get the dimensions of the board
        m = len(board)
        n = len(board[0])

        # Check if the given position is valid and has not been visited before
        if i >= 0 and j >= 0 and i < m and j < n and not visited[i][j]:
            visited[i][j] = True

            # Traverse to the neighboring cell and check if it can form a valid word
            self.traverse(board, i, j, trie, visited, result)

            visited[i][j] = False

if __name__ == '__main__':
    # Read the dimensions of the board and the number of words
    rows, cols = map(int, input().split())
    input()

    # Read the characters of the board
    board = []
    for _ in range(rows):
        board.append(input().strip())

    # Read the number of words and their characters
    wordCount = int(input())
    input()

    # Read the words and store them in an array
    words = []
    for _ in range(wordCount):
        words.append(input().strip())

    # Create an instance of the Main class and call the findWords method
    wordSearch = Main()
    result = wordSearch.findWords(board, words)

    # Print the result
    for word in result:
        print(word)

