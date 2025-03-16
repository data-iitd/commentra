
import sys

class Main:
    class Solution:
        # Class to store the solution and its validity flag
        def __init__(self, isFound, cellsTaken):
            self.isFound = isFound
            self.cellsTaken = cellsTaken

        def prettyPrint(self):
            # Print the solution if it exists
            if not self.isFound:
                print("No solution found.")
                return

            size = len(self.cellsTaken)
            for i in range(size):
                for j in range(size):
                    print("Q" if self.cellsTaken[i][j] else ".", end=" ")
                print()

    def solve(self, boardSize):
        # Initialize the cellsTaken array and call the checkSolution method
        cellsTaken = [[False for i in range(boardSize)] for j in range(boardSize)]
        isFound = self.checkSolution(boardSize, cellsTaken, 0)

        # Return a new Solution object with the found solution and its flag
        return self.Solution(isFound, cellsTaken)

    def checkSolution(self, size, cellsTaken, queensPositioned):
        # Check if the current positioning of queens is legal
        if not self.isLegal(size, cellsTaken):
            return False

        # If all queens have been placed, return true
        if queensPositioned == size:
            return True

        # Try placing a queen in each empty cell and recursively call checkSolution
        for row in range(size):
            for col in range(size):
                if not cellsTaken[row][col]:
                    cellsTaken[row][col] = True
                    result = self.checkSolution(size, cellsTaken, queensPositioned + 1)
                    cellsTaken[row][col] = False

                    # If a solution was found, return true
                    if result:
                        return True

        # If no solution was found, return false
        return False

    def isLegal(self, size, cellsTaken):
        # Check if the current positioning of queens is legal by checking the conditions
        for i in range(size):
            for j in range(size):
                if cellsTaken[i][j]:
                    # Check the conditions for the queen at (i, j)
                    for r in range(1, size):
                        if i + r < size and cellsTaken[i + r][j]:
                            return False
                        if i - r >= 0 and cellsTaken[i - r][j]:
                            return False

                    for r in range(1, size):
                        if j + r < size and cellsTaken[i][j + r]:
                            return False
                        if j - r >= 0 and cellsTaken[i][j - r]:
                            return False

                    for r in range(1, size):
                        if i + r < size and j + r < size and cellsTaken[i + r][j + r]:
                            return False
                        if i + r < size and j - r >= 0 and cellsTaken[i + r][j - r]:
                            return False
                        if i - r >= 0 and j + r < size and cellsTaken[i - r][j + r]:
                            return False
                        if i - r >= 0 and j - r >= 0 and cellsTaken[i - r][j - r]:
                            return False

        # If all conditions are met, return true
        return True

if __name__ == "__main__":
    # Read the board size from the user input and call the solve method
    boardSize = int(sys.stdin.readline())
    eightQueens = Main()
    solution = eightQueens.solve(boardSize)

    # Print the solution using the prettyPrint method
    solution.prettyPrint()

# 