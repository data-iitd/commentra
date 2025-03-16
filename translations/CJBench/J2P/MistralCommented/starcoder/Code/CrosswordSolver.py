
import sys

# Main method to start the program
def main():
    # Read number of rows from input
    rows = int(sys.stdin.readline())
    # Read number of columns from input
    cols = int(sys.stdin.readline())
    # Consume newline character left after reading integers
    sys.stdin.readline()

    puzzle = [] # Initialize 2D char array to represent the crossword puzzle

    # Read puzzle data from input
    for i in range(rows):
        line = sys.stdin.readline().strip()
        puzzle.append(list(line))

    # Read number of words to be placed in the puzzle from input
    wordCount = int(sys.stdin.readline())
    # Consume newline character left after reading integer
    sys.stdin.readline()

    words = [] # Initialize ArrayList to store words to be placed in the puzzle

    # Read words to be placed in the puzzle from input
    for i in range(wordCount):
        words.append(sys.stdin.readline().strip())

    # Solve the crossword puzzle using given words
    if solveCrossword(puzzle, words):
        # Print solved crossword puzzle
        for row in puzzle:
            print(''.join(row))
    else:
        print('No solution exists.') # Print message if no solution exists

# Method to check if a given word can be placed in the puzzle at a given position and orientation
def isValid(puzzle, word, row, col, vertical):
    # Check each character in the word against the puzzle grid
    for i in range(len(word)):
        if vertical:
            # Check if character can be placed in the next row
            if row + i >= len(puzzle) or (puzzle[row + i][col]!='' and puzzle[row + i][col]!= word[i]):
                return False
        else:
            # Check if character can be placed in the next column
            if col + i >= len(puzzle[0]) or (puzzle[row][col + i]!='' and puzzle[row][col + i]!= word[i]):
                return False
    return True

# Method to place a given word in the puzzle at a given position and orientation
def placeWord(puzzle, word, row, col, vertical):
    # Place each character in the word in the puzzle grid
    for i in range(len(word)):
        if vertical:
            puzzle[row + i][col] = word[i]
        else:
            puzzle[row][col + i] = word[i]

# Method to remove a given word from the puzzle at a given position and orientation
def removeWord(puzzle, word, row, col, vertical):
    # Remove each character in the word from the puzzle grid
    for i in range(len(word)):
        if vertical:
            puzzle[row + i][col] =''
        else:
            puzzle[row][col + i] =''

# Recursive method to solve the crossword puzzle using given words
def solveCrossword(puzzle, words):
    # Base case: no more words to place
    if len(words) == 0:
        return True

    word = words.pop(0) # Get the next word to place

    # Try placing the word in each possible orientation and position
    for row in range(len(puzzle)):
        for col in range(len(puzzle[0])):
            for vertical in [True, False]:
                # Check if the word can be placed at the current position and orientation
                if isValid(puzzle, word, row, col, vertical):
                    # Place the word in the puzzle and recursively try to solve the remaining puzzle
                    placeWord(puzzle, word, row, col, vertical)
                    if solveCrossword(puzzle, words):
                        return True
                    # Backtrack and remove the word if placement fails or recursion fails
                    removeWord(puzzle, word, row, col, vertical)

    # If no placement was successful, add the word back to the list of words to try
    words.insert(0, word)

    return False

if __name__ == '__main__':
    main()

