# Importing the necessary modules
import sys

def main():
    # Reading a string input from the user
    str_input = input()
    
    # Converting the string to a list of characters for easier manipulation
    c = list(str_input)
    
    # Reading a long integer input from the user
    k = int(input())
    
    # Getting the length of the input string
    n = len(str_input)
    
    # Looping through the first k characters of the character list
    for i in range(k):
        # Checking if the current character is '1'
        if c[i] == '1':
            # If it's the last character in the range, print 1 and exit
            if i == k - 1:
                print(1)
                return  # Exit the program
        else:
            # If the current character is not '1', print it and exit
            print(c[i])
            return  # Exit the program

if __name__ == "__main__":
    main()

# <END-OF-CODE>
