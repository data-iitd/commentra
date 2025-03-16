import sys

def solve_maze(maze):
    rows = len(maze)
    cols = len(maze[0])
    if rows == 0 or cols == 0:
        return None
    if set_way(maze, 0, 0):
        return maze
    return None

def set_way(maze, i, j):
    rows = len(maze)
    cols = len(maze[0])
    if i == rows - 2 and j == cols - 2:
        maze[i][j] = 2
        return True
    if maze[i][j] == 0:
        maze[i][j] = 2
        if set_way(maze, i + 1, j):
            return True
        elif set_way(maze, i, j + 1):
            return True
        elif set_way(maze, i - 1, j):
            return True
        elif set_way(maze, i, j - 1):
            return True
        maze[i][j] = 3
        return False
    return False

def solve_maze2(maze):
    rows = len(maze)
    cols = len(maze[0])
    if rows == 0 or cols == 0:
        return None
    if set_way2(maze, 0, 0):
        return maze
    return None

def set_way2(maze, i, j):
    rows = len(maze)
    cols = len(maze[0])
    if i == rows - 2 and j == cols - 2:
        maze[i][j] = 2
        return True
    if maze[i][j] == 0:
        maze[i][j] = 2
        if set_way2(maze, i - 1, j):
            return True
        elif set_way2(maze, i, j + 1):
            return True
        elif set_way2(maze, i + 1, j):
            return True
        elif set_way2(maze, i, j - 1):
            return True
        maze[i][j] = 3
        return False
    return False

def main():
    # Read the dimensions of the maze
    rows = int(input())
    cols = int(input())
    maze = []
    for i in range(rows):
        maze.append([])
        for j in range(cols):
            maze[i].append(int(input()))
    
    # Prompt the user to choose a strategy for solving the maze
    strategy = int(input())
    solved_maze = None
    
    # Solve the maze using the chosen strategy
    if strategy == 1:
        solved_maze = solve_maze(maze)
    elif strategy == 2:
        solved_maze = solve_maze2(maze)
    else:
        print("Invalid strategy choice.")
        return
    
    # Output the solved maze or a message indicating no solution exists
    if solved_maze != None:
        print("Solved maze:")
        for row in solved_maze:
            for cell in row:
                print(cell, end=" ")
            print()
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

