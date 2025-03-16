#include<stdio.h> // Include the standard input/output library

def main(): # Declare the main function
    str = [None] * 30 # Declare a character array str of size 30

    # Get a string input from the user using gets() function and store it in str array
    str = input()

    # Assign a space character to the 6th index (index starts from 0) and 14th index of the string str
    str[5] =''
    str[13] =''

    # Print the modified string using printf() function
    print(str)

# Return 0 to indicate successful execution of the program
if __name__ == "__main__":
    main()

