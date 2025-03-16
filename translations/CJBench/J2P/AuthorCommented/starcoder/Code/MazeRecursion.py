
import sys

# This class contains methods to solve a maze using recursive backtracking.
# The maze is represented as a 2D array where walls, paths, and visited/dead
# ends are marked with different integers.
class Main:

    def __init__(self):
        pass

    def main(self):
        # Input maze dimensions
        rows = int(sys.stdin.readline())
        cols = int(sys.stdin.readline())

        maze = []
        for i in range(rows):
            maze.append(list(map(int, sys.stdin.readline().split())))

        # Choose strategy
        strategy = int(sys.stdin.readline())

        solvedMaze = None
        if strategy == 1:
            solvedMaze = self.solveMazeUsingFirstStrategy(maze)
        elif strategy == 2:
            solvedMaze = self.solveMazeUsingSecondStrategy(maze)
        else:
            print("Invalid strategy choice.")
            return

        # Output the result
        if solvedMaze!= None:
            print("Solved maze:")
            for row in solvedMaze:
                for cell in row:
                    print(cell, end=" ")
                print()
        else:
            print("No solution exists.")

    # This method solves the maze using the "down -> right -> up -> left"
    # movement strategy.
    #
    # @param map The 2D array representing the maze (walls, paths, etc.)
    # @return The solved maze with paths marked, or null if no solution exists.
    def solveMazeUsingFirstStrategy(self, map):
        if self.setWay(map, 1, 1):
            return map
        return None

    # This method solves the maze using the "up -> right -> down -> left"
    # movement strategy.
    #
    # @param map The 2D array representing the maze (walls, paths, etc.)
    # @return The solved maze with paths marked, or null if no solution exists.
    def solveMazeUsingSecondStrategy(self, map):
        if self.setWay2(map, 1, 1):
            return map
        return None

    # Attempts to find a path through the maze using a "down -> right -> up -> left"
    # movement strategy. The path is marked with '2' for valid paths and '3' for dead ends.
    #
    # @param map The 2D array representing the maze (walls, paths, etc.)
    # @param i   The current x-coordinate of the ball (row index)
    # @param j   The current y-coordinate of the ball (column index)
    # @return True if a path is found to (6,5), otherwise false
    def setWay(self, map, i, j):
        if i == len(map) - 2 and j == len(map[0]) - 2:
            map[i][j] = 2
            return True

        if map[i][j] == 0:
            map[i][j] = 2

            # Move down
            if self.setWay(map, i + 1, j):
                return True
            # Move right
            elif self.setWay(map, i, j + 1):
                return True
            # Move up
            elif self.setWay(map, i - 1, j):
                return True
            # Move left
            elif self.setWay(map, i, j - 1):
                return True

            map[i][j] = 3 # Mark as dead end (3) if no direction worked
            return False
        return False

    # Attempts to find a path through the maze using an alternative movement
    # strategy "up -> right -> down -> left".
    #
    # @param map The 2D array representing the maze (walls, paths, etc.)
    # @param i   The current x-coordinate of the ball (row index)
    # @param j   The current y-coordinate of the ball (column index)
    # @return True if a path is found to (6,5), otherwise false
    def setWay2(self, map, i, j):
        if i == len(map) - 2 and j == len(map[0]) - 2:
            map[i][j] = 2
            return True

        if map[i][j] == 0:
            map[i][j] = 2

            # Move up
            if self.setWay2(map, i - 1, j):
                return True
            # Move right
            elif self.setWay2(map, i, j + 1):
                return True
            # Move down
            elif self.setWay2(map, i + 1, j):
                return True
            # Move left
            elif self.setWay2(map, i, j - 1):
                return True

            map[i][j] = 3 # Mark as dead end (3) if no direction worked
            return False
        return False

# 