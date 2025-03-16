class WordSearch:
    def __init__(self):
        # Directions for moving in the board
        self.dx = [0, 0, 1, -1]
        self.dy = [1, -1, 0, 0]
        self.visited = []
        self.board = []
        self.word = ""

    # Helper method to check if given coordinates are valid
    def is_valid(self, x, y):
        return 0 <= x < len(self.board) and 0 <= y < len(self.board[0])

    # Depth-First Search (DFS) helper method to find a word in the board
    def do_dfs(self, x, y, next_idx):
        # Mark the current cell as visited
        self.visited[x][y] = True

        # Base case: if we have visited all characters in the word
        if next_idx == len(self.word):
            return True

        # Iterate through all possible directions
        for i in range(4):
            xi = x + self.dx[i]
            yi = y + self.dy[i]

            # Check if the new coordinates are valid and the character matches the word
            if self.is_valid(xi, yi) and self.board[xi][yi] == self.word[next_idx] and not self.visited[xi][yi]:
                # Recursive call to search for the next character in the word
                exists = self.do_dfs(xi, yi, next_idx + 1)

                # If the recursive call returns true, we have found the word
                if exists:
                    return True

        # Backtrack: mark the current cell as unvisited
        self.visited[x][y] = False

        # Return false if we haven't found the word
        return False

    # Main method to check if the given word exists in the board
    def exist(self, board, word):
        # Initialize the board and word variables
        self.board = board
        self.word = word
        self.visited = [[False] * len(board[0]) for _ in range(len(board))]

        # Iterate through all cells in the board
        for i in range(len(board)):
            for j in range(len(board[0])):
                # If we find the first character of the word, start the DFS search
                if board[i][j] == word[0]:
                    exists = self.do_dfs(i, j, 1)

                    # If the DFS search returns true, we have found the word
                    if exists:
                        return True

        # If we haven't found the word, return false
        return False


# Main method to run the program
if __name__ == "__main__":
    import sys

    # Read the dimensions of the board and initialize it
    rows, cols = map(int, sys.stdin.readline().split())
    board = [list(sys.stdin.readline().strip()) for _ in range(rows)]

    # Read the word to search for
    word = sys.stdin.readline().strip()

    # Create an instance of the WordSearch class and call the exist method
    word_search = WordSearch()
    result = word_search.exist(board, word)

    # Print the result
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")

# <END-OF-CODE>
