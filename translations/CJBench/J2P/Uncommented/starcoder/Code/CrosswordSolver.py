import sys
import copy

def isValid(puzzle, word, row, col, vertical):
    for i in range(len(word)):
        if vertical:
            if row + i >= len(puzzle) or (puzzle[row + i][col]!='' and puzzle[row + i][col]!= word[i]):
                return False
        else:
            if col + i >= len(puzzle[0]) or (puzzle[row][col + i]!='' and puzzle[row][col + i]!= word[i]):
                return False
    return True

def placeWord(puzzle, word, row, col, vertical):
    for i in range(len(word)):
        if vertical:
            puzzle[row + i][col] = word[i]
        else:
            puzzle[row][col + i] = word[i]

def removeWord(puzzle, word, row, col, vertical):
    for i in range(len(word)):
        if vertical:
            puzzle[row + i][col] =''
        else:
            puzzle[row][col + i] =''

def solveCrossword(puzzle, words):
    if len(words) == 0:
        return True
    word = words.pop(0)
    for row in range(len(puzzle)):
        for col in range(len(puzzle[0])):
            for vertical in [True, False]:
                if isValid(puzzle, word, row, col, vertical):
                    placeWord(puzzle, word, row, col, vertical)
                    if solveCrossword(puzzle, words):
                        return True
                    removeWord(puzzle, word, row, col, vertical)
    words.insert(0, word)
    return False

if __name__ == "__main__":
    puzzle = []
    for line in sys.stdin:
        puzzle.append(list(line.strip()))
    words = []
    for line in sys.stdin:
        words.append(line.strip())
    if solveCrossword(puzzle, words):
        print("Solved Crossword:")
        for row in puzzle:
            print("".join(row))
    else:
        print("No solution exists.")

