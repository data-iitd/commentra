

import sys

def main():
    # Input maze dimensions
    rows, cols = map(int, input().split())

    maze = []
    for _ in range(rows):
        maze.append(list(map(int, input().split())))

    # Choose strategy
    strategy = int(input())

    solved_maze = None
    if strategy == 1:
        solved_maze = solve_maze_using_first_strategy(maze)
    elif strategy == 2:
        solved_maze = solve_maze_using_second_strategy(maze)
    else:
        print("Invalid strategy choice.")
        return

    # Output the result
    if solved_maze is not None:
        print("Solved maze:")
        for row in solved_maze:
            print(" ".join(map(str, row)))
    else:
        print("No solution exists.")

def solve_maze_using_first_strategy(maze):
    if set_way(maze, 1, 1):
        return maze
    return None

def solve_maze_using_second_strategy(maze):
    if set_way2(maze, 1, 1):
        return maze
    return None

def set_way(maze, i, j):
    if i == len(maze) - 2 and j == len(maze[0]) - 2:
        maze[i][j] = 2
        return True

    if maze[i][j] == 0:
        maze[i][j] = 2

        # Move down
        if set_way(maze, i + 1, j):
            return True
        # Move right
        elif set_way(maze, i, j + 1):
            return True
        # Move up
        elif set_way(maze, i - 1, j):
            return True
        # Move left
        elif set_way(maze, i, j - 1):
            return True

        maze[i][j] = 3 # Mark as dead end (3) if no direction worked
        return False
    return False

def set_way2(maze, i, j):
    if i == len(maze) - 2 and j == len(maze[0]) - 2:
        maze[i][j] = 2
        return True

    if maze[i][j] == 0:
        maze[i][j] = 2

        # Move up
        if set_way2(maze, i - 1, j):
            return True
        # Move right
        elif set_way2(maze, i, j + 1):
            return True
        # Move down
        elif set_way2(maze, i + 1, j):
            return True
        # Move left
        elif set_way2(maze, i, j - 1):
            return True

        maze[i][j] = 3 # Mark as dead end (3) if no direction worked
        return False
    return False

if __name__ == "__main__":
    main()

