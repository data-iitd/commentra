def strrstr(string, pattern):
    """Find the last occurrence of a substring in a string."""
    last_index = -1
    offset = 0

    while True:
        index = string.find(pattern, offset)
        if index == -1:
            break
        last_index = index
        offset = index + 1

    return last_index


def main():
    # Define pattern base string
    pattern_base = "keyence"
    S = input().strip()

    # Calculate length of input string
    len_S = len(S)
    found = False

    # Loop through each character in pattern base string
    for offset in range(len(pattern_base) + 1):
        # Copy substring up to current character to top variable
        top = pattern_base[:offset]

        # Copy substring from current character to end of pattern base string to bottom variable
        bottom = pattern_base[offset:]

        # Search for top substring in input string
        top_search = S.find(top)

        # If top substring is found
        if top_search != -1:
            # Search for bottom substring after top substring in input string
            bottom_search = strrstr(S[top_search + offset:], bottom)

            # If bottom substring is found
            if bottom_search != -1:
                # Calculate number of separators between top and bottom substrings
                sep_count = 0

                # If top_search is not the first occurrence of top substring in input string
                if top_search != 0:
                    sep_count += 1

                # If top_search is not the same as bottom_search
                if top_search + offset != bottom_search + top_search + offset:
                    sep_count += 1

                # If bottom_search is not the last character in input string
                if bottom_search + len(bottom) < len_S:
                    sep_count += 1

                # If number of separators is less than or equal to 1
                if sep_count <= 1:
                    found = True
                    break

    # Print output based on whether pattern is found or not
    print("YES" if found else "NO")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
