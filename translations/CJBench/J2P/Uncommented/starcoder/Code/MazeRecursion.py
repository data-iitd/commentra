
import sys
import copy

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
    map = []
    for line in sys.stdin:
        map.append([int(x) for x in line.split()])
    strategy = int(input())
    if strategy == 1:
        solvedMap = solveMazeUsingFirstStrategy(copy.deepcopy(map))
    elif strategy == 2:
        solvedMap = solveMazeUsingSecondStrategy(copy.deepcopy(map))
    else:
        print("Invalid strategy choice.")
        return
    if solvedMap!= None:
        print("Solved maze:")
        for row in solvedMap:
            for cell in row:
                print(cell, end=" ")
            print()
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

# 