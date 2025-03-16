import sys
from collections import defaultdict

class Main:
    def __init__(self):
        self.shift_values = None
        self.pattern_length = None
        self.comparisons = 0

    def find_first(self, pattern, text, case_sensitive=True):
        return self.first_occurrence(pattern, text, case_sensitive)

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

            text_index += 1

        return -1

    def char_equals(self, c1, c2, case_sensitive):
        return c1 == c2 if case_sensitive else c1.lower() == c2.lower()

    def calc_shift_values(self, pattern):
        self.pattern_length = len(pattern)
        table = defaultdict(lambda: self.pattern_length)

        for i in range(len(pattern) - 2, -1, -1):
            c = pattern[i]
            table[c] = len(pattern) - 1 - i

        return table

    def get_shift_value(self, c):
        return self.shift_values[c] if c in self.shift_values else self.pattern_length

    def main(self):
        text = input().strip()
        pattern = input().strip()
        position = self.find_first(pattern, text)

        if position != -1:
            print(f"Pattern found at index: {position}")
        else:
            print("Pattern not found.")

if __name__ == "__main__":
    main_instance = Main()
    main_instance.main()
