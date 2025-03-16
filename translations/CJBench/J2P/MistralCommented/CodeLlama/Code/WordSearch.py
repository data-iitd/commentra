
import sys

class Main:
    # Declare 2D arrays for visited cells and the board
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    visited = []
    board = []
    
    # Declare a string variable for the given word
    word = ""
    
    # Helper method to check if given coordinates are valid
    def isValid(self, x, y):
        return x >= 0 and x < len(self.board) and y >= 0 and y < len(self.board[0])
    
    # Depth-First Search (DFS) helper method to find a word in the board
    def doDFS(self, x, y, nextIdx):
        # Mark the current cell as visited
        self.visited[x][y] = True
        
        # Base case: if we have visited all characters in the word
        if nextIdx == len(self.word):
            return True
        
        # Iterate through all possible directions
        for i in range(4):
            xi = x + self.dx[i]
            yi = y + self.dy[i]
            
            # Check if the new coordinates are valid and the character matches the word
            if self.isValid(xi, yi) and self.board[xi][yi] == self.word[nextIdx] and not self.visited[xi][yi]:
                # Recursive call to search for the next character in the word
                exists = self.doDFS(xi, yi, nextIdx + 1)
                
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
        
        # Iterate through all cells in the board
        for i in range(len(board)):
            for j in range(len(board[0])):
                # If we find the first character of the word, start the DFS search
                if board[i][j] == word[0]:
                    self.visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
                    exists = self.doDFS(i, j, 1)
                    
                    # If the DFS search returns true, we have found the word
                    if exists:
                        return True
        
        # If we haven't found the word, return false
        return False
    
    # Main method to run the program
    def main(self):
        # Read the dimensions of the board and initialize it
        rows = int(input())
        cols = int(input())
        board = []
        for i in range(rows):
            row = input()
            board.append(list(row))
        
        # Read the word to search for
        word = input()
        
        # Create an instance of the Main class and call the exist method
        wordSearch = Main()
        result = wordSearch.exist(board, word)
        
        # Print the result
        if result:
            print("The word exists in the board.")
        else:
            print("The word does not exist in the board.")

# END-OF-CODE
