class Main:
    @staticmethod
    def main():
        rows = int(input())
        cols = int(input())
        maze = []
        for _ in range(rows):
            maze.append(list(map(int, input().split())))
        strategy = int(input())
        solved_maze = None
        if strategy == 1:
            solved_maze = Main.solve_maze_using_first_strategy(maze)
        elif strategy == 2:
            solved_maze = Main.solve_maze_using_second_strategy(maze)
        else:
            print("Invalid strategy choice.")
            return
        if solved_maze is not None:
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

if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
