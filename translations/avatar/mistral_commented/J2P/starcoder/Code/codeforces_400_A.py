
import sys

# Method to check if a given string represents a valid solution
def isSolution(columnsCount, x):
    allXs = [True] * columnsCount # Initialize an array to keep track of the presence of 'X' in each column

    # Iterate through the given string and mark the corresponding columns as not having 'X'
    for i in range(12):
        if x[i]!= 'X':
            allXs[i % columnsCount] = False # Update the corresponding column

    # Check if there is any column having 'X'
    for i in range(columnsCount):
        if allXs[i]: # If 'X' is present in this column
            return True # Return true as this is a valid solution

    return False # If no column has 'X', then this is not a valid solution

# Main method
def main():
    t = int(sys.stdin.readline().strip()) # Read the number of test cases

    for i in range(t): # Iterate through each test case
        possibleSolutions = 0 # Initialize the counter for the number of valid solutions
        solutions = "" # Initialize a string builder to store the valid solutions

        s = sys.stdin.readline().strip() # Read the given string

        # Check if the given string represents a valid solution
        if isSolution(12, s):
            solutions += " 1x12" # Add the solution to the string builder
            possibleSolutions += 1 # Increment the counter

        if isSolution(6, s):
            solutions += " 2x6"
            possibleSolutions += 1

        if isSolution(4, s):
            solutions += " 3x4"
            possibleSolutions += 1

        if isSolution(3, s):
            solutions += " 4x3"
            possibleSolutions += 1

        if isSolution(2, s):
            solutions += " 6x2"
            possibleSolutions += 1

        if isSolution(1, s):
            solutions += " 12x1"
            possibleSolutions += 1

        # Write the output
        print(possibleSolutions, solutions) # Write the number of valid solutions and the valid solutions

if __name__ == "__main__":
    main()

