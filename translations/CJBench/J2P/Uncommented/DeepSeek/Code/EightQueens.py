import sys

class Solution:
    def __init__(self, is_found, cells_taken):
        self.is_found = is_found
        self.cells_taken = cells_taken

    def pretty_print(self):
        if not self.is_found:
            print("No solution found.")
            return
        size = len(self.cells_taken)
        for i in range(size):
            for j in range(size):
                print('Q' if self.cells_taken[i][j] else '.', end=' ')
            print()

def solve(board_size):
    cells_taken = [[False] * board_size for _ in range(board_size)]
    is_found = check_solution(board_size, cells_taken, 0)
    return Solution(is_found, cells_taken)

def check_solution(size, cells_taken, queens_positioned):
    if not is_legal(size, cells_taken):
        return False
    if queens_positioned == size:
        return True
    for row in range(size):
        for col in range(size):
            if not cells_taken[row][col]:
                cells_taken[row][col] = True
                if check_solution(size, cells_taken, queens_positioned + 1):
                    return True
                else:
                    cells_taken[row][col] = False
    return False

def is_legal(size, cells_taken):
    for i in range(size):
        for j in range(size):
            if cells_taken[i][j]:
                for r in range(1, size):
                    if i + r < size and cells_taken[i + r][j]:
                        return False
                    if i - r >= 0 and cells_taken[i - r][j]:
                        return False
                for r in range(1, size):
                    if j + r < size and cells_taken[i][j + r]:
                        return False
                    if j - r >= 0 and cells_taken[i][j - r]:
                        return False
                for r in range(1, size):
                    if i + r < size and j + r < size and cells_taken[i + r][j + r]:
                        return False
                    if i + r < size and j - r >= 0 and cells_taken[i + r][j - r]:
                        return False
                    if i - r >= 0 and j + r < size and cells_taken[i - r][j + r]:
                        return False
                    if i - r >= 0 and j - r >= 0 and cells_taken[i - r][j - r]:
                        return False
    return True

def main():
    board_size = int(sys.stdin.readline().strip())
    solution = solve(board_size)
    solution.pretty_print()

if __name__ == "__main__":
    main()
