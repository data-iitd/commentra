
import sys
import copy

class Main:
    BASE = 12
    MOVES = [[1, -2], [2, -1], [2, 1], [1, 2], [-1, 2], [-2, 1], [-2, -1], [-1, -2]]
    grid = None
    total = None
    def resetBoard(self, size):
        self.grid = [[0 for i in range(size + 4)] for j in range(size + 4)]
        self.total = size * size
        for r in range(len(self.grid)):
            for c in range(len(self.grid[0])):
                if r < 2 or r >= len(self.grid) - 2 or c < 2 or c >= len(self.grid[0]) - 2:
                    self.grid[r][c] = -1
    def solve(self, row, col, count):
        if count > self.total: return True
        neighbor = self.neighbors(row, col)
        if len(neighbor) == 0 and count!= self.total: return False
        neighbor.sort(key = lambda x: x[2])
        for nb in neighbor:
            nextRow = nb[0]
            nextCol = nb[1]
            self.grid[nextRow][nextCol] = count
            if not self.orphanDetected(count, nextRow, nextCol) and self.solve(nextRow, nextCol, count + 1):
                return True
            self.grid[nextRow][nextCol] = 0
        return False
    def neighbors(self, row, col):
        neighbor = []
        for m in self.MOVES:
            x = row + m[0]
            y = col + m[1]
            if self.grid[x][y] == 0:
                neighbor.append([x, y, self.countNeighbors(x, y)])
        return neighbor
    def countNeighbors(self, row, col):
        count = 0
        for m in self.MOVES:
            x = row + m[0]
            y = col + m[1]
            if self.grid[x][y] == 0: count += 1
        return count
    def orphanDetected(self, count, row, col):
        if count < self.total - 1:
            for nb in self.neighbors(row, col):
                if self.countNeighbors(nb[0], nb[1]) == 0:
                    return True
        return False
    def printSolution(self, size):
        for r in range(2, size + 2):
            for c in range(2, size + 2):
                print("%3d" % self.grid[r][c], end = "")
            print()
    def main(self):
        size = int(input())
        startRow = int(input())
        startCol = int(input())
        self.resetBoard(size)
        self.grid[startRow + 2][startCol + 2] = 1
        if self.solve(startRow + 2, startCol + 2, 2):
            print("Knight's tour solution:")
            self.printSolution(size)
        else:
            print("No solution exists.")

if __name__ == "__main__":
    Main().main()

