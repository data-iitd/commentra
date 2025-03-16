def main():
    # Read a string from standard input
    s = input()

    # Initialize variables to keep track of the maximum lengths
    max_tmp = 0
    max_length = 0

    # Iterate over each character in the string
    for i in range(len(s)):
        flag = False
        # Check if the character is one of 'A', 'C', 'T', 'G'
        if s[i] in "ACTG":
            # Increment the temporary maximum length counter
            max_tmp += 1
        else:
            # Set the flag to true if the character is not 'A', 'C', 'T', 'G'
            flag = True

        # At the end of the loop, if the flag is true, update the overall maximum length
        if i == len(s) - 1:
            flag = True
        if flag:
            if max_length < max_tmp:
                max_length = max_tmp
            # Reset the temporary maximum length counter
            max_tmp = 0

    # Print the value of the overall maximum length
    print(max_length)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
