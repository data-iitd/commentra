class Solution:
    def __init__(self, is_found, cells_taken):
        self.is_found = is_found  # Indicates if a solution was found
        self.cells_taken = cells_taken  # 2D array to represent the board and the positions of queens

    def pretty_print(self):
        if not self.is_found:
            print("No solution found.")
            return
        size = len(self.cells_taken)  # Get the size of the board
        for i in range(size):
            for j in range(size):
                print("Q" if self.cells_taken[i][j] else ".", end=" ")
            print()  # Move to the next line after each row


class Main:
    def solve(self, board_size):
        cells_taken = [[False] * board_size for _ in range(board_size)]  # Initialize the board
        is_found = self.check_solution(board_size, cells_taken, 0)  # Start checking for solutions
        return Solution(is_found, cells_taken)  # Return the solution object

    def check_solution(self, size, cells_taken, queens_positioned):
        if not self.is_legal(size, cells_taken):
            return False  # If not legal, return false
        if queens_positioned == size:
            return True  # If all queens are positioned, a solution is found
        for row in range(size):
            for col in range(size):
                if not cells_taken[row][col]:  # If the cell is empty
                    cells_taken[row][col] = True  # Place a queen
                    if self.check_solution(size, cells_taken, queens_positioned + 1):
                        return True  # If a solution is found, return true
                    else:
                        cells_taken[row][col] = False  # Backtrack if no solution found
        return False  # Return false if no valid position is found

    def is_legal(self, size, cells_taken):
        for i in range(size):
            for j in range(size):
                if cells_taken[i][j]:  # If there is a queen in the cell
                    for r in range(1, size):
                        if i + r < size and cells_taken[i + r][j]:
                            return False  # Vertical conflict
                        if i - r >= 0 and cells_taken[i - r][j]:
                            return False  # Vertical conflict
                    for r in range(1, size):
                        if j + r < size and cells_taken[i][j + r]:
                            return False  # Horizontal conflict
                        if j - r >= 0 and cells_taken[i][j - r]:
                            return False  # Horizontal conflict
                    for r in range(1, size):
                        if i + r < size and j + r < size and cells_taken[i + r][j + r]:
                            return False  # Diagonal conflict
                        if i + r < size and j - r >= 0 and cells_taken[i + r][j - r]:
                            return False  # Diagonal conflict
                        if i - r >= 0 and j + r < size and cells_taken[i - r][j + r]:
                            return False  # Diagonal conflict
                        if i - r >= 0 and j - r >= 0 and cells_taken[i - r][j - r]:
                            return False  # Diagonal conflict
        return True  # Return true if no conflicts are found


if __name__ == "__main__":
    board_size = int(input())  # Read the size of the board from input
    eight_queens = Main()  # Create an instance of Main
    solution = eight_queens.solve(board_size)  # Solve the N-Queens problem
    solution.pretty_print()  # Print the solution

# <END-OF-CODE>
