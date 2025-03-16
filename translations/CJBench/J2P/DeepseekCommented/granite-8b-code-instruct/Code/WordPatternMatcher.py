

def match_word_pattern(pattern, input_string):
    # Maps to store the pattern-to-string and string-to-pattern mappings
    pattern_map = {}
    str_map = {}
    # Start the backtracking process
    return backtrack(pattern, input_string, 0, 0, pattern_map, str_map)

# Helper method to perform the backtracking for pattern matching
def backtrack(pattern, input_string, pattern_index, str_index, pattern_map, str_map):
    # If both pattern and input string are fully traversed, return true
    if pattern_index == len(pattern) and str_index == len(input_string):
        return True
    # If either pattern or input string is fully traversed, return false
    if pattern_index == len(pattern) or str_index == len(input_string):
        return False
    # Get the current character from the pattern
    current_char = pattern[pattern_index]
    # Check if the current character is already mapped
    if current_char in pattern_map:
        # Get the mapped string
        mapped_str = pattern_map[current_char]
        # Check if the input string starts with the mapped string
        if input_string.startswith(mapped_str, str_index):
            # Recursively check the next part of the pattern and input string
            return backtrack(pattern, input_string, pattern_index + 1, str_index + len(mapped_str), pattern_map, str_map)
        else:
            return False
    # Try to map the current character to different substrings in the input string
    for end in range(str_index + 1, len(input_string) + 1):
        substring = input_string[str_index:end]
        if substring in str_map:
            continue
        # Map the current character to the substring
        pattern_map[current_char] = substring
        str_map[substring] = current_char
        # Recursively check the next part of the pattern and input string
        if backtrack(pattern, input_string, pattern_index + 1, end, pattern_map, str_map):
            return True
        # Backtrack: remove the current mapping
        del pattern_map[current_char]
        del str_map[substring]
    return False

# Main method to take input and print the result
if __name__ == "__main__":
    pattern = input()
    input_string = input()
    result = match_word_pattern(pattern, input_string)
    print("True" if result else "False")

