
import sys

def main():
    # Read input from stdin
    rows, cols = map(int, sys.stdin.readline().split())
    puzzle = [sys.stdin.readline().strip() for _ in range(rows)]
    word_count = int(sys.stdin.readline().strip())
    words = [sys.stdin.readline().strip() for _ in range(word_count)]

    # Solve the crossword puzzle using given words
    if solve_crossword(puzzle, words):
        print("Solved Crossword:")
        for row in puzzle:
            print(row)
    else:
        print("No solution exists.")

def solve_crossword(puzzle, words):
    # Base case: no more words to place
    if not words:
        return True

    word = words.pop(0)

    # Try placing the word in each possible orientation and position
    for row in range(len(puzzle)):
        for col in range(len(puzzle[0])):
            for vertical in [True, False]:
                # Check if the word can be placed at the current position and orientation
                if is_valid(puzzle, word, row, col, vertical):
                    # Place the word in the puzzle and recursively try to solve the remaining puzzle
                    place_word(puzzle, word, row, col, vertical)
                    if solve_crossword(puzzle, words):
                        return True
                    # Backtrack and remove the word if placement fails or recursion fails
                    remove_word(puzzle, word, row, col, vertical)

    # If no placement was successful, add the word back to the list of words to try
    words.insert(0, word)

    return False

def is_valid(puzzle, word, row, col, vertical):
    # Check each character in the word against the puzzle grid
    for i in range(len(word)):
        if vertical:
            # Check if character can be placed in the next row
            if row + i >= len(puzzle) or (puzzle[row + i][col] != ' ' and puzzle[row + i][col] != word[i]):
                return False
        else:
            # Check if character can be placed in the next column
            if col + i >= len(puzzle[0]) or (puzzle[row][col + i] != ' ' and puzzle[row][col + i] != word[i]):
                return False
    return True

def place_word(puzzle, word, row, col, vertical):
    # Place each character in the word in the puzzle grid
    for i in range(len(word)):
        if vertical:
            puzzle[row + i][col] = word[i]
        else:
            puzzle[row][col + i] = word[i]

def remove_word(puzzle, word, row, col, vertical):
    # Remove each character in the word from the puzzle grid
    for i in range(len(word)):
        if vertical:
            puzzle[row + i][col] = ' '
        else:
            puzzle[row][col + i] = ' '

if __name__ == "__main__":
    main()

