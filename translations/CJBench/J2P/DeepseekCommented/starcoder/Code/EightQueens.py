import sys

class Main:
    class Solution:
        def __init__(self, isFound, cellsTaken):
            self.isFound = isFound
            self.cellsTaken = cellsTaken
        # This method prints the board in a readable format.
        # If no solution is found, it prints "No solution found."
        def prettyPrint(self):
            if not self.isFound:
                print("No solution found.")
                return
            size = len(self.cellsTaken)
            for i in range(size):
                for j in range(size):
                    print("Q" if self.cellsTaken[i][j] else ".", end=" ")
                print()

    # This method initializes the board and starts the process to find a solution.
    def solve(self, boardSize):
        cellsTaken = [[False for i in range(boardSize)] for j in range(boardSize)]
        isFound = self.checkSolution(boardSize, cellsTaken, 0)
        return Solution(isFound, cellsTaken)

    # This recursive method attempts to place queens on the board.
    # It checks if the current state is legal and tries to place queens in each row.
    def checkSolution(self, size, cellsTaken, queensPositioned):
        if not self.isLegal(size, cellsTaken): # Check if the current state is legal
            return False
        if queensPositioned == size: # If all queens are positioned, a solution is found
            return True
        for row in range(size):
            for col in range(size):
                if not cellsTaken[row][col]: # Try to place a queen if the cell is empty
                    cellsTaken[row][col] = True
                    if self.checkSolution(size, cellsTaken, queensPositioned + 1): # Recursively check the next position
                        return True
                    else:
                        cellsTaken[row][col] = False # Backtrack if placing a queen doesn't lead to a solution
        return False

    # This method checks if the current board state is legal.
    # It ensures no two queens are in the same row, column, or diagonal.
    def isLegal(self, size, cellsTaken):
        for i in range(size):
            for j in range(size):
                if cellsTaken[i][j]:
                    for r in range(1, size):
                        if i + r < size and cellsTaken[i + r][j]: # Check for same column
                            return False
                        if i - r >= 0 and cellsTaken[i - r][j]: # Check for same column
                            return False
                    for r in range(1, size):
                        if j + r < size and cellsTaken[i][j + r]: # Check for same row
                            return False
                        if j - r >= 0 and cellsTaken[i][j - r]: # Check for same row
                            return False
                    for r in range(1, size):
                        if i + r < size and j + r < size and cellsTaken[i + r][j + r]: # Check for diagonal
                            return False
                        if i + r < size and j - r >= 0 and cellsTaken[i + r][j - r]: # Check for diagonal
                            return False
                        if i - r >= 0 and j + r < size and cellsTaken[i - r][j + r]: # Check for diagonal
                            return False
                        if i - r >= 0 and j - r >= 0 and cellsTaken[i - r][j - r]: # Check for diagonal
                            return False
        return True

if __name__ == "__main__":
    boardSize = int(sys.stdin.readline())
    eightQueens = Main()
    solution = eightQueens.solve(boardSize)
    solution.prettyPrint()

