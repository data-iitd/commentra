
import sys

# Direction vectors for moving up, down, left, and right
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

# 2D array to track visited cells
visited = []

# 2D character array representing the board
board = []

# The word we are searching for
word = ""

# Method to check if the given coordinates are within the bounds of the board
def isValid(x, y):
    return x >= 0 and x < len(board) and y >= 0 and y < len(board[0])

# Depth-First Search (DFS) method to explore the board for the word
def doDFS(x, y, nextIdx):
    # Mark the current cell as visited
    visited[x][y] = True

    # Check if we have found the entire word
    if nextIdx == len(word):
        return True

    # Explore all four possible directions
    for i in range(4):
        xi = x + dx[i] # New x coordinate
        yi = y + dy[i] # New y coordinate
        
        # Check if the next cell is valid, matches the next character in the word, and is not visited
        if isValid(xi, yi) and board[xi][yi] == word[nextIdx] and not visited[xi][yi]:
            # Recursively call doDFS for the next character in the word
            exists = doDFS(xi, yi, nextIdx + 1)
            if exists:
                return True # If the word exists, return true
    # Unmark the current cell as visited (backtrack)
    visited[x][y] = False 
    return False # Return false if the word is not found

# Main method to check if the word exists in the board
def exist(board, word):
    global visited
    global word
    
    # Initialize the board
    visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
    self.board = board
    self.word = word
    
    # Iterate through each cell in the board
    for i in range(len(board)):
        for j in range(len(board[0])):
            # If the current cell matches the first character of the word
            if board[i][j] == word[0]:
                # Start DFS from the current cell for the next character
                exists = doDFS(i, j, 1)
                if exists:
                    return True # If the word exists, return true
    return False # Return false if the word is not found in the board

# Main entry point of the program
if __name__ == "__main__":
    # Read the dimensions of the board
    rows = int(sys.stdin.readline())
    cols = int(sys.stdin.readline())
    
    # Initialize the board
    board = [sys.stdin.readline().strip() for _ in range(rows)]
    
    # Read the word to search for
    word = sys.stdin.readline().strip()
    
    # Create an instance of Main to use the exist method
    wordSearch = Main()
    
    # Check if the word exists in the board
    result = wordSearch.exist(board, word)
    
    # Output the result
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")

