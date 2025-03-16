class Main:
    shift_values = {}
    pattern_length = 0
    comparisons = 0

    @staticmethod
    def find_first(pattern, text):
        return Main.first_occurrence(pattern, text, True)

    @staticmethod
    def first_occurrence(pattern, text, case_sensitive):
        Main.shift_values = Main.calc_shift_values(pattern)
        Main.comparisons = 0
        if not pattern:
            return -1
        text_index = len(pattern) - 1
        while text_index < len(text):
            i = len(pattern) - 1
            while i >= 0:
                Main.comparisons += 1
                pattern_char = pattern[i]
                text_char = text[text_index - (len(pattern) - 1) + i]
                if not Main.char_equals(pattern_char, text_char, case_sensitive):
                    text_index += Main.get_shift_value(text[text_index])
                    break
                i -= 1
            if i == -1:
                return text_index - len(pattern) + 1
        return -1

    @staticmethod
    def char_equals(c1, c2, case_sensitive):
        return c1 == c2 if case_sensitive else c1.lower() == c2.lower()

    @staticmethod
    def calc_shift_values(pattern):
        Main.pattern_length = len(pattern)
        table = {}
        for i in range(len(pattern) - 2, -1, -1):
            c = pattern[i]
            table.setdefault(c, len(pattern) - 1 - i)
        return table

    @staticmethod
    def get_shift_value(c):
        return Main.shift_values.get(c, Main.pattern_length)

if __name__ == "__main__":
    text = input()
    pattern = input()
    position = Main.find_first(pattern, text)
    if position != -1:
        print(f"Pattern found at index: {position}")
    else:
        print("Pattern not found.")

# <END-OF-CODE>
