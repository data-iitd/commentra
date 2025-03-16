# Include standard input/output library
# Include standard library for memory allocation

def main():  # Beginning of the main function
    S = input()  # Read a string of six characters from the standard input and store it in the variable 'S'

    for i in range(len(S)):  # Iterate through each character in the string 'S'
        if S[i] == 'A' and i + 1 < len(S) and S[i + 1] == 'C':  # Check if the current character is 'A' and the next character is 'C'
            print("Yes")  # If so, print 'Yes' to the standard output
            return  # And exit the function

    print("No")  # If no pair of 'AC' is found, print 'No' to the standard output

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
