class MazeSolver:
    def __init__(self):
        pass

    def main(self):
        # Input maze dimensions
        rows = int(input())
        cols = int(input())

        maze = []
        # Input maze grid
        for _ in range(rows):
            maze.append(list(map(int, input().split())))

        # Choose strategy
        strategy = int(input())

        solved_maze = None
        if strategy == 1:
            solved_maze = self.solve_maze_using_first_strategy(maze)
        elif strategy == 2:
            solved_maze = self.solve_maze_using_second_strategy(maze)
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

    def solve_maze_using_first_strategy(self, map):
        if self.set_way(map, 1, 1):
            return map
        return None

    def solve_maze_using_second_strategy(self, map):
        if self.set_way2(map, 1, 1):
            return map
        return None

    def set_way(self, map, i, j):
        if i == len(map) - 2 and j == len(map[0]) - 2:
            map[i][j] = 2
            return True

        if map[i][j] == 0:
            map[i][j] = 2

            # Move down
            if self.set_way(map, i + 1, j):
                return True
            # Move right
            elif self.set_way(map, i, j + 1):
                return True
            # Move up
            elif self.set_way(map, i - 1, j):
                return True
            # Move left
            elif self.set_way(map, i, j - 1):
                return True

            map[i][j] = 3  # Mark as dead end (3) if no direction worked
            return False
        return False

    def set_way2(self, map, i, j):
        if i == len(map) - 2 and j == len(map[0]) - 2:
            map[i][j] = 2
            return True

        if map[i][j] == 0:
            map[i][j] = 2

            # Move up
            if self.set_way2(map, i - 1, j):
                return True
            # Move right
            elif self.set_way2(map, i, j + 1):
                return True
            # Move down
            elif self.set_way2(map, i + 1, j):
                return True
            # Move left
            elif self.set_way2(map, i, j - 1):
                return True

            map[i][j] = 3  # Mark as dead end (3) if no direction worked
            return False
        return False


if __name__ == "__main__":
    solver = MazeSolver()
    solver.main()

# <END-OF-CODE>
