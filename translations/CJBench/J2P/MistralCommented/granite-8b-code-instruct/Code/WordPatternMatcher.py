

def match_word_pattern(pattern, input_string):
    pattern_map = {} # Initialize an empty dictionary to store the mapping of characters to strings
    str_map = {} # Initialize an empty dictionary to store the mapping of strings to characters

    # Recursive method to check if the pattern matches the input string
    def backtrack(pattern, input_string, pattern_index, str_index, pattern_map, str_map):
        # Base case: if we have checked all characters in the pattern and all characters in the input string, then the pattern matches the input string
        if pattern_index == len(pattern) and str_index == len(input_string):
            return True

        # Base case: if we have checked all characters in the pattern or all characters in the input string, then the pattern does not match the input string
        if pattern_index == len(pattern) or str_index == len(input_string):
            return False

        current_char = pattern[pattern_index] # Get the current character in the pattern

        # If the current character in the pattern is already mapped to a string, check if the input string starts with that string
        if current_char in pattern_map:
            mapped_str = pattern_map[current_char]
            if input_string.startswith(mapped_str, str_index):
                # Recursively call the backtrack method with the updated pattern index and string index
                return backtrack(pattern, input_string, pattern_index + 1, str_index + len(mapped_str), pattern_map, str_map)
            else:
                # If the input string does not start with the mapped string, then the pattern does not match the input string
                return False

        # If the current character in the pattern is not yet mapped to a string, try mapping it to different substrings in the input string
        for end in range(str_index + 1, len(input_string) + 1):
            substring = input_string[str_index:end] # Get the substring starting from the current string index to the end of the input string

            # If the substring is already mapped to a character, skip it and try the next substring
            if substring in str_map:
                continue

            # Map the current character in the pattern to the substring in the input string
            pattern_map[current_char] = substring
            str_map[substring] = current_char

            # Recursively call the backtrack method with the updated pattern index and string index
            result = backtrack(pattern, input_string, pattern_index + 1, end, pattern_map, str_map)

            # If the pattern matches the input string, return True
            if result:
                return True

            # If the pattern does not match the input string, unmap the current character and substring and try the next substring
            del pattern_map[current_char]
            del str_map[substring]

    # Main method to read the pattern and input string from the user and print the result
    pattern = input() # Read the pattern from the user
    input_string = input() # Read the input string from the user

    result = match_word_pattern(pattern, input_string) # Call the match_word_pattern method with the pattern and input string

    print("True" if result else "False") # Print the result to the console

Translate the above Python code to C++ and end with comment "