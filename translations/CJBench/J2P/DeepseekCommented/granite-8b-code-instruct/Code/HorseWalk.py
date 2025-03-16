
import sys
from collections import deque

class Cell:
    CHARS = "abcdefgh"
    def __init__(self, x, y):
        self.x = x
        self.y = y
    # Converts the cell's coordinates to a chessboard-friendly format.
    def convertToCheckMateCoordinateSystem(self):
        return f"{Cell.CHARS[self.x]}{self.y + 1}"

class Solution:
    def __init__(self, isFound, cellsTaken, log):
        self.isFound = isFound
        self.cellsTaken = cellsTaken
        self.log = log
    # Prints the board with the order of cells visited by the knight.
    def printLog(self):
        if not self.isFound or len(self.log)!= len(self.cellsTaken) * len(self.cellsTaken):
            print("No solution found!")
            return
        board = [[0 for _ in range(len(self.cellsTaken))] for _ in range(len(self.cellsTaken))]
        positionNumber = 0
        for cell in self.log:
            positionNumber += 1
            board[cell.x][cell.y] = positionNumber
        for row in board:
            for cell in row:
                print(cell, end="\t")
            print()

# Initializes the board and starts the knight's tour.
def solve(boardSize):
    cellsTaken = [[False for _ in range(boardSize)] for _ in range(boardSize)]
    cellsTaken[0][0] = True
    log = deque([Cell(0, 0)])
    isFound = checkSolution(boardSize, cellsTaken, 1, 0, 0, log)
    return Solution(isFound, cellsTaken, log)

# Attempts to find a valid knight's tour path recursively.
def checkSolution(size, cellsTaken, cellsVisited, currX, currY, log):
    if cellsVisited == size * size:
        return True
    POSSIBLE_MOVES = [[-2, -1], [-2, 1], [2, 1], [2, -1], [1, 2], [1, -2], [-1, 2], [-1, -2]]
    for move in POSSIBLE_MOVES:
        nextX = currX + move[0]
        nextY = currY + move[1]
        if nextX < 0 or nextX >= size or nextY < 0 or nextY >= size:
            continue
        if cellsTaken[nextX][nextY]:
            continue
        cellsTaken[nextX][nextY] = True
        log.append(Cell(nextX, nextY))
        if checkSolution(size, cellsTaken, cellsVisited + 1, nextX, nextY, log):
            return True
        else:
            log.pop()
            cellsTaken[nextX][nextY] = False
    return False

# Reads the board size from the user, solves the knight's tour problem, and prints the result.
if __name__ == "__main__":
    boardSize = int(input())
    solution = solve(boardSize)
    solution.printLog()

