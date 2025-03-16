import sys

class Main:
    # Inner class to represent the solution of the N-Queens problem
    class Solution:
        def __init__(self, isFound, cellsTaken):
            self.isFound = isFound
            self.cellsTaken = cellsTaken

        # Method to print the board in a pretty format
        def prettyPrint(self):
            # If no solution was found, print a message
            if not self.isFound:
                print("No solution found.")
                return
            size = len(self.cellsTaken) # Get the size of the board
            # Loop through each cell of the board
            for i in range(size):
                for j in range(size):
                    # Print 'Q' for a queen and '.' for an empty cell
                    print("Q" if self.cellsTaken[i][j] else ".", end=" ")
                print() # Move to the next line after each row

    # Method to solve the N-Queens problem for a given board size
    def solve(self, boardSize):
        cellsTaken = [[False] * boardSize for _ in range(boardSize)] # Initialize the board
        isFound = self.checkSolution(boardSize, cellsTaken, 0) # Start checking for solutions
        return self.Solution(isFound, cellsTaken) # Return the solution object

    # Recursive method to check for a valid solution
    def checkSolution(self, size, cellsTaken, queensPositioned):
        # Check if the current board configuration is legal
        if not self.isLegal(size, cellsTaken):
            return False # If not legal, return false
        # If all queens are positioned, a solution is found
        if queensPositioned == size:
            return True
        # Try to place a queen in each cell of the board
        for row in range(size):
            for col in range(size):
                if not cellsTaken[row][col]: # If the cell is empty
                    cellsTaken[row][col] = True # Place a queen
                    # Recursively check if placing the queen leads to a solution
                    if self.checkSolution(size, cellsTaken, queensPositioned + 1):
                        return True # If a solution is found, return true
                    else:
                        cellsTaken[row][col] = False # Backtrack if no solution found
        return False # Return false if no valid position is found

    # Method to check if the current board configuration is legal
    def isLegal(self, size, cellsTaken):
        # Loop through each cell to check for conflicts
        for i in range(size):
            for j in range(size):
                if cellsTaken[i][j]: # If there is a queen in the cell
                    # Check vertical and horizontal conflicts
                    for r in range(1, size):
                        if i + r < size and cellsTaken[i + r][j]:
                            return False # Vertical conflict
                        if i - r >= 0 and cellsTaken[i - r][j]:
                            return False # Vertical conflict
                    # Check horizontal conflicts
                    for r in range(1, size):
                        if j + r < size and cellsTaken[i][j + r]:
                            return False # Horizontal conflict
                        if j - r >= 0 and cellsTaken[i][j - r]:
                            return False # Horizontal conflict
                    # Check diagonal conflicts
                    for r in range(1, size):
                        if i + r < size and j + r < size and cellsTaken[i + r][j + r]:
                            return False # Diagonal conflict
                        if i + r < size and j - r >= 0 and cellsTaken[i + r][j - r]:
                            return False # Diagonal conflict
                        if i - r >= 0 and j + r < size and cellsTaken[i - r][j + r]:
                            return False # Diagonal conflict
                        if i - r >= 0 and j - r >= 0 and cellsTaken[i - r][j - r]:
                            return False # Diagonal conflict
        return True # Return true if no conflicts are found

# Main method to execute the program
if __name__ == "__main__":
    boardSize = int(sys.stdin.readline()) # Read the size of the board from input
    eightQueens = Main() # Create an instance of Main
    solution = eightQueens.solve(boardSize) # Solve the N-Queens problem
    solution.prettyPrint() # Print the solution

