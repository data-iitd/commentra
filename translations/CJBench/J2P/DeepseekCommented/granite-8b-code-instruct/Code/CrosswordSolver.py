
import sys

def is_valid(puzzle, word, row, col, vertical):
    for i in range(len(word)):
        if vertical:
            if row + i >= len(puzzle) or (puzzle[row + i][col]!='' and puzzle[row + i][col]!= word[i]):
                return False
        else:
            if col + i >= len(puzzle[0]) or (puzzle[row][col + i]!='' and puzzle[row][col + i]!= word[i]):
                return False
    return True

def place_word(puzzle, word, row, col, vertical):
    for i in range(len(word)):
        if vertical:
            puzzle[row + i][col] = word[i]
        else:
            puzzle[row][col + i] = word[i]

def remove_word(puzzle, word, row, col, vertical):
    for i in range(len(word)):
        if vertical:
            puzzle[row + i][col] =''
        else:
            puzzle[row][col + i] =''

def solve_crossword(puzzle, words):
    if not words:
        return True
    word = words.pop(0)
    for row in range(len(puzzle)):
        for col in range(len(puzzle[0])):
            for vertical in [True, False]:
                if is_valid(puzzle, word, row, col, vertical):
                    place_word(puzzle, word, row, col, vertical)
                    if solve_crossword(puzzle, words):
                        return True
                    remove_word(puzzle, word, row, col, vertical)
    words.insert(0, word)
    return False

def main():
    rows, cols = map(int, input().split())
    puzzle = []
    for _ in range(rows):
        puzzle.append(list(input()))
    word_count = int(input())
    words = []
    for _ in range(word_count):
        words.append(input())
    if solve_crossword(puzzle, words):
        print("Solved Crossword:")
        for row in puzzle:
            print(''.join(row))
    else:
        print("No solution exists.")

if __name__ == "__main__":
    main()
