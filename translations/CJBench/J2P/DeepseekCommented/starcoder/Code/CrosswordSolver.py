import sys

# Checks if a word can be placed in the puzzle at a given position without overlapping or going out of bounds.
def isValid(puzzle, word, row, col, vertical):
    for i in range(0, len(word)):
        if vertical:
            if row + i >= len(puzzle) or (puzzle[row + i][col]!='' and puzzle[row + i][col]!= word[i]):
                return False
        else:
            if col + i >= len(puzzle[0]) or (puzzle[row][col + i]!='' and puzzle[row][col + i]!= word[i]):
                return False
    return True

# Places a word in the puzzle at a specified position.
def placeWord(puzzle, word, row, col, vertical):
    for i in range(0, len(word)):
        if vertical:
            puzzle[row + i][col] = word[i]
        else:
            puzzle[row][col + i] = word[i]

# Removes a word from the puzzle, restoring the original state.
def removeWord(puzzle, word, row, col, vertical):
    for i in range(0, len(word)):
        if vertical:
            puzzle[row + i][col] =''
        else:
            puzzle[row][col + i] =''

# Attempts to solve the crossword puzzle by placing words one by one.
def solveCrossword(puzzle, words):
    if len(words) == 0:
        return True
    word = words.pop(0)
    for row in range(0, len(puzzle)):
        for col in range(0, len(puzzle[0])):
            for vertical in [True, False]:
                if isValid(puzzle, word, row, col, vertical):
                    placeWord(puzzle, word, row, col, vertical)
                    if solveCrossword(puzzle, words):
                        return True
                    removeWord(puzzle, word, row, col, vertical)
    words.insert(0, word)
    return False

# The entry point of the program where the puzzle is read from the user, the crossword is solved, and the result is printed.
def main():
    rows = int(sys.stdin.readline())
    cols = int(sys.stdin.readline())
    puzzle = []
    for i in range(0, rows):
        puzzle.append(list(sys.stdin.readline().strip()))
    wordCount = int(sys.stdin.readline())
    words = []
    for i in range(0, wordCount):
        words.append(sys.stdin.readline().strip())
    if solveCrossword(puzzle, words):
        print("Solved Crossword:")
        for row in puzzle:
            print(''.join(row))
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

