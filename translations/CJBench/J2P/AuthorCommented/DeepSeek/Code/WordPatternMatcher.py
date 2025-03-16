def match_word_pattern(pattern, input_string):
    pattern_map = {}
    str_map = {}

    def backtrack(pattern_index, str_index):
        if pattern_index == len(pattern) and str_index == len(input_string):
            return True
        if pattern_index == len(pattern) or str_index == len(input_string):
            return False

        current_char = pattern[pattern_index]
        if current_char in pattern_map:
            mapped_str = pattern_map[current_char]
            if input_string.startswith(mapped_str, str_index):
                return backtrack(pattern_index + 1, str_index + len(mapped_str))
            else:
                return False

        for end in range(str_index + 1, len(input_string) + 1):
            substring = input_string[str_index:end]
            if substring in str_map:
                continue

            pattern_map[current_char] = substring
            str_map[substring] = current_char
            if backtrack(pattern_index + 1, end):
                return True

            del pattern_map[current_char]
            del str_map[substring]

        return False

    return backtrack(0, 0)


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    pattern = data[0]
    input_string = data[1]

    result = match_word_pattern(pattern, input_string)
    print("True" if result else "False")
