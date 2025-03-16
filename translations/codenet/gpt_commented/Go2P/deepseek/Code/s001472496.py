def main():
    # Read the input string from standard input
    s = input()

    # Initialize variables to track the maximum length of valid characters and the current length
    max_tmp = 0
    max = 0

    # Iterate over each character in the input string
    for i in range(len(s)):
        # Flag to indicate if a non-valid character is encountered
        flag = False

        # Check if the current character is one of the valid DNA bases
        if s[i] in "ACGT":
            # Increment the temporary count for valid characters
            max_tmp += 1
        else:
            # Set the flag to true if a non-valid character is found
            flag = True

        # Update the maximum length if the current temporary length is greater
        if max < max_tmp:
            max = max_tmp

        # If a non-valid character was found
        if flag:
            # Reset the temporary length counter
            max_tmp = 0

    # Print the maximum length of consecutive valid characters found
    print(max)


main()
