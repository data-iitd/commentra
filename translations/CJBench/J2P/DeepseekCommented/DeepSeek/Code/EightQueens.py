def is_legal(size, cells_taken):
    for i in range(size):
        for j in range(size):
            if cells_taken[i][j]:
                for r in range(1, size):
                    if i + r < size and cells_taken[i + r][j]:  # Check for same column
                        return False
                    if i - r >= 0 and cells_taken[i - r][j]:  # Check for same column
                        return False
                for r in range(1, size):
                    if j + r < size and cells_taken[i][j + r]:  # Check for same row
                        return False
                    if j - r >= 0 and cells_taken[i][j - r]:  # Check for same row
                        return False
                for r in range(1, size):
                    if i + r < size and j + r < size and cells_taken[i + r][j + r]:  # Check for diagonal
                        return False
                    if i + r < size and j - r >= 0 and cells_taken[i + r][j - r]:  # Check for diagonal
                        return False
                    if i - r >= 0 and j + r < size and cells_taken[i - r][j + r]:  # Check for diagonal
                        return False
                    if i - r >= 0 and j - r >= 0 and cells_taken[i - r][j - r]:  # Check for diagonal
                        return False
    return True


def check_solution(size, cells_taken, queens_positioned):
    if not is_legal(size, cells_taken):  # Check if the current state is legal
        return False
    if queens_positioned == size:  # If all queens are positioned, a solution is found
        return True
    for row in range(size):
        for col in range(size):
            if not cells_taken[row][col]:  # Try to place a queen if the cell is empty
                cells_taken[row][col] = True
                if check_solution(size, cells_taken, queens_positioned + 1):  # Recursively check the next position
                    return True
                else:
                    cells_taken[row][col] = False  # Backtrack if placing a queen doesn't lead to a solution
    return False


def solve(board_size):
    cells_taken = [[False] * board_size for _ in range(board_size)]
    is_found = check_solution(board_size, cells_taken, 0)
    return Solution(is_found, cells_taken)


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
                print("Q" if self.cells_taken[i][j] else ".", end=" ")
            print()


def main():
    board_size = int(input())
    solution = solve(board_size)
    solution.pretty_print()


if __name__ == "__main__":
    main()
