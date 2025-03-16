class CrosswordSolver:
    def __init__(self):
        self.puzzle = []
        self.words = []

    def is_valid(self, word, row, col, vertical):
        for i in range(len(word)):
            if vertical:
                if row + i >= len(self.puzzle) or (self.puzzle[row + i][col] != ' ' and self.puzzle[row + i][col] != word[i]):
                    return False
            else:
                if col + i >= len(self.puzzle[0]) or (self.puzzle[row][col + i] != ' ' and self.puzzle[row][col + i] != word[i]):
                    return False
        return True

    def place_word(self, word, row, col, vertical):
        for i in range(len(word)):
            if vertical:
                self.puzzle[row + i][col] = word[i]
            else:
                self.puzzle[row][col + i] = word[i]

    def remove_word(self, word, row, col, vertical):
        for i in range(len(word)):
            if vertical:
                self.puzzle[row + i][col] = ' '
            else:
                self.puzzle[row][col + i] = ' '

    def solve_crossword(self):
        if not self.words:
            return True

        word = self.words.pop(0)

        for row in range(len(self.puzzle)):
            for col in range(len(self.puzzle[0])):
                for vertical in [True, False]:
                    if self.is_valid(word, row, col, vertical):
                        self.place_word(word, row, col, vertical)
                        if self.solve_crossword():
                            return True
                        self.remove_word(word, row, col, vertical)

        self.words.insert(0, word)
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
    solver.puzzle = puzzle
    solver.words = words

    if solver.solve_crossword():
        print("Solved Crossword:")
        for row in solver.puzzle:
            print(''.join(row))
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
