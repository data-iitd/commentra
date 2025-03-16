import sys

# A class to solve a crossword puzzle using backtracking with dynamic input.
class Main:

    # Checks if a word can be placed at the specified position in the crossword.
    def isValid(self, puzzle, word, row, col, vertical):
        for i in range(0, len(word)):
            if vertical:
                if row + i >= len(puzzle) or (puzzle[row + i][col]!='' and puzzle[row + i][col]!= word[i]):
                    return False
            else:
                if col + i >= len(puzzle[0]) or (puzzle[row][col + i]!='' and puzzle[row][col + i]!= word[i]):
                    return False
        return True

    # Places a word at the specified position in the crossword.
    def placeWord(self, puzzle, word, row, col, vertical):
        for i in range(0, len(word)):
            if vertical:
                puzzle[row + i][col] = word[i]
            else:
                puzzle[row][col + i] = word[i]

    # Removes a word from the specified position in the crossword.
    def removeWord(self, puzzle, word, row, col, vertical):
        for i in range(0, len(word)):
            if vertical:
                puzzle[row + i][col] =''
            else:
                puzzle[row][col + i] =''

    # Solves the crossword puzzle using backtracking.
    def solveCrossword(self, puzzle, words):
        if len(words) == 0:
            return True # All words placed successfully

        word = words.pop(0) # Take the first word from the list
        for row in range(0, len(puzzle)):
            for col in range(0, len(puzzle[0])):
                for vertical in [True, False]:
                    if self.isValid(puzzle, word, row, col, vertical):
                        self.placeWord(puzzle, word, row, col, vertical)
                        if self.solveCrossword(puzzle, words):
                            return True
                        self.removeWord(puzzle, word, row, col, vertical)
        words.insert(0, word) # Backtrack by adding the word back to the list
        return False

    # Main method to take input dynamically and solve the crossword puzzle.
    def main(self):
        rows = int(sys.stdin.readline().strip())
        cols = int(sys.stdin.readline().strip())
        puzzle = []
        for i in range(0, rows):
            puzzle.append(sys.stdin.readline().strip().replace(' ', ''))

        wordCount = int(sys.stdin.readline().strip())
        words = []
        for i in range(0, wordCount):
            words.append(sys.stdin.readline().strip())

        if self.solveCrossword(puzzle, words):
            print("Solved Crossword:")
            for row in puzzle:
                print(row)
        else:
            print("No solution exists.")

# 