
import sys

def is_solution(columns_count, x):
    all_xs = [True] * columns_count # Initialize an array to keep track of the presence of 'X' in each column
    for i in range(12): # Iterate through the given string and mark the corresponding columns as not having 'X'
        if x[i] != 'X':
            all_xs[i % columns_count] = False # Update the corresponding column
    for i in range(columns_count): # Check if there is any column having 'X'
        if all_xs[i]: # If 'X' is present in this column
            return True # Return true as this is a valid solution
    return False # If no column has 'X', then this is not a valid solution

for line in sys.stdin: # Read input from console
    t = int(line) # Read the number of test cases
    for i in range(t): # Iterate through each test case
        possible_solutions = 0 # Initialize the counter for the number of valid solutions
        solutions = "" # Initialize a string builder to store the valid solutions
        s = sys.stdin.readline() # Read the given string
        if is_solution(12, s): # Check if the given string represents a valid solution
            solutions += " 1x12" # Add the solution to the string builder
            possible_solutions += 1 # Increment the counter
        if is_solution(6, s):
            solutions += " 2x6"
            possible_solutions += 1
        if is_solution(4, s):
            solutions += " 3x4"
            possible_solutions += 1
        if is_solution(3, s):
            solutions += " 4x3"
            possible_solutions += 1
        if is_solution(2, s):
            solutions += " 6x2"
            possible_solutions += 1
        if is_solution(1, s):
            solutions += " 12x1"
            possible_solutions += 1
        # Write the output
        print(possible_solutions, end=" ") # Write the number of valid solutions
        print(solutions) # Write the valid solutions

