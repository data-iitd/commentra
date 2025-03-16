import sys
import string

class Cell:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def convertToCheckMateCoordinateSystem(self):
        return "{}{}".format(string.ascii_lowercase[self.x], self.y + 1)

class Solution:
    def __init__(self, isFound, cellsTaken, log):
        self.isFound = isFound
        self.cellsTaken = cellsTaken
        self.log = log

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

class Main:
    def solve(self, boardSize):
        cellsTaken = [[False for _ in range(boardSize)] for _ in range(boardSize)]
        cellsTaken[0][0] = True
        log = []
        log.append(Cell(0, 0))
        isFound = self.checkSolution(boardSize, cellsTaken, 1, 0, 0, log)
        return Solution(isFound, cellsTaken, log)

    def checkSolution(self, size, cellsTaken, cellsVisited, currX, currY, log):
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
            if self.checkSolution(size, cellsTaken, cellsVisited + 1, nextX, nextY, log):
                return True
            else:
                log.pop()
                cellsTaken[nextX][nextY] = False
        return False

if __name__ == "__main__":
    boardSize = int(sys.stdin.readline())
    horseWalk = Main()
    solution = horseWalk.solve(boardSize)
    solution.printLog()

