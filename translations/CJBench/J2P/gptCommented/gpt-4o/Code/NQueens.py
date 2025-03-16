class Main:
    @staticmethod
    def main():
        # Read the number of queens (and the size of the board)
        queens = int(input("Enter the number of queens: "))
        
        # Get all arrangements for placing the queens on the board
        arrangements = Main.get_main_arrangements(queens)
        
        # Check if there are no arrangements found
        if not arrangements:
            print(f"There is no way to place {queens} queens on a board of size {queens}x{queens}")
        else:
            # Print the arrangements found
            print(f"Arrangements for placing {queens} queens:")
            for arrangement in arrangements:
                for row in arrangement:
                    print(row)  # Print each arrangement
                print()  # Print a blank line between arrangements

    @staticmethod
    def get_main_arrangements(queens):
        arrangements = []  # List to store valid arrangements
        Main.get_solution(queens, arrangements, [0] * queens, 0)  # Start the recursive solution finding
        return arrangements  # Return the list of arrangements found

    @staticmethod
    def get_solution(board_size, solutions, columns, column_index):
        # Base case: if all queens are placed
        if column_index == board_size:
            solution = []  # List to store the current solution
            for i in range(board_size):
                row = ''.join('Q' if j == columns[i] else '.' for j in range(board_size))  # Build each row of the board
                solution.append(row)  # Add the constructed row to the solution
            solutions.append(solution)  # Add the complete solution to the list of solutions
            return  # Exit the method

        # Try placing a queen in each row of the current column
        for row_index in range(board_size):
            columns[column_index] = row_index  # Place queen at the current rowIndex in the current column
            # Check if the placement is valid
            if Main.is_placed_correctly(columns, row_index, column_index):
                # Recursively attempt to place queens in the next column
                Main.get_solution(board_size, solutions, columns, column_index + 1)

    @staticmethod
    def is_placed_correctly(columns, row_index, column_index):
        # Check previous columns for conflicts
        for i in range(column_index):
            diff = abs(columns[i] - row_index)  # Calculate the row difference
            # Check for same row or diagonal conflicts
            if diff == 0 or column_index - i == diff:
                return False  # Placement is not valid
        return True  # Placement is valid


if __name__ == "__main__":
    Main.main()

# <END-OF-CODE>
