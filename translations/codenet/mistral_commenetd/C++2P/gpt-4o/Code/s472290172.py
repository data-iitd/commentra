# Main function starts here
def main():
    # Read the input string from the standard input
    str_input = input()

    max_count = 0  # Initialize the maximum count with zero
    cnt = 0  # Initialize the current count with zero

    # Iterate through each character in the input string
    for sc in str_input:
        # Check if the current character is a valid nucleotide (A, C, G or T)
        if sc in 'ACGT':
            cnt += 1  # Increment the count if the character is a valid nucleotide
        else:
            cnt = 0  # Otherwise, reset the count to zero

        # Update the maximum count if the current count is greater than the previous maximum
        max_count = max(max_count, cnt)

    # Print the maximum count of valid nucleotides found in the input string
    print(max_count)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
