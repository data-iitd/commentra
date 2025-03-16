
import sys

# Define a Cell class to represent a cell on the board
class Cell:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Method to convert a Cell to its coordinate in the checkmate coordinate system
    def convert_to_check_mate_coordinate_system(self):
        return f"{chr(ord('a') + self.x)}{self.y + 1}"

# Define a Solution class to store the solution and its log
class Solution:
    def __init__(self, is_found, cells_taken, log):
        self.is_found = is_found
        self.cells_taken = cells_taken
        self.log = log

    # Method to print the solution log
    def print_log(self):
        if not self.is_found or len(self.log) != len(self.cells_taken) * len(self.cells_taken):
            print("No solution found!")
            return
        board = [[0] * len(self.cells_taken) for _ in range(len(self.cells_taken))]
        position_number = 0
        for cell in self.log:
            position_number += 1
            board[cell.x][cell.y] = position_number
        for row in board:
            for cell in row:
                print(cell, end="\t")
            print()

# Main method to solve the problem and print the solution
def main():
    board_size = int(sys.stdin.readline().strip())
    solution = solve(board_size)
    solution.print_log()

# Method to solve the problem and find a solution
def solve(board_size):
    cells_taken = [[False] * board_size for _ in range(board_size)]
    cells_taken[0][0] = True
    log = [Cell(0, 0)]
    is_found = check_solution(board_size, cells_taken, 1, 0, 0, log)
    return Solution(is_found, cells_taken, log)

# Recursive method to check if a solution exists
def check_solution(size, cells_taken, cells_visited, curr_x, curr_y, log):
    if cells_visited == size * size:
        # Base case: if all cells have been visited, a solution has been found
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
        if check_solution(size, cells_taken, cells_visited + 1, next_x, next_y, log):
            # Recursive call: if a solution is found, return true
            return True
        else:
            log.pop()
            cells_taken[next_x][next_y] = False
    # If no solution is found, return false
    return False

if __name__ == "__main__":
    main()

