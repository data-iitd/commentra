import sys

class Main:

    class Solution:
        def __init__(self, isFound, cellsTaken):
            self.isFound = isFound
            self.cellsTaken = cellsTaken

        def prettyPrint(self):
            if not self.isFound:
                print("No solution found.")
                return
            size = len(self.cellsTaken)
            for i in range(size):
                for j in range(size):
                    print("Q" if self.cellsTaken[i][j] else ".", end=" ")
                print()

    def solve(self, boardSize):
        cellsTaken = [[False for _ in range(boardSize)] for _ in range(boardSize)]
        isFound = self.checkSolution(boardSize, cellsTaken, 0)

        return Solution(isFound, cellsTaken)

    def checkSolution(self, size, cellsTaken, queensPositioned):
        if not self.isLegal(size, cellsTaken):
            return False
        if queensPositioned == size:
            return True

        for row in range(size):
            for col in range(size):
                if not cellsTaken[row][col]:
                    cellsTaken[row][col] = True

                    if self.checkSolution(size, cellsTaken, queensPositioned + 1):
                        return True
                    else:
                        cellsTaken[row][col] = False

        return False

    def isLegal(self, size, cellsTaken):
        for i in range(size):
            for j in range(size):
                if cellsTaken[i][j]:
                    # check rows
                    for r in range(1, size):
                        if i + r < size and cellsTaken[i + r][j]:
                            return False
                        if i - r >= 0 and cellsTaken[i - r][j]:
                            return False

                    # check columns
                    for r in range(1, size):
                        if j + r < size and cellsTaken[i][j + r]:
                            return False
                        if j - r >= 0 and cellsTaken[i][j - r]:
                            return False

                    # check diagonals
                    for r in range(1, size):
                        if i + r < size and j + r < size and cellsTaken[i + r][j + r]:
                            return False
                        if i + r < size and j - r >= 0 and cellsTaken[i + r][j - r]:
                            return False
                        if i - r >= 0 and j + r < size and cellsTaken[i - r][j + r]:
                            return False
                        if i - r >= 0 and j - r >= 0 and cellsTaken[i - r][j - r]:
                            return False

        return True

if __name__ == "__main__":
    boardSize = int(sys.stdin.readline())
    eightQueens = Main()
    solution = eightQueens.solve(boardSize)

    solution.prettyPrint()

