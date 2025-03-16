# Include the iostream library for input and output
# Include the algorithm library (not used in this code)
# Include the string library for string manipulation

# Define a main function
def main():
    # Declare two strings: s for input and t for the output format
    s = ""
    t = ""

    # Read a string input from the user and store it in s
    s = input("Enter a string: ")

    # Construct the abbreviated version of the string
    t = s[0] # Start with the first character of the input string
    t += str(len(s) - 2) # Append the number of characters between the first and last characters
    t += s[len(s) - 1] # Append the last character of the input string

    # Output the abbreviated string
    print(t)

# Call the main function
main()

