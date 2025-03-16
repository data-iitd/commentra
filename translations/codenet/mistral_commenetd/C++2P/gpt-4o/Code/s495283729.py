# Include necessary libraries for standard input/output

def main():
    s = input()  # Read a string from the standard input

    flag = 0  # Initialize a boolean flag

    for i in range(len(s)):  # Iterate through each character in the string 's'
        if i % 2 == 0:  # Check if the current index 'i' is even
            if s[i] not in 'RUD':  # If the character is not 'R', 'U', or 'D'
                flag = 1  # Set the flag to 1
        else:  # If the current index 'i' is odd
            if s[i] not in 'LUD':  # If the character is not 'L', 'U', or 'D'
                flag = 1  # Set the flag to 1

    if flag == 0:  # If no invalid character was found during the iteration
        print("Yes")  # Output "Yes" to the standard output
    else:  # If an invalid character was found during the iteration
        print("No")  # Output "No" to the standard output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
