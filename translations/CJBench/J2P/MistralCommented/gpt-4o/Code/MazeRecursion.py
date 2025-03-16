class Main:
    @staticmethod
    def main():
        rows = int(input())  # Read the number of rows in the maze from the user
        cols = int(input())  # Read the number of columns in the maze from the user

        maze = []  # Create a list to represent the maze
        for _ in range(rows):  # Iterate through each row in the maze
            row = list(map(int, input().split()))  # Read the cell values of the current row from the user
            maze.append(row)

        strategy = int(input())  # Read the strategy number from the user

        solved_maze = None  # Initialize the solved maze as None

        if strategy == 1:  # If the user chooses the first strategy
            solved_maze = Main.solve_maze_using_first_strategy(maze)  # Call the function to solve the maze using the first strategy
        elif strategy == 2:  # If the user chooses the second strategy
            solved_maze = Main.solve_maze_using_second_strategy(maze)  # Call the function to solve the maze using the second strategy
        else:  # If the user chooses an invalid strategy
            print("Invalid strategy choice.")  # Print an error message and exit the program
            return

        if solved_maze is not None:  # If a solution was found
            print("Solved maze:")  # Print a message to indicate that the solved maze will be displayed
            for row in solved_maze:  # Iterate through each row in the solved maze
                print(" ".join(map(str, row)))  # Print the cell values of the current row
        else:  # If no solution was found
            print("No solution exists.")  # Print a message to indicate that no solution was found

    @staticmethod
    def solve_maze_using_first_strategy(map):
        # Function to solve the maze using the first strategy
        if Main.set_way(map, 1, 1):  # Call the set_way function to try and find a solution starting from the first cell
            return map  # Return the solved maze if a solution was found
        return None  # Return None if no solution was found

    @staticmethod
    def solve_maze_using_second_strategy(map):
        # Function to solve the maze using the second strategy
        if Main.set_way2(map, 1, 1):  # Call the set_way2 function to try and find a solution starting from the first cell
            return map  # Return the solved maze if a solution was found
        return None  # Return None if no solution was found

    @staticmethod
    def set_way(map, i, j):
        # Function to try and find a solution by setting the current cell as visited and recursively exploring the neighbors
        if i == len(map) - 2 and j == len(map[0]) - 2:  # If the current cell is the exit cell
            map[i][j] = 2  # Set the exit cell as visited (solved)
            return True  # Return True to indicate that a solution was found

        if map[i][j] == 0:  # If the current cell is unvisited
            map[i][j] = 2  # Set the current cell as visited

            if Main.set_way(map, i + 1, j):  # Try to find a solution by moving down
                return True
            elif Main.set_way(map, i, j + 1):  # Try to find a solution by moving right
                return True
            elif Main.set_way(map, i - 1, j):  # Try to find a solution by moving up
                return True
            elif Main.set_way(map, i, j - 1):  # Try to find a solution by moving left
                return True

            map[i][j] = 3  # Set the current cell back to unvisited if no solution was found in any direction
            return False

        return False  # Return False if the current cell is already visited

    @staticmethod
    def set_way2(map, i, j):
        # Function identical to set_way, but with different variable names for readability
        if i == len(map) - 2 and j == len(map[0]) - 2:
            map[i][j] = 2
            return True

        if map[i][j] == 0:
            map[i][j] = 2

            if Main.set_way2(map, i - 1, j):
                return True
            elif Main.set_way2(map, i, j + 1):
                return True
            elif Main.set_way2(map, i + 1, j):
                return True
            elif Main.set_way2(map, i, j - 1):
                return True

            map[i][j] = 3
            return False

        return False

if __name__ == "__main__":
    Main.main()  # Run the main function

# <END-OF-CODE>
