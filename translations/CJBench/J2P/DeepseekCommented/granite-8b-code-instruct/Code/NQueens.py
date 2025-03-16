

queens = int(input("Enter the number of queens: ")) # Read the number of queens from the user
arrangements = get_main_arrangements(queens) # Get all possible arrangements
if not arrangements: # Check if there are no arrangements
    print("There is no way to place", queens, "queens on a board of size", queens, "x", queens)
else: # If there are arrangements, print them
    print("Arrangements for placing", queens, "queens:")
    for arrangement in arrangements:
        for row in arrangement:
            print(row) # Print each arrangement
        print() # Print a newline for separation

def get_main_arrangements(board_size):
    arrangements = [] # Initialize the list of arrangements
    get_solution(board_size, arrangements, [0] * board_size, 0) # Call the recursive method to find solutions
    return arrangements # Return the list of arrangements

def get_solution(board_size, solutions, columns, column_index):
    if column_index == board_size: # If all queens are placed
        solution = [] # Create a new solution list
        for i in range(board_size): # Iterate over each row
            row = "" # Create a string for the row
            for j in range(board_size): # Iterate over each column
                row += "Q" if j == columns[i] else "." # Append 'Q' if it's a queen's position, else '.'
            solution.append(row) # Add the row to the solution
        solutions.append(solution) # Add the solution to the list of solutions
        return # Return from the method
    for row_index in range(board_size): # Try to place the queen in each row of the current column
        columns[column_index] = row_index # Place the queen
        if is_placed_correctly(columns, row_index, column_index): # Check if the placement is correct
            get_solution(board_size, solutions, columns, column_index + 1) # Recursively try to place the next queen

def is_placed_correctly(columns, row_index, column_index):
    for i in range(column_index): # Check all previous columns
        diff = abs(columns[i] - row_index) # Calculate the difference in rows
        if diff == 0 or column_index - i == diff: # If the same row or diagonal, return false
            return False
    return True # If no conflicts, return true

