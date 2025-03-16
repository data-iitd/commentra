
import sys

def main():
    # Read the number of rows and columns in the maze from the user
    rows = int(input())
    cols = int(input())

    # Create a 2D list to represent the maze
    maze = [[0 for i in range(cols)] for j in range(rows)]

    # Read the maze from the user
    for i in range(rows):
        for j in range(cols):
            maze[i][j] = int(input())

    # Read the strategy number from the user
    strategy = int(input())

    # Initialize the solved maze as None
    solved_maze = None

    # If the user chooses the first strategy
    if strategy == 1:
        # Call the solve_maze_using_first_strategy function to solve the maze using the first strategy
        solved_maze = solve_maze_using_first_strategy(maze)

    # If the user chooses the second strategy
    elif strategy == 2:
        # Call the solve_maze_using_second_strategy function to solve the maze using the second strategy
        solved_maze = solve_maze_using_second_strategy(maze)

    # If the user chooses an invalid strategy
    else:
        # Print an error message and exit the program
        print("Invalid strategy choice.")
        sys.exit()

    # If a solution was found
    if solved_maze is not None:
        # Print a message to indicate that the solved maze will be displayed
        print("Solved maze:")

        # Iterate through each row in the solved maze
        for row in solved_maze:
            # Iterate through each cell in the current row
            for cell in row:
                # Print the cell value to the console
                print(cell, end=" ")
            # Move to the next line after printing the current row
            print()

    # If no solution was found
    else:
        # Print a message to indicate that no solution was found
        print("No solution exists.")

    # Close the Scanner object to free up system resources
    # scanner.close()

def solve_maze_using_first_strategy(map):
    # Function to solve the maze using the first strategy
    if set_way(map, 1, 1):
        return map
    return None

def solve_maze_using_second_strategy(map):
    # Function to solve the maze using the second strategy
    if set_way2(map, 1, 1):
        return map
    return None

def set_way(map, i, j):
    # Function to try and find a solution by setting the current cell as visited and recursively exploring the neighbors
    if i == len(map) - 2 and j == len(map[0]) - 2:
        map[i][j] = 2
        return True

    if map[i][j] == 0:
        map[i][j] = 2

        if set_way(map, i + 1, j):
            return True

        elif set_way(map, i, j + 1):
            return True

        elif set_way(map, i - 1, j):
            return True

        elif set_way(map, i, j - 1):
            return True

        map[i][j] = 3
        return False

    return False

def set_way2(map, i, j):
    # Function identical to set_way, but with different variable names for readability
    if i == len(map) - 2 and j == len(map[0]) - 2:
        map[i][j] = 2
        return True

    if map[i][j] == 0:
        map[i][j] = 2

        if set_way2(map, i - 1, j):
            return True

        elif set_way2(map, i, j + 1):
            return True

        elif set_way2(map, i + 1, j):
            return True

        elif set_way2(map, i, j - 1):
            return True

        map[i][j] = 3
        return False

    return False

if __name__ == "__main__":
    main()

