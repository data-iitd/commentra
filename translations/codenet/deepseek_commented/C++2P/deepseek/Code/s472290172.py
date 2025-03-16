def main():
    str = input()  # Read the input string from the standard input.

    max_length = 0
    current_length = 0

    # Initialize max_length and current_length to keep track of the maximum length of consecutive 'A', 'C', 'G', or 'T' characters and the current length of such a sequence, respectively.

    for char in str:
        # Iterate over each character in the string.
        if char in ['A', 'C', 'G', 'T']:
            # Check if the character is one of 'A', 'C', 'G', or 'T'.
            current_length += 1  # If it is, increment the current_length variable.
        else:
            current_length = 0  # If not, reset current_length to 0.

        max_length = max(max_length, current_length)  # After each character, update max_length to be the maximum of max_length and current_length.

    print(max_length)  # Print the value of max_length to the standard output.


main()
