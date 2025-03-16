
import sys

# Declare 2D arrays for visited cells and the board
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
visited = None
board = None

# Declare a string variable for the given word
word = None

# Helper method to check if given coordinates are valid
def isValid(x, y):
    return x >= 0 and x < len(board) and y >= 0 and y < len(board[0])

# Depth-First Search (DFS) helper method to find a word in the board
def doDFS(x, y, nextIdx):
    # Mark the current cell as visited
    visited[x][y] = True
    
    # Base case: if we have visited all characters in the word
    if nextIdx == len(word):
        return True
    
    # Iterate through all possible directions
    for i in range(4):
        xi = x + dx[i]
        yi = y + dy[i]
        
        # Check if the new coordinates are valid and the character matches the word
        if isValid(xi, yi) and board[xi][yi] == word[nextIdx] and not visited[xi][yi]:
            # Recursive call to search for the next character in the word
            exists = doDFS(xi, yi, nextIdx + 1)
            
            # If the recursive call returns true, we have found the word
            if exists:
                return True
    
    # Backtrack: mark the current cell as unvisited
    visited[x][y] = False
    
    # Return false if we haven't found the word
    return False

# Main method to check if the given word exists in the board
def exist(board, word):
    # Initialize the board and word variables
    global visited, board, word
    visited = [[False for i in range(len(board[0]))] for j in range(len(board))]
    board = board
    word = word
    
    # Iterate through all cells in the board
    for i in range(len(board)):
        for j in range(len(board[0])):
            # If we find the first character of the word, start the DFS search
            if board[i][j] == word[0]:
                exists = doDFS(i, j, 1)
                
                # If the DFS search returns true, we have found the word
                if exists:
                    return True
    
    # If we haven't found the word, return false
    return False

# Main method to run the program
def main():
    # Read the dimensions of the board and initialize it
    rows = int(sys.stdin.readline().strip())
    cols = int(sys.stdin.readline().strip())
    board = [[0 for i in range(cols)] for j in range(rows)]
    for i in range(rows):
        row = sys.stdin.readline().strip()
        for j in range(cols):
            board[i][j] = row[j]
    
    # Read the word to search for
    word = sys.stdin.readline().strip()
    
    # Create an instance of the Main class and call the exist method
    wordSearch = Main()
    result = wordSearch.exist(board, word)
    
    # Print the result
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")

# Run the program
if __name__ == "__main__":
    main()

