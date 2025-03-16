def match_word_pattern(pattern, input_string):
    # Maps to store the relationship between pattern characters and substrings
    pattern_map = {}
    str_map = {}
    
    # Start the backtracking process
    def backtrack(pattern_index, str_index):
        # Check if both pattern and input string have been fully matched
        if pattern_index == len(pattern) and str_index == len(input_string):
            return True
        # If one of them is fully matched but the other is not, return false
        if pattern_index == len(pattern) or str_index == len(input_string):
            return False

        # Get the current character from the pattern
        current_char = pattern[pattern_index]
        
        # If the current character is already mapped to a substring
        if current_char in pattern_map:
            mapped_str = pattern_map[current_char]
            # Check if the input string starts with the mapped substring at the current index
            if input_string.startswith(mapped_str, str_index):
                # Continue to backtrack with the next character in the pattern and the updated index in the input string
                return backtrack(pattern_index + 1, str_index + len(mapped_str))
            else:
                return False # Mapped substring does not match

        # Try to map the current pattern character to different substrings of the input string
        for end in range(str_index + 1, len(input_string) + 1):
            substring = input_string[str_index:end]
            # If the substring is already mapped to a different pattern character, skip it
            if substring in str_map:
                continue
            # Map the current character to the substring and vice versa
            pattern_map[current_char] = substring
            str_map[substring] = current_char
            # Recursively backtrack with the new mappings
            if backtrack(pattern_index + 1, end):
                return True # Found a valid mapping
            # If not successful, remove the mappings and try the next substring
            pattern_map.pop(current_char)
            str_map.pop(substring)
        return False # No valid mapping found

    # Start the backtracking process from the beginning
    return backtrack(0, 0)

# Main method to execute the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()
    pattern = data[0]
    input_string = data[1]
    # Check if the pattern matches the input string
    result = match_word_pattern(pattern, input_string)
    # Output the result
    print("True" if result else "False")
