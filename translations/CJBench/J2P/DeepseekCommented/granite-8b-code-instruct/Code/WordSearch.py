
import sys

class Solution:
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
    def isValid(self, x, y):
        return x >= 0 and x < len(self.board) and y >= 0 and y < len(self.board[0])
    
    # Depth-First Search (DFS) method to find the word in the board
    def doDFS(self, x, y, nextIdx):
        # Mark the current cell as visited
        self.visited[x][y] = True
        
        # If we have reached the end of the word, return true
        if nextIdx == len(self.word):
            return True
        
        # Explore all four possible directions
        for i in range(4):
            xi = x + self.dx[i]
            yi = y + self.dy[i]
            
            # Check if the new cell is within bounds, matches the next character of the word, and hasn't been visited
            if self.isValid(xi, yi) and self.board[xi][yi] == self.word[nextIdx] and not self.visited[xi][yi]:
                # Recursively call doDFS for the new cell
                exists = self.doDFS(xi, yi, nextIdx + 1)
                if exists:
                    return True
        
        # Backtrack: unmark the current cell as visited
        self.visited[x][y] = False 
        
        # Return false if the word cannot be formed from the current path
        return False
    
    # Method to check if the word exists in the board
    def exist(self, board, word):
        self.board = board
        self.word = word
        
        # Initialize the visited array for each DFS search
        self.visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        
        # Iterate over each cell in the board to start a DFS search
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    # Start DFS from the current cell
                    exists = self.doDFS(i, j, 1)
                    if exists:
                        return True
        
        # Return false if the word does not exist in the board
        return False

# Main method to read input, create an instance of Solution, and print the result
if __name__ == "__main__":
    # Read the dimensions of the board
    rows = int(input())
    cols = int(input())
    
    # Initialize the board with the given dimensions
    board = []
    for _ in range(rows):
        row = input()
        board.append(list(row))
    
    # Read the word to be searched
    word = input()
    
    # Create an instance of Solution and check if the word exists in the board
    solution = Solution()
    result = solution.exist(board, word)
    
    # Print the result
    if result:
        print("The word exists in the board.")
    else:
        print("The word does not exist in the board.")