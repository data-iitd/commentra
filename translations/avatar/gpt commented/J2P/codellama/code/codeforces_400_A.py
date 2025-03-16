
import sys 

def isSolution(columnsCount, x): 
    # Create an array to track if all positions for each column are 'X'
    allXs = [True] * columnsCount 

    # Check each character in the string
    for i in range(12): 
        # If the character is not 'X', mark the corresponding column as false
        if x[i] != 'X': 
            allXs[i % columnsCount] = False 

    # Check if any column has all 'X's
    for i in range(columnsCount): 
        if allXs[i]: 
            return True 

    return False 

def main(): 
    # Read the number of test cases
    t = int(sys.stdin.readline()) 

    # Process each test case
    for i in range(t): 
        possibleSolutions = 0 
        solutions = "" 
        s = sys.stdin.readline() 

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
        print(possibleSolutions, solutions) 

if __name__ == "__main__": 
    main() 

