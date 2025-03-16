
import sys

# HashMap to store shift values for characters in the pattern
shift_values = {}
# Length of the pattern
pattern_length = 0
# Counter for the number of comparisons made
comparisons = 0

# Public method to find the first occurrence of a pattern in a text
def find_first(pattern, text):
    return first_occurrence(pattern, text, True)

# Private method to find the first occurrence of a pattern in a text
def first_occurrence(pattern, text, case_sensitive):
    # Calculate shift values for the pattern
    global shift_values
    shift_values = calc_shift_values(pattern)
    global comparisons
    comparisons = 0
    # If the pattern is empty, return -1 (not found)
    if pattern == "":
        return -1
    # Start searching from the end of the pattern in the text
    text_index = len(pattern) - 1
    while text_index < len(text):
        i = len(pattern) - 1
        while i >= 0:
            comparisons += 1
            pattern_char = pattern[i]
            text_char = text[text_index + i - (len(pattern) - 1)]
            # Check if characters match based on case sensitivity
            if not char_equals(pattern_char, text_char, case_sensitive):
                # If not a match, shift the text index based on the character
                text_index += get_shift_value(text[text_index])
                break
            i -= 1
        # If all characters matched, return the starting index of the match
        if i == -1:
            return text_index - len(pattern) + 1
    # If no match is found, return -1
    return -1

# Method to compare two characters based on case sensitivity
def char_equals(c1, c2, case_sensitive):
    return case_sensitive and c1 == c2 or not case_sensitive and c1.lower() == c2.lower()

# Method to calculate shift values for each character in the pattern
def calc_shift_values(pattern):
    global pattern_length
    pattern_length = len(pattern)
    table = {}
    # Populate the shift values for each character in the pattern
    for i in range(len(pattern) - 2, -1, -1):
        c = pattern[i]
        table[c] = pattern_length - 1 - i
    return table

# Method to get the shift value for a character
def get_shift_value(c):
    return shift_values.get(c, pattern_length)

# Main method to execute the program
def main():
    text = sys.stdin.readline().strip()
    pattern = sys.stdin.readline().strip()
    position = find_first(pattern, text)
    # Output the result based on the position found
    if position != -1:
        print("Pattern found at index: " + str(position))
    else:
        print("Pattern not found.")

if __name__ == "__main__":
    main()

