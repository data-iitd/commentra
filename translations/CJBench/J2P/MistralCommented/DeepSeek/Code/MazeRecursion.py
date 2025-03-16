class Main:
    def __init__(self):
        pass

    @staticmethod
    def main(args):
        scanner = Scanner()
        rows = scanner.nextInt()
        cols = scanner.nextInt()
        maze = [[0] * cols for _ in range(rows)]

        for i in range(rows):
            for j in range(cols):
                maze[i][j] = scanner.nextInt()

        strategy = scanner.nextInt()
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

class Scanner:
    def __init__(self):
        self.inputs = []
        self.index = 0

    def nextInt(self):
        value = int(self.inputs[self.index])
        self.index += 1
        return value

    def read_inputs(self, inputs):
        self.inputs = inputs.split()
        self.index = 0

# Example usage:
# scanner = Scanner()
# scanner.read_inputs("3 3 1 0 1 1 0 0 0 1 1 1 0 0 0 1 2")
# Main.main([])
