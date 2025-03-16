import sys

# Private class to prevent instantiation of the Main class
class Main:
    # Private constructor to prevent instantiation of the Main class
    def __init__(self):
        pass

    # Main method
    def main(self):
        # Read the number of rows and columns for the maze
        rows = int(sys.stdin.readline())
        cols = int(sys.stdin.readline())

        # Initialize the maze with the specified dimensions
        maze = [[0 for i in range(cols)] for j in range(rows)]

        # Populate the maze with input values
        for i in range(rows):
            for j in range(cols):
                maze[i][j] = int(sys.stdin.readline())

        # Read the strategy choice for solving the maze
        strategy = int(sys.stdin.readline())
        solvedMaze = None

        # Determine which strategy to use for solving the maze
        if strategy == 1:
            solvedMaze = self.solveMazeUsingFirstStrategy(maze)
        elif strategy == 2:
            solvedMaze = self.solveMazeUsingSecondStrategy(maze)
        else:
            # Handle invalid strategy choice
            print("Invalid strategy choice.")
            return

        # Output the solved maze or indicate that no solution exists
        if solvedMaze!= None:
            print("Solved maze:")
            for row in solvedMaze:
                for cell in row:
                    print(cell, end=" ")
                print()
        else:
            print("No solution exists.")

    # Method to solve the maze using the first strategy
    def solveMazeUsingFirstStrategy(self, map):
        # Attempt to find a way through the maze starting from (1, 1)
        if self.setWay(map, 1, 1):
            return map # Return the solved maze if successful
        return None # Return null if no solution is found

    # Method to solve the maze using the second strategy
    def solveMazeUsingSecondStrategy(self, map):
        # Attempt to find a way through the maze starting from (1, 1)
        if self.setWay2(map, 1, 1):
            return map # Return the solved maze if successful
        return None # Return null if no solution is found

    # Recursive method to find a path in the maze using the first strategy
    def setWay(self, map, i, j):
        # Check if the exit is reached
        if i == len(map) - 2 and j == len(map[0]) - 2:
            map[i][j] = 2 # Mark the exit
            return True # Exit found

        # Check if the current cell is open (0)
        if map[i][j] == 0:
            map[i][j] = 2 # Mark the cell as part of the path
            # Recursively explore the neighboring cells
            if self.setWay(map, i + 1, j) or \
               self.setWay(map, i, j + 1) or \
               self.setWay(map, i - 1, j) or \
               self.setWay(map, i, j - 1):
                return True # Path found
            map[i][j] = 3 # Mark the cell as visited (dead end)
            return False # No path found
        return False # Cell is not open

    # Recursive method to find a path in the maze using the second strategy
    def setWay2(self, map, i, j):
        # Check if the exit is reached
        if i == len(map) - 2 and j == len(map[0]) - 2:
            map[i][j] = 2 # Mark the exit
            return True # Exit found

        # Check if the current cell is open (0)
        if map[i][j] == 0:
            map[i][j] = 2 # Mark the cell as part of the path
            # Recursively explore the neighboring cells in a different order
            if self.setWay2(map, i - 1, j) or \
               self.setWay2(map, i, j + 1) or \
               self.setWay2(map, i + 1, j) or \
               self.setWay2(map, i, j - 1):
                return True # Path found
            map[i][j] = 3 # Mark the cell as visited (dead end)
            return False # No path found
        return False # Cell is not open

# Main entry point
if __name__ == "__main__":
    Main().main()

# 