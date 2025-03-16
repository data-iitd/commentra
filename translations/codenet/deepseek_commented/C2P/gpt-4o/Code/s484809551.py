import sys

# Define the pattern to search for
pattern_base = "keyence"

# Function to find the last occurrence of a substring within a string
def strrstr(string, pattern):
    last_pos = -1
    offset = 0

    # Loop to find the last occurrence of the pattern
    while True:
        search_result = string.find(pattern, offset)
        if search_result == -1:
            break
        last_pos = search_result
        offset = search_result + 1  # Move offset to search for further occurrences

    return last_pos  # Return the last found position

# Main function to execute the program
def main():
    S = input().strip()  # Read the input string

    found = False  # Flag to indicate if the pattern is found

    # Loop through each possible split point in the pattern
    for offset in range(len(pattern_base) + 1):
        # Split the pattern into top and bottom parts
        top = pattern_base[:offset]
        bottom = pattern_base[offset:]

        # Search for the top part in the input string
        top_search = S.find(top)
        if top_search != -1:
            # Search for the bottom part after the found top part
            bottom_search = strrstr(S[top_search + offset:], bottom)
            if bottom_search != -1:
                sep_count = 0  # Counter for separators

                # Count the number of separators between top and bottom parts
                if top_search != 0:
                    sep_count += 1  # Increment if there's text before the top part
                if top_search + offset != bottom_search + top_search + offset:
                    sep_count += 1  # Increment if there's text between top and bottom parts
                if bottom_search + len(bottom) < len(S):
                    sep_count += 1  # Increment if there's text after the bottom part

                # Check if the number of separators is less than or equal to 1
                if sep_count <= 1:
                    found = True  # Set found flag to true
                    break  # Exit the loop as the pattern is found

    # Output the result based on whether the pattern was found
    print("YES" if found else "NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
