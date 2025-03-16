class Main:
    # Class variable to store shift values for characters in the pattern
    shift_values = {}
    # Length of the pattern
    pattern_length = 0
    # Counter for the number of comparisons made
    comparisons = 0

    @staticmethod
    def find_first(pattern, text):
        return Main.first_occurrence(pattern, text, True)

    @staticmethod
    def first_occurrence(pattern, text, case_sensitive):
        # Calculate shift values for the pattern
        Main.shift_values = Main.calc_shift_values(pattern)
        Main.comparisons = 0  # Reset comparisons count
        # If the pattern is empty, return -1 (not found)
        if not pattern:
            return -1
        # Start searching from the end of the pattern in the text
        text_index = len(pattern) - 1
        while text_index < len(text):
            i = len(pattern) - 1  # Index for the pattern
            while i >= 0:
                Main.comparisons += 1  # Increment comparison count
                pattern_char = pattern[i]
                text_char = text[text_index - (len(pattern) - 1) + i]
                # Check if characters match based on case sensitivity
                if not Main.char_equals(pattern_char, text_char, case_sensitive):
                    # If not a match, shift the text index based on the character
                    text_index += Main.get_shift_value(text[text_index])
                    break  # Exit inner loop to continue with the next text index
                i -= 1  # Move to the next character in the pattern
            # If all characters matched, return the starting index of the match
            if i == -1:
                return text_index - len(pattern) + 1
        # If no match is found, return -1
        return -1

    @staticmethod
    def char_equals(c1, c2, case_sensitive):
        return c1 == c2 if case_sensitive else c1.lower() == c2.lower()

    @staticmethod
    def calc_shift_values(pattern):
        Main.pattern_length = len(pattern)  # Store the length of the pattern
        table = {}  # Initialize shift values table
        # Populate the shift values for each character in the pattern
        for i in range(len(pattern) - 2, -1, -1):
            c = pattern[i]
            table.setdefault(c, len(pattern) - 1 - i)
        return table  # Return the shift values table

    @staticmethod
    def get_shift_value(c):
        return Main.shift_values.get(c, Main.pattern_length)  # Default to pattern length if not found

# Main execution
if __name__ == "__main__":
    text = input()  # Read the text input
    pattern = input()  # Read the pattern input
    position = Main.find_first(pattern, text)  # Find the first occurrence of the pattern
    # Output the result based on the position found
    if position != -1:
        print(f"Pattern found at index: {position}")
    else:
        print("Pattern not found.")

# <END-OF-CODE>
