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
            pattern_char = pattern[i]
            text_char = text[(text_index + i) - (len(pattern) - 1)]
            if not char_equals(pattern_char, text_char):
                text_index += shift_values.get(text[text_index], len(pattern))
                break
            i -= 1
        if i == -1:
            return text_index - len(pattern) + 1
    return -1

def char_equals(c1, c2):
    return c1 == c2

def calc_shift_values(pattern):
    pattern_length = len(pattern)
    table = {}
    for i in range(len(pattern) - 2, -1, -1):
        c = pattern[i]
        table[c] = pattern_length - 1 - i
    return table

def get_shift_value(c):
    return shift_values.get(c, pattern_length)

if __name__ == "__main__":
    text = sys.stdin.readline().strip()
    pattern = sys.stdin.readline().strip()
    position = find_first(pattern, text)
    if position != -1:
        print("Pattern found at index: " + str(position))
    else:
        print("Pattern not found.")

# 