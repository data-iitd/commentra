class CrosswordSolver:
    def is_valid(self, puzzle, word, row, col, vertical):
        for i in range(len(word)):
            if vertical:
                if row + i >= len(puzzle) or (puzzle[row + i][col] != ' ' and puzzle[row + i][col] != word[i]):
                    return False
            else:
                if col + i >= len(puzzle[0]) or (puzzle[row][col + i] != ' ' and puzzle[row][col + i] != word[i]):
                    return False
        return True

    def place_word(self, puzzle, word, row, col, vertical):
        for i in range(len(word)):
            if vertical:
                puzzle[row + i][col] = word[i]
            else:
                puzzle[row][col + i] = word[i]

    def remove_word(self, puzzle, word, row, col, vertical):
        for i in range(len(word)):
            if vertical:
                puzzle[row + i][col] = ' '
            else:
                puzzle[row][col + i] = ' '

    def solve_crossword(self, puzzle, words):
        if not words:
            return True  # All words placed successfully

        word = words.pop(0)  # Take the first word from the list
        for row in range(len(puzzle)):
            for col in range(len(puzzle[0])):
                for vertical in [True, False]:
                    if self.is_valid(puzzle, word, row, col, vertical):
                        self.place_word(puzzle, word, row, col, vertical)
                        if self.solve_crossword(puzzle, words):
                            return True
                        self.remove_word(puzzle, word, row, col, vertical)
        words.insert(0, word)  # Backtrack by adding the word back to the list
        return False

def main():
    import sys

    input = sys.stdin.read
    data = input().splitlines()
    
    rows, cols = map(int, data[0].split())
    puzzle = [list(data[i + 1]) for i in range(rows)]

    word_count = int(data[rows + 1])
    words = [data[rows + 2 + i] for i in range(word_count)]

    solver = CrosswordSolver()
    if solver.solve_crossword(puzzle, words):
        print("Solved Crossword:")
        for row in puzzle:
            print(''.join(row))
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
