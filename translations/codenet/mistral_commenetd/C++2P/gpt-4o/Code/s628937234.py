# Include necessary libraries

def main():
    s = input()  # Read a string from the standard input and store it in the variable s

    # The following block of code creates a new string t from the string s
    t = s[0]  # Extract the first character from string s
    t += str(len(s) - 2)  # Convert the size of string s minus 2 to a string
    t += s[-1]  # Concatenate the last character of string s

    print(t)  # Output the newly created string t to the standard output

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
