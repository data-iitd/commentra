from collections import deque

class Cell:
    CHARS = "abcdefgh"  # Character representation for columns

    def __init__(self, x, y):
        self.x = x  # x coordinate
        self.y = y  # y coordinate

    def convert_to_check_mate_coordinate_system(self):
        return f"{self.CHARS[self.x]}{self.y + 1}"  # Convert to chess notation


class Solution:
    def __init__(self, is_found, cells_taken, log):
        self.is_found = is_found  # Indicates if a solution was found
        self.cells_taken = cells_taken  # Tracks which cells have been visited
        self.log = log  # Log of the cells visited in the solution

    def print_log(self):
        if not self.is_found or len(self.log) != len(self.cells_taken) ** 2:
            print("No solution found!")  # No valid solution
            return
        
        board = [[0] * len(self.cells_taken) for _ in range(len(self.cells_taken))]  # Initialize the board
        position_number = 0  # Counter for the position number
        
        # Fill the board with the order of the knight's moves
        for cell in self.log:
            position_number += 1
            board[cell.x][cell.y] = position_number
        
        # Print the board with the knight's move order
        for row in board:
            print("\t".join(map(str, row)))  # Print each cell with a tab space


class Main:
    def solve(self, board_size):
        cells_taken = [[False] * board_size for _ in range(board_size)]  # Track visited cells
        cells_taken[0][0] = True  # Mark the starting cell as visited
        log = deque()  # Log of the knight's moves
        log.append(Cell(0, 0))  # Start from the initial position
        
        # Start the recursive solution check
        is_found = self.check_solution(board_size, cells_taken, 1, 0, 0, log)
        return Solution(is_found, cells_taken, log)  # Return the solution

    def check_solution(self, size, cells_taken, cells_visited, curr_x, curr_y, log):
        # If all cells have been visited, a solution is found
        if cells_visited == size * size:
            return True
        
        # Possible knight moves
        possible_moves = [(-2, -1), (-2, 1), (2, 1), (2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
        
        # Try each possible move
        for move in possible_moves:
            next_x = curr_x + move[0]  # Calculate next x position
            next_y = curr_y + move[1]  # Calculate next y position
            
            # Check if the next position is within bounds and not visited
            if next_x < 0 or next_x >= size or next_y < 0 or next_y >= size:
                continue  # Skip out-of-bounds moves
            if cells_taken[next_x][next_y]:
                continue  # Skip already visited cells
            
            cells_taken[next_x][next_y] = True  # Mark the next cell as visited
            log.append(Cell(next_x, next_y))  # Log the move
            
            # Recursively check for the next move
            if self.check_solution(size, cells_taken, cells_visited + 1, next_x, next_y, log):
                return True  # Solution found
            else:
                log.pop()  # Backtrack if no solution found
                cells_taken[next_x][next_y] = False  # Unmark the cell
        
        return False  # No solution found from this path


if __name__ == "__main__":
    board_size = int(input())  # Read the board size from input
    horse_walk = Main()  # Create an instance of Main
    solution = horse_walk.solve(board_size)  # Solve the knight's tour problem
    solution.print_log()  # Print the solution log

# <END-OF-CODE>
