def main():
    str_input = input()  # Read the input string from the standard input.

    max_length = 0  # Initialize max_length to keep track of the maximum length of consecutive 'A', 'C', 'G', or 'T' characters.
    cnt = 0  # Initialize cnt to keep track of the current length of such a sequence.

    for sc in str_input:  # Iterate over each character in the string.
        if sc in 'ACGT':  # Check if the character is one of 'A', 'C', 'G', or 'T'.
            cnt += 1  # If it is, increment the cnt variable.
        else:
            cnt = 0  # If not, reset cnt to 0.
        
        max_length = max(max_length, cnt)  # Update max_length to be the maximum of max_length and cnt.

    print(max_length)  # Print the value of max_length to the standard output.

if __name__ == "__main__":
    main()

# <END-OF-CODE>
