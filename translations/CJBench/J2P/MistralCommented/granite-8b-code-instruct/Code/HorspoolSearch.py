

def find_first(pattern, text):
    shift_values = calc_shift_values(pattern)
    comparisons = 0

    if not pattern:
        return -1

    text_index = len(pattern) - 1

    while text_index < len(text):
        i = len(pattern) - 1

        while i >= 0:
            comparisons += 1

            pattern_char = pattern[i]
            text_char = text[(text_index + i) - (len(pattern) - 1)]

            if not char_equals(pattern_char, text_char):
                text_index += get_shift_value(text[text_index])
                break

            i -= 1

        if i == -1:
            return text_index - len(pattern) + 1

        text_index += 1

    return -1

def char_equals(c1, c2, case_sensitive):
    return c1 == c2 if case_sensitive else c1.lower() == c2.lower()

def calc_shift_values(pattern):
    global pattern_length
    pattern_length = len(pattern)
    table = {}

    for i in range(len(pattern) - 2, -1, -1):
        c = pattern[i]
        table[c] = table.get(c, pattern_length - 1 - i)

    return table

def get_shift_value(c):
    return shift_values.get(c, pattern_length)

if __name__ == "__main__":
    text = input()
    pattern = input()
    position = find_first(pattern, text)

    if position!= -1:
        print("Pattern found at index:", position)
    else:
        print("Pattern not found.")

