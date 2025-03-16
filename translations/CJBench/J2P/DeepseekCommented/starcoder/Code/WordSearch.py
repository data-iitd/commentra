import sys

# Direction vectors for moving in four possible directions (right, left, down, up)
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

# 2D array to keep track of visited cells during the DFS
visited = None

# 2D char array representing the board
board = None

# String representing the word to be searched
word = None

# Method to check if a cell (x, y) is within the bounds of the board
def isValid(x, y):
    return x >= 0 and x < len(board) and y >= 0 and y < len(board[0])

# Depth-First Search (DFS) method to find the word in the board
def doDFS(x, y, nextIdx):
    # Mark the current cell as visited
    visited[x][y] = True
    
    # If we have reached the end of the word, return true
    if nextIdx == len(word):
        return True
    
    # Explore all four possible directions
    for i in range(4):
        xi = x + dx[i]
        yi = y + dy[i]
        
        # Check if the new cell is within bounds, matches the next character of the word, and hasn't been visited
        if isValid(xi, yi) and board[xi][yi] == word[nextIdx] and not visited[xi][yi]:
            # Recursively call doDFS for the new cell
            exists = doDFS(xi, yi, nextIdx + 1)
            if exists:
                return True
    
    # Backtrack: unmark the current cell as visited
    visited[x][y] = False 
    
    # Return false if the word cannot be formed from the current path
    return False

# Method to check if the word exists in the board
def exist(board, word):
    global visited, board, word
    
    # Iterate over each cell in the board to start a DFS search
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == word[0]:
                # Initialize the visited array for each DFS search
                visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
                
                # Start DFS from the current cell
                exists = doDFS(i, j, 1)
                if exists:
                    return True
    
    # Return false if the word does not exist in the board
    return False

# Main method to read input, create an instance of Main, and print the result
def main():
    # Read the dimensions of the board
    rows = int(sys.stdin.readline().strip())
    cols = int(sys.stdin.readline().strip())
    
    # Initialize the board with the given dimensions
    board = [[0 for _ in range(cols)] for _ in range(rows)]
    for i in range(rows):
        row = sys.stdin.readline().strip()
        for j in range(cols):
            board[i][j] = row[j]
    
    # Read the word to be searched
    word = sys.stdin.readline().strip()
    
    # Create an instance of Main and check if the word exists in the board
    wordSearch = Main()
    result = wordSearch.exist(board, word)
    
    # Print the result
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")

if __name__ == "__main__":
    main()

