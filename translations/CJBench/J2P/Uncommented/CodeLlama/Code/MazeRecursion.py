
import sys

def solve_maze(maze):
    rows = len(maze)
    cols = len(maze[0])
    if rows == 0 or cols == 0:
        return None
    if maze[rows - 1][cols - 1] == 0:
        return None
    if set_way(maze, 1, 1):
        return maze
    return None

def set_way(maze, i, j):
    rows = len(maze)
    cols = len(maze[0])
    if i == rows - 1 and j == cols - 1:
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
    if maze[rows - 1][cols - 1] == 0:
        return None
    if set_way2(maze, 1, 1):
        return maze
    return None

def set_way2(maze, i, j):
    rows = len(maze)
    cols = len(maze[0])
    if i == rows - 1 and j == cols - 1:
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

if __name__ == "__main__":
    rows = int(input())
    cols = int(input())
    maze = []
    for i in range(rows):
        maze.append([int(x) for x in input().split()])
    strategy = int(input())
    if strategy == 1:
        maze = solve_maze(maze)
    elif strategy == 2:
        maze = solve_maze2(maze)
    else:
        print("Invalid strategy choice.")
        sys.exit(0)
    if maze is not None:
        print("Solved maze:")
        for row in maze:
            print(" ".join(str(x) for x in row))
    else:
        print("No solution exists.")
    sys.exit(0)

