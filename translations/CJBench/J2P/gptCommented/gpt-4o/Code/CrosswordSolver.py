class CrosswordSolver:
    # Method to check if a word can be placed in the puzzle at a given position
    @staticmethod
    def is_valid(puzzle, word, row, col, vertical):
        for i in range(len(word)):
            # Check if placing the word vertically
            if vertical:
                # Check if the position is within bounds and either empty or matches the word
                if row + i >= len(puzzle) or (puzzle[row + i][col] != ' ' and puzzle[row + i][col] != word[i]):
                    return False  # Invalid position
            else:
                # Check if placing the word horizontally
                if col + i >= len(puzzle[0]) or (puzzle[row][col + i] != ' ' and puzzle[row][col + i] != word[i]):
                    return False  # Invalid position
        return True  # Valid position

    # Method to place a word in the puzzle at a given position
    @staticmethod
    def place_word(puzzle, word, row, col, vertical):
        for i in range(len(word)):
            # Place the word vertically
            if vertical:
                puzzle[row + i][col] = word[i]
            else:
                # Place the word horizontally
                puzzle[row][col + i] = word[i]

    # Method to remove a word from the puzzle at a given position
    @staticmethod
    def remove_word(puzzle, word, row, col, vertical):
        for i in range(len(word)):
            # Remove the word vertically
            if vertical:
                puzzle[row + i][col] = ' '
            else:
                # Remove the word horizontally
                puzzle[row][col + i] = ' '

    # Method to solve the crossword puzzle using backtracking
    @staticmethod
    def solve_crossword(puzzle, words):
        # Base case: if no words left to place, the puzzle is solved
        if not words:
            return True
        # Remove the first word from the list to try placing it
        word = words.pop(0)
        # Iterate through each cell in the puzzle
        for row in range(len(puzzle)):
            for col in range(len(puzzle[0])):
                # Try placing the word both vertically and horizontally
                for vertical in [True, False]:
                    # Check if the word can be placed
                    if CrosswordSolver.is_valid(puzzle, word, row, col, vertical):
                        # Place the word in the puzzle
                        CrosswordSolver.place_word(puzzle, word, row, col, vertical)
                        # Recursively attempt to solve the rest of the puzzle
                        if CrosswordSolver.solve_crossword(puzzle, words):
                            return True  # Puzzle solved
                        # If not solved, remove the word and try the next position
                        CrosswordSolver.remove_word(puzzle, word, row, col, vertical)
        # If the word cannot be placed, add it back to the list and return false
        words.insert(0, word)
        return False  # No solution found

def main():
    # Initialize input for user
    rows, cols = map(int, input().split())
    # Create the puzzle grid
    puzzle = [list(input().strip()) for _ in range(rows)]
    # Read the number of words to place in the puzzle
    word_count = int(input())
    words = [input().strip() for _ in range(word_count)]
    # Attempt to solve the crossword puzzle
    if CrosswordSolver.solve_crossword(puzzle, words):
        # If solved, print the completed puzzle
        print("Solved Crossword:")
        for row in puzzle:
            print(''.join(row))
    else:
        # If no solution exists, inform the user
        print("No solution exists.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
