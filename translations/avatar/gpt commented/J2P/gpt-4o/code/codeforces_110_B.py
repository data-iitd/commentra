# Importing the sys module for user input
import sys

def main():
    # Reading an integer input from the user which determines the size of the character array
    n = int(input())
    
    # Declaring variables
    p = 97  # 'p' is initialized to 97, which is the ASCII value for 'a'
    
    # Creating a list to hold characters
    c = [''] * n
    
    # Filling the character array with letters starting from 'a' (ASCII 97)
    for i in range(4):  # Looping through the first 4 positions
        for j in range(i, n, 4):  # Filling every 4th position starting from 'i'
            c[j] = chr(p)  # Assigning the character corresponding to ASCII value 'p'
            p += 1  # Incrementing 'p' to get the next character
    
    # Printing the filled character array to the console
    for char in c:
        print(char, end='')  # Outputting each character in the array

if __name__ == "__main__":
    main()

# <END-OF-CODE>
