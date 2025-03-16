class Horspool:
    def __init__(self):
        self.shift_values = {}  # bad symbol table
        self.pattern_length = 0
        self.comparisons = 0  # total comparisons in the current/last search

    def find_first(self, pattern, text):
        return self.first_occurrence(pattern, text, True)

    def first_occurrence(self, pattern, text, case_sensitive):
        self.shift_values = self.calc_shift_values(pattern)
        self.comparisons = 0

        if not pattern:
            return -1

        text_index = len(pattern) - 1

        while text_index < len(text):
            i = len(pattern) - 1
            while i >= 0:
                self.comparisons += 1
                pattern_char = pattern[i]
                text_char = text[text_index + i - (len(pattern) - 1)]
                if not self.char_equals(pattern_char, text_char, case_sensitive):
                    text_index += self.get_shift_value(text[text_index])
                    break
                i -= 1

            if i == -1:
                return text_index - len(pattern) + 1

        return -1

    def char_equals(self, c1, c2, case_sensitive):
        return c1 == c2 if case_sensitive else c1.lower() == c2.lower()

    def calc_shift_values(self, pattern):
        self.pattern_length = len(pattern)
        table = {}

        for i in range(len(pattern) - 2, -1, -1):
            c = pattern[i]
            if c not in table:
                table[c] = len(pattern) - 1 - i

        return table

    def get_shift_value(self, c):
        return self.shift_values.get(c, self.pattern_length)


if __name__ == "__main__":
    import sys

    # Create an instance of the Horspool class
    horspool = Horspool()

    # Prompt for text
    text = input()

    # Prompt for pattern
    pattern = input()

    # Perform search
    position = horspool.find_first(pattern, text)

    # Display results
    if position != -1:
        print(f"Pattern found at index: {position}")
    else:
        print("Pattern not found.")

# <END-OF-CODE>
