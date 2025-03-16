# Include standard input-output library for print and input functions

def main():
    s = input()  # Read a string from the user input

    # Outer loop to iterate over each character in the string s using index j
    for j in range(len(s)):
        # Inner loop to iterate over each character in the string s using index i
        for i in range(len(s)):
            # Check if the characters at positions i and j are the same, but only if i is not equal to j
            if i != j and s[i] == s[j]:
                print("no")  # Print "no" if a duplicate character is found and exit the program
                return

    print("yes")  # Print "yes" if no duplicates are found after completing the loops

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
