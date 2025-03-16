import sys

class Main:
    # Direction vectors for moving up, down, left, and right
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    # 2D array to track visited cells
    visited = None
    
    # 2D character array representing the board
    board = None
    
    # The word we are searching for
    word = None

    # Method to check if the given coordinates are within the bounds of the board
    def isValid(self, x, y):
        return x >= 0 and x < len(self.board) and y >= 0 and y < len(self.board[0])

    # Depth-First Search (DFS) method to explore the board for the word
    def doDFS(self, x, y, nextIdx):
        # Mark the current cell as visited
        self.visited[x][y] = True

        # Check if we have found the entire word
        if nextIdx == len(self.word):
            return True

        # Explore all four possible directions
        for i in range(4):
            xi = x + self.dx[i] # New x coordinate
            yi = y + self.dy[i] # New y coordinate
            
            # Check if the next cell is valid, matches the next character in the word, and is not visited
            if self.isValid(xi, yi) and self.board[xi][yi] == self.word[nextIdx] and not self.visited[xi][yi]:
                # Recursively call doDFS for the next character in the word
                exists = self.doDFS(xi, yi, nextIdx + 1)
                if exists:
                    return True # If the word exists, return true
        return False # Return false if the word is not found

    # Main method to check if the word exists in the board
    def exist(self, board, word):
        self.board = board # Initialize the board
        self.word = word   # Initialize the word
        
        # Iterate through each cell in the board
        for i in range(len(board)):
            for j in range(len(board[0])):
                # If the current cell matches the first character of the word
                if board[i][j] == word[0]:
                    # Initialize the visited array for a new search
                    self.visited = [[False for j in range(len(board[0]))] for i in range(len(board))]
                    # Start DFS from the current cell for the next character
                    exists = self.doDFS(i, j, 1)
                    if exists:
                        return True # If the word exists, return true
        return False # Return false if the word is not found in the board

# Main entry point of the program
if __name__ == "__main__":
    # Read the dimensions of the board
    rows = int(input())
    cols = int(input())
    
    # Initialize the board
    board = [[0 for j in range(cols)] for i in range(rows)]
    
    # Read the board input from the user
    for i in range(rows):
        row = input()
        board[i] = list(row) # Convert each row to a character array
    
    # Read the word to search for
    word = input()
    
    # Create an instance of Main to use the exist method
    wordSearch = Main()
    
    # Check if the word exists in the board
    result = wordSearch.exist(board, word)
    
    # Output the result
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")

