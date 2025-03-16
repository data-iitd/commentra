
import sys

# Stores shift values for each character in the pattern
shift_values = {}

# Stores the length of the pattern
pattern_length = 0

# Counter for the number of character comparisons
comparisons = 0

# Finds the first occurrence of the pattern in the text
def find_first(pattern, text):
    return first_occurrence(pattern, text, True)

# Implements the Boyer-Moore algorithm to find the first occurrence
def first_occurrence(pattern, text, case_sensitive):
    global shift_values, pattern_length, comparisons
    shift_values = calc_shift_values(pattern)
    comparisons = 0

    # If the pattern is empty, return -1
    if not pattern:
        return -1

    text_index = pattern_length - 1
    while text_index < len(text):
        i = pattern_length - 1
        while i >= 0:
            comparisons += 1
            pattern_char = pattern[i]
            text_char = text[(text_index + i) - (pattern_length - 1)]
            if not char_equals(pattern_char, text_char, case_sensitive):
                text_index += get_shift_value(text[text_index])
                break
            i -= 1
        if i == -1:
            return text_index - pattern_length + 1
    return -1

# Compares characters, optionally ignoring case sensitivity
def char_equals(c1, c2, case_sensitive):
    return c1 == c2 if case_sensitive else c1.lower() == c2.lower()

# Calculates the shift values for each character in the pattern
def calc_shift_values(pattern):
    global pattern_length
    pattern_length = len(pattern)
    table = {}
    for i in range(pattern_length - 2, -1, -1):
        c = pattern[i]
        table[c] = table.get(c, pattern_length - 1 - i)
    return table

# Retrieves the shift value for a given character
def get_shift_value(c):
    return shift_values.get(c, pattern_length)

# Main method to read input and find the pattern
def main():
    text = sys.stdin.readline().strip()
    pattern = sys.stdin.readline().strip()
    position = find_first(pattern, text)
    if position!= -1:
        print("Pattern found at index: " + str(position))
    else:
        print("Pattern not found.")

if __name__ == "__main__":
    main()

