import sys

# Method to check if a given string can form a solution for a specific column count
def isSolution(columnsCount, x):
    # Create an array to track if all positions for each column are 'X'
    allXs = [True] * columnsCount

    # Check each character in the string
    for i in range(12):
        # If the character is not 'X', mark the corresponding column as false
        if x[i]!= 'X':
            allXs[i % columnsCount] = False

    # Check if any column has all 'X's
    for i in range(columnsCount):
        if allXs[i]:
            return True

    return False

# Main function
def main():
    # Read the number of test cases
    t = int(sys.stdin.readline())

    # Process each test case
    for i in range(t):
        possibleSolutions = 0 # Counter for possible solutions
        solutions = "" # To store the solutions
        s = sys.stdin.readline() # Read the input string

        # Check for various column configurations and append valid solutions
        if isSolution(12, s):
            solutions += " 1x12"
            possibleSolutions += 1
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

        # Output the number of possible solutions and the solutions themselves
        print(possibleSolutions)
        print(solutions)

# Start the execution if it's the main script
if __name__ == "__main__":
    main()

# 