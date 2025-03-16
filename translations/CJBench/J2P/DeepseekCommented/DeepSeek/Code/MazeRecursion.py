class Main:
    def __init__(self):
        pass

    @staticmethod
    def main(args):
        # Read the dimensions of the maze
        import sys
        input = sys.stdin.readline
        rows, cols = map(int, input().split())
        maze = [[0] * cols for _ in range(rows)]
        
        # Populate the maze array with values provided by the user
        for i in range(rows):
            maze[i] = list(map(int, input().split()))
        
        # Prompt the user to choose a strategy for solving the maze
        strategy = int(input())
        solved_maze = None
        
        # Solve the maze using the chosen strategy
        if strategy == 1:
            solved_maze = Main.solve_maze_using_first_strategy(maze)
        elif strategy == 2:
            solved_maze = Main.solve_maze_using_second_strategy(maze)
        else:
            print("Invalid strategy choice.")
            return
        
        # Output the solved maze or a message indicating no solution exists
        if solved_maze:
            print("Solved maze:")
            for row in solved_maze:
                print(" ".join(map(str, row)))
        else:
            print("No solution exists.")

    @staticmethod
    def solve_maze_using_first_strategy(map):
        if Main.set_way(map, 1, 1):
            return map
        return None

    @staticmethod
    def solve_maze_using_second_strategy(map):
        if Main.set_way2(map, 1, 1):
            return map
        return None

    @staticmethod
    def set_way(map, i, j):
        if i == len(map) - 2 and j == len(map[0]) - 2:
            map[i][j] = 2
            return True
        if map[i][j] == 0:
            map[i][j] = 2
            if Main.set_way(map, i + 1, j):
                return True
            elif Main.set_way(map, i, j + 1):
                return True
            elif Main.set_way(map, i - 1, j):
                return True
            elif Main.set_way(map, i, j - 1):
                return True
            map[i][j] = 3
            return False
        return False

    @staticmethod
    def set_way2(map, i, j):
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

Main.main([])
