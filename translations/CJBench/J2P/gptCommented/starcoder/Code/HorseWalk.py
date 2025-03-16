import sys

# Cell class represents a position on the chessboard
class Cell:
    CHARS = "abcdefgh" # Character representation for columns

    # Constructor to initialize the cell's coordinates
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Converts the cell's coordinates to a chess notation format
    def convertToCheckMateCoordinateSystem(self):
        return "{}{}".format(self.CHARS[self.x], self.y + 1)

# Solution class encapsulates the result of the knight's tour problem
class Solution:
    def __init__(self, isFound, cellsTaken, log):
        self.isFound = isFound
        self.cellsTaken = cellsTaken
        self.log = log

    # Prints the log of the knight's tour if a solution is found
    def printLog(self):
        if not self.isFound or len(self.log)!= len(self.cellsTaken) * len(self.cellsTaken):
            print("No solution found!") # No valid solution
            return
        board = [[0 for _ in range(len(self.cellsTaken))] for _ in range(len(self.cellsTaken))] # Initialize the board
        positionNumber = 0 # Counter for the position number
        # Fill the board with the order of the knight's moves
        for cell in self.log:
            positionNumber += 1
            board[cell.x][cell.y] = positionNumber
        # Print the board with the knight's move order
        for row in board:
            for cell in row:
                print(cell, end="\t") # Print each cell with a tab space
            print() # New line after each row

# Solves the knight's tour problem for a given board size
def solve(boardSize):
    cellsTaken = [[False for _ in range(boardSize)] for _ in range(boardSize)] # Track visited cells
    cellsTaken[0][0] = True # Mark the starting cell as visited
    log = [] # Log of the knight's moves
    log.append(Cell(0, 0)) # Start from the initial position
    # Start the recursive solution check
    isFound = checkSolution(boardSize, cellsTaken, 1, 0, 0, log)
    return Solution(isFound, cellsTaken, log) # Return the solution

# Recursively checks for a valid knight's tour solution
def checkSolution(size, cellsTaken, cellsVisited, currX, currY, log):
    # If all cells have been visited, a solution is found
    if cellsVisited == size * size:
        return True
    # Possible knight moves
    POSSIBLE_MOVES = [[-2, -1], [-2, 1], [2, 1], [2, -1], [1, 2], [1, -2], [-1, 2], [-1, -2]]
    # Try each possible move
    for move in POSSIBLE_MOVES:
        nextX = currX + move[0] # Calculate next x position
        nextY = currY + move[1] # Calculate next y position
        # Check if the next position is within bounds and not visited
        if nextX < 0 or nextX >= size or nextY < 0 or nextY >= size:
            continue # Skip out-of-bounds moves
        if cellsTaken[nextX][nextY]:
            continue # Skip already visited cells
        cellsTaken[nextX][nextY] = True # Mark the next cell as visited
        log.append(Cell(nextX, nextY)) # Log the move
        # Recursively check for the next move
        if checkSolution(size, cellsTaken, cellsVisited + 1, nextX, nextY, log):
            return True # Solution found
        else:
            log.pop() # Backtrack if no solution found
            cellsTaken[nextX][nextY] = False # Unmark the cell
    return False # No solution found from this path

# Main method to execute the program
def main():
    boardSize = int(sys.stdin.readline().strip()) # Read the board size from input
    solution = solve(boardSize) # Solve the knight's tour problem
    solution.printLog() # Print the solution log

if __name__ == "__main__":
    main()

