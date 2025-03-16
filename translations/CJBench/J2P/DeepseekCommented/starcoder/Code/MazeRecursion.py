import sys

def solveMazeUsingFirstStrategy(map):
    if setWay(map, 1, 1):
        return map
    return None

def solveMazeUsingSecondStrategy(map):
    if setWay2(map, 1, 1):
        return map
    return None

def setWay(map, i, j):
    if i == len(map) - 2 and j == len(map[0]) - 2:
        map[i][j] = 2
        return True
    if map[i][j] == 0:
        map[i][j] = 2
        if setWay(map, i + 1, j):
            return True
        elif setWay(map, i, j + 1):
            return True
        elif setWay(map, i - 1, j):
            return True
        elif setWay(map, i, j - 1):
            return True
        map[i][j] = 3
        return False
    return False

def setWay2(map, i, j):
    if i == len(map) - 2 and j == len(map[0]) - 2:
        map[i][j] = 2
        return True
    if map[i][j] == 0:
        map[i][j] = 2
        if setWay2(map, i - 1, j):
            return True
        elif setWay2(map, i, j + 1):
            return True
        elif setWay2(map, i + 1, j):
            return True
        elif setWay2(map, i, j - 1):
            return True
        map[i][j] = 3
        return False
    return False

def main():
    # Read the dimensions of the maze
    rows, cols = map(int, sys.stdin.readline().split())
    map = []
    for i in range(rows):
        map.append(list(map(int, sys.stdin.readline().split())))
    
    # Prompt the user to choose a strategy for solving the maze
    strategy = int(sys.stdin.readline())
    
    # Solve the maze using the chosen strategy
    if strategy == 1:
        solvedMaze = solveMazeUsingFirstStrategy(map)
    elif strategy == 2:
        solvedMaze = solveMazeUsingSecondStrategy(map)
    else:
        print("Invalid strategy choice.")
        return
    
    # Output the solved maze or a message indicating no solution exists
    if solvedMaze!= None:
        print("Solved maze:")
        for row in solvedMaze:
            for cell in row:
                print(cell, end=" ")
            print()
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

# 