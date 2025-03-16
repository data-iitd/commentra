import sys

def main():
    # Read the number of rows and columns for the maze
    rows, cols = map(int, sys.stdin.readline().split())
    
    # Initialize the maze with the specified dimensions
    maze = [[0] * cols for _ in range(rows)]
    
    # Populate the maze with input values
    for i in range(rows):
        for j in range(cols):
            maze[i][j] = int(sys.stdin.readline())
    
    # Read the strategy choice for solving the maze
    strategy = int(sys.stdin.readline())
    solved_maze = None

    # Determine which strategy to use for solving the maze
    if strategy == 1:
        solved_maze = solve_maze_using_first_strategy(maze)
    elif strategy == 2:
        solved_maze = solve_maze_using_second_strategy(maze)
    else:
        # Handle invalid strategy choice
        print("Invalid strategy choice.")
        return

    # Output the solved maze or indicate that no solution exists
    if solved_maze is not None:
        print("Solved maze:")
        for row in solved_maze:
            for cell in row:
                print(cell, end=" ")
            print()
    else:
        print("No solution exists.")

def solve_maze_using_first_strategy(map):
    # Attempt to find a way through the maze starting from (1, 1)
    if set_way(map, 1, 1):
        return map # Return the solved maze if successful
    return None # Return null if no solution is found

def solve_maze_using_second_strategy(map):
    # Attempt to find a way through the maze starting from (1, 1)
    if set_way2(map, 1, 1):
        return map # Return the solved maze if successful
    return None # Return null if no solution is found

def set_way(map, i, j):
    # Check if the exit is reached
    if i == len(map) - 2 and j == len(map[0]) - 2:
        map[i][j] = 2 # Mark the exit
        return True # Exit found
    
    # Check if the current cell is open (0)
    if map[i][j] == 0:
        map[i][j] = 2 # Mark the cell as part of the path
        # Recursively explore the neighboring cells
        if set_way(map, i + 1, j) or \
           set_way(map, i, j + 1) or \
           set_way(map, i - 1, j) or \
           set_way(map, i, j - 1):
            return True # Path found
        map[i][j] = 3 # Mark the cell as visited (dead end)
        return False # No path found
    return False # Cell is not open

def set_way2(map, i, j):
    # Check if the exit is reached
    if i == len(map) - 2 and j == len(map[0]) - 2:
        map[i][j] = 2 # Mark the exit
        return True # Exit found
    
    # Check if the current cell is open (0)
    if map[i][j] == 0:
        map[i][j] = 2 # Mark the cell as part of the path
        # Recursively explore the neighboring cells in a different order
        if set_way2(map, i - 1, j) or \
           set_way2(map, i, j + 1) or \
           set_way2(map, i + 1, j) or \
           set_way2(map, i, j - 1):
            return True # Path found
        map[i][j] = 3 # Mark the cell as visited (dead end)
        return False # No path found
    return False # Cell is not open

if __name__ == "__main__":
    main()

