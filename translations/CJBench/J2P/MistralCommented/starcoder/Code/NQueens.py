
import sys

# Initializes the scanner and reads the number of queens from the user input
def main():
    scanner = sys.stdin
    queens = int(scanner.readline())
    scanner.close()

    # Calls the function to get all possible arrangements for the given number of queens
    arrangements = get_main_arrangements(queens)

    # Checks if there are any arrangements and prints the error message if not
    if (len(arrangements) == 0):
        print("There is no way to place " + str(queens) + " queens on a board of size " + str(queens) + "x" + str(queens))
    else:
        # Prints the header message and the arrangements one by one
        print("Arrangements for placing " + str(queens) + " queens:")
        for arrangement in arrangements:
            for row in arrangement:
                print(row)
            print()

# Recursively calculates all possible arrangements for the given number of queens
def get_main_arrangements(queens):
    arrangements = []
    get_solution(queens, arrangements, [0] * queens, 0)
    return arrangements

# The main recursive function to find all possible arrangements
def get_solution(board_size, solutions, columns, column_index):
    # Base case: if all columns have been filled, add the current arrangement to the list of solutions
    if (column_index == board_size):
        solution = []
        # Creates a new string representation of the arrangement and adds it to the list of solutions
        for i in range(board_size):
            row = ""
            for j in range(board_size):
                row += "Q" if (j == columns[i]) else "."
            solution.append(row)
        solutions.append(solution)
        return

    # Iterates through all possible rows to place a queen
    for row_index in range(board_size):
        columns[column_index] = row_index
        # Checks if the current placement is valid and recursively calls the function if it is
        if (is_placed_correctly(columns, row_index, column_index)):
            get_solution(board_size, solutions, columns, column_index + 1)

# Checks if the current placement of a queen is valid based on the previous placements
def is_placed_correctly(columns, row_index, column_index):
    # Iterates through all previous columns to check if there is a conflict with the current placement
    for i in range(column_index):
        diff = abs(columns[i] - row_index)
        # Checks for two possible conflicts: the queen is placed on the same row or diagonal
        if (diff == 0 or column_index - i == diff):
            return False
    # If no conflicts are found, the placement is valid
    return True

if __name__ == "__main__":
    main()

# 