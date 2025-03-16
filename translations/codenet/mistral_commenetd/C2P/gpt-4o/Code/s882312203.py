# Include the standard input/output library
# Include the string manipulation library

def main():  # The main function is the entry point of the program
    s = input()  # Read a string from the standard input and store it in the 's' variable

    for j in range(len(s)):  # Iterate through each character in the string 's' using index 'j'
        for i in range(len(s)):  # Nested loop to compare each character with all other characters in the string
            if i != j and s[i] == s[j]:  # Check if the current characters at indices 'i' and 'j' are the same and not the same index
                print("no")  # If duplicate characters are found, print 'no' and exit the program
                return

    print("yes")  # If no duplicate characters are found, print 'yes'

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
