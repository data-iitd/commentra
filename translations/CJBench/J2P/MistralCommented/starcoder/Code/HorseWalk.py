
import sys

# Define a Cell class to represent a cell on the board
class Cell:
    CHARS = "abcdefgh"

    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Method to convert a Cell to its coordinate in the checkmate coordinate system
    def convertToCheckMateCoordinateSystem(self):
        return "{}{}".format(self.CHARS[self.x], self.y + 1)


# Define a Solution class to store the solution and its log
class Solution:
    def __init__(self, isFound, cellsTaken, log):
        self.isFound = isFound
        self.cellsTaken = cellsTaken
        self.log = log

    # Method to print the solution log
    def printLog(self):
        if not self.isFound or len(self.log)!= self.cellsTaken.length * self.cellsTaken.length:
            print("No solution found!")
            return
        board = [[0 for _ in range(self.cellsTaken.length)] for _ in range(self.cellsTaken.length)]
        positionNumber = 0
        for cell in self.log:
            positionNumber += 1
            board[cell.x][cell.y] = positionNumber
        for row in board:
            for cell in row:
                print(cell, end="\t")
            print()


# Main method to solve the problem and print the solution
def main():
    boardSize = int(sys.stdin.readline().strip())
    horseWalk = Main()
    solution = horseWalk.solve(boardSize)
    solution.printLog()


# Method to solve the problem and find a solution
def solve(self, boardSize):
    cellsTaken = [[False for _ in range(boardSize)] for _ in range(boardSize)]
    cellsTaken[0][0] = True
    log = []
    log.append(Cell(0, 0))
    isFound = self.checkSolution(boardSize, cellsTaken, 1, 0, 0, log)
    return Solution(isFound, cellsTaken, log)


# Recursive method to check if a solution exists
def checkSolution(self, size, cellsTaken, cellsVisited, currX, currY, log):
    if cellsVisited == size * size:
        # Base case: if all cells have been visited, a solution has been found
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
        if self.checkSolution(size, cellsTaken, cellsVisited + 1, nextX, nextY, log):
            # Recursive call: if a solution is found, return true
            return True
        else:
            log.pop()
            cellsTaken[nextX][nextY] = False
    # If no solution is found, return false
    return False


if __name__ == "__main__":
    main()

# 