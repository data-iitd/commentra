
import sys

def find_first(pattern, text):
    shift_values = calc_shift_values(pattern)
    comparisons = 0

    if len(pattern) == 0:
        return -1

    text_index = len(pattern) - 1

    while text_index < len(text):
        i = len(pattern) - 1

        while i >= 0:
            comparisons += 1

            if pattern[i] != text[text_index + i - len(pattern) + 1]:
                text_index += shift_values[text[text_index]]
                break

            i -= 1

        if i == -1:
            return text_index - len(pattern) + 1

        text_index += 1

    return -1

def calc_shift_values(pattern):
    pattern_length = len(pattern)
    table = {}

    for i in range(len(pattern) - 2, -1, -1):
        c = pattern[i]
        table[c] = pattern_length - 1 - i

    return table

def main():
    text = sys.stdin.readline().strip()
    pattern = sys.stdin.readline().strip()
    position = find_first(pattern, text)

    if position != -1:
        print("Pattern found at index:", position)
    else:
        print("Pattern not found.")

if __name__ == "__main__":
    main()

