from collections import deque

class Cell:
    CHARS = "abcdefgh"

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def convert_to_checkmate_coordinate_system(self):
        return f"{self.CHARS[self.x]}{self.y + 1}"

class Solution:
    def __init__(self, is_found, cells_taken, log):
        self.is_found = is_found
        self.cells_taken = cells_taken
        self.log = log

    def print_log(self):
        if not self.is_found or len(self.log) != len(self.cells_taken) ** 2:
            print("No solution found!")
            return

        board = [[0] * len(self.cells_taken) for _ in range(len(self.cells_taken))]
        position_number = 0
        for cell in self.log:
            position_number += 1
            board[cell.x][cell.y] = position_number

        for row in board:
            print("\t".join(map(str, row)))

class Main:
    def solve(self, board_size):
        cells_taken = [[False] * board_size for _ in range(board_size)]
        cells_taken[0][0] = True

        log = deque()
        log.append(Cell(0, 0))

        is_found = self.check_solution(board_size, cells_taken, 1, 0, 0, log)

        return Solution(is_found, cells_taken, log)

    def check_solution(self, size, cells_taken, cells_visited, curr_x, curr_y, log):
        if cells_visited == size * size:
            return True

        possible_moves = [(-2, -1), (-2, 1), (2, 1), (2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
        for move in possible_moves:
            next_x = curr_x + move[0]
            next_y = curr_y + move[1]
            if next_x < 0 or next_x >= size or next_y < 0 or next_y >= size:
                continue

            if cells_taken[next_x][next_y]:
                continue

            cells_taken[next_x][next_y] = True
            log.append(Cell(next_x, next_y))
            if self.check_solution(size, cells_taken, cells_visited + 1, next_x, next_y, log):
                return True
            else:
                log.pop()
                cells_taken[next_x][next_y] = False
        return False

if __name__ == "__main__":
    board_size = int(input())
    horse_walk = Main()
    solution = horse_walk.solve(board_size)
    solution.print_log()

# <END-OF-CODE>
