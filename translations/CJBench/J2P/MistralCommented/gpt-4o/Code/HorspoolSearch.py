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

        if not pattern:  # Base case: if the pattern is empty, return -1
            return -1

        text_index = len(pattern) - 1  # Initialize text_index to the last character of the pattern

        while text_index < len(text):  # While text_index is less than the length of the text
            i = len(pattern) - 1  # Initialize i to the last character of the pattern

            # Loop through each character of the pattern from the last to the first
            while i >= 0:
                Main.comparisons += 1  # Increment comparisons for each character comparison

                pattern_char = pattern[i]  # Get the character of the pattern at index i
                text_char = text[text_index + i - (len(pattern) - 1)]  # Get the character of the text at the corresponding index

                # Compare the characters of the pattern and text, considering case sensitivity
                if not Main.char_equals(pattern_char, text_char, case_sensitive):
                    text_index += Main.get_shift_value(text[text_index])  # Shift text_index based on the shift value of the character at text_index
                    break  # Exit the inner loop if the characters don't match

                i -= 1  # Decrement i to compare the next character of the pattern with the text

            # If all characters of the pattern match the corresponding characters in the text, return the index of the first match
            if i == -1:
                return text_index - len(pattern) + 1

            text_index += 1  # Increment text_index to compare the next possible match in the text

        # If no match is found, return -1
        return -1

    @staticmethod
    def char_equals(c1, c2, case_sensitive):
        return c1 == c2 if case_sensitive else c1.lower() == c2.lower()

    @staticmethod
    def calc_shift_values(pattern):
        Main.pattern_length = len(pattern)
        table = {}

        # Calculate shift values for each character in the pattern, from the last to the first
        for i in range(len(pattern) - 2, -1, -1):
            c = pattern[i]
            table.setdefault(c, Main.pattern_length - 1 - i)

        return table

    @staticmethod
    def get_shift_value(c):
        return Main.shift_values.get(c, Main.pattern_length)

if __name__ == "__main__":
    text = input()  # Read the text from the user
    pattern = input()  # Read the pattern from the user
    position = Main.find_first(pattern, text)  # Find the first occurrence of the pattern in the text

    if position != -1:  # If the pattern is found, print the index of the first occurrence
        print(f"Pattern found at index: {position}")
    else:  # If the pattern is not found, print a message indicating that
        print("Pattern not found.")

# <END-OF-CODE>
