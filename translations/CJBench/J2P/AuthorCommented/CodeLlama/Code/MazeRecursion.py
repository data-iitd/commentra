
import sys

# Input maze dimensions
rows = int(input())
cols = int(input())

# Input maze grid
maze = []
for i in range(rows):
    maze.append([int(x) for x in input().split()])

# Choose strategy
strategy = int(input())

# Solve maze
if strategy == 1:
    solved_maze = solve_maze_using_first_strategy(maze)
elif strategy == 2:
    solved_maze = solve_maze_using_second_strategy(maze)
else:
    print("Invalid strategy choice.")
    sys.exit()

# Output the result
if solved_maze is not None:
    print("Solved maze:")
    for row in solved_maze:
        print(" ".join(str(x) for x in row))
else:
    print("No solution exists.")

# END-OF-CODE
