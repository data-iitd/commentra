import sys

# Method to check if a word can be placed in the puzzle at a given position
def isValid(puzzle, word, row, col, vertical):
    for i in range(len(word)):
        # Check if placing the word vertically
        if vertical:
            # Check if the position is within bounds and either empty or matches the word
            if row + i >= len(puzzle) or (puzzle[row + i][col]!='' and puzzle[row + i][col]!= word[i]):
                return False # Invalid position
        else:
            # Check if placing the word horizontally
            if col + i >= len(puzzle[0]) or (puzzle[row][col + i]!='' and puzzle[row][col + i]!= word[i]):
                return False # Invalid position
    return True # Valid position

# Method to place a word in the puzzle at a given position
def placeWord(puzzle, word, row, col, vertical):
    for i in range(len(word)):
        # Place the word vertically
        if vertical:
            puzzle[row + i][col] = word[i]
        else:
            # Place the word horizontally
            puzzle[row][col + i] = word[i]

# Method to remove a word from the puzzle at a given position
def removeWord(puzzle, word, row, col, vertical):
    for i in range(len(word)):
        # Remove the word vertically
        if vertical:
            puzzle[row + i][col] =''
        else:
            # Remove the word horizontally
            puzzle[row][col + i] =''

# Method to solve the crossword puzzle using backtracking
def solveCrossword(puzzle, words):
    # Base case: if no words left to place, the puzzle is solved
    if len(words) == 0:
        return True
    # Remove the first word from the list to try placing it
    word = words.pop(0)
    # Iterate through each cell in the puzzle
    for row in range(len(puzzle)):
        for col in range(len(puzzle[0])):
            # Try placing the word both vertically and horizontally
            for vertical in [True, False]:
                # Check if the word can be placed
                if isValid(puzzle, word, row, col, vertical):
                    # Place the word in the puzzle
                    placeWord(puzzle, word, row, col, vertical)
                    # Recursively attempt to solve the rest of the puzzle
                    if solveCrossword(puzzle, words):
                        return True # Puzzle solved
                    # If not solved, remove the word and try the next position
                    removeWord(puzzle, word, row, col, vertical)
    # If the word cannot be placed, add it back to the list and return false
    words.insert(0, word)
    return False # No solution found

if __name__ == "__main__":
    # Initialize scanner for user input
    scanner = sys.stdin
    # Read the dimensions of the puzzle
    rows = int(scanner.readline())
    cols = int(scanner.readline())
    # Create the puzzle grid
    puzzle = [[''for j in range(cols)] for i in range(rows)]
    # Read the puzzle input from the user
    for i in range(rows):
        line = scanner.readline()
        for j in range(cols):
            puzzle[i][j] = line[j] # Fill the puzzle grid
    # Read the number of words to place in the puzzle
    wordCount = int(scanner.readline())
    # Read each word from the user
    words = []
    for i in range(wordCount):
        words.append(scanner.readline())
    # Attempt to solve the crossword puzzle
    if solveCrossword(puzzle, words):
        # If solved, print the completed puzzle
        print("Solved Crossword:")
        for row in puzzle:
            print("".join(row))
    else:
        # If no solution exists, inform the user
        print("No solution exists.")
    # Close the scanner to prevent resource leaks
    scanner.close()

