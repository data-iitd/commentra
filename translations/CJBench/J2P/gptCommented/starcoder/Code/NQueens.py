import sys

# Private class to prevent instantiation
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Main method
    def main(self):
        # Read the number of queens (and the size of the board)
        queens = int(sys.stdin.readline())

        # Get all arrangements for placing the queens on the board
        arrangements = self.getMainArrangements(queens)

        # Check if there are no arrangements found
        if (arrangements.isEmpty()):
            print("There is no way to place " + queens + " queens on a board of size " + queens + "x" + queens)
        else:
            # Print the arrangements found
            print("Arrangements for placing " + queens + " queens:")
            for arrangement in arrangements:
                arrangement.forEach(print) # Print each arrangement
                print() # Print a blank line between arrangements

    # Method to get all main arrangements of queens on the board
    def getMainArrangements(self, queens):
        arrangements = [] # List to store valid arrangements
        self.getSolution(queens, arrangements, [0] * queens, 0) # Start the recursive solution finding
        return arrangements # Return the list of arrangements found

    # Recursive method to find all solutions for placing queens on the board
    def getSolution(self, boardSize, solutions, columns, columnIndex):
        # Base case: if all queens are placed
        if (columnIndex == boardSize):
            solution = [] # List to store the current solution
            for i in range(boardSize):
                row = "" # Build each row of the board
                for j in range(boardSize):
                    # Place 'Q' for queen and '.' for empty space
                    row += "Q" if (j == columns[i]) else "."
                solution.append(row) # Add the constructed row to the solution
            solutions.append(solution) # Add the complete solution to the list of solutions
            return # Exit the method

        # Try placing a queen in each row of the current column
        for rowIndex in range(boardSize):
            columns[columnIndex] = rowIndex # Place queen at the current rowIndex in the current column
            # Check if the placement is valid
            if (self.isPlacedCorrectly(columns, rowIndex, columnIndex)):
                # Recursively attempt to place queens in the next column
                self.getSolution(boardSize, solutions, columns, columnIndex + 1)

    # Method to check if the queen can be placed in the current position
    def isPlacedCorrectly(self, columns, rowIndex, columnIndex):
        # Check previous columns for conflicts
        for i in range(columnIndex):
            diff = abs(columns[i] - rowIndex) # Calculate the row difference
            # Check for same row or diagonal conflicts
            if (diff == 0 or columnIndex - i == diff):
                return False # Placement is not valid
        return True # Placement is valid

# Main function
if __name__ == "__main__":
    Main().main()

# 