
import sys

# Reading a string input from the user
str = input()

# Converting the string to a character array for easier manipulation
c = list(str)

# Reading a long integer input from the user
k = int(input())

# Getting the length of the input string
n = len(str)

# Looping through the first k characters of the character array
for i in range(k):
    # Checking if the current character is '1'
    if c[i] == '1':
        # If it's the last character in the range, print 1 and exit
        if i == k - 1:
            print(1)
            sys.exit() # Exit the program
    else:
        # If the current character is not '1', print it and exit
        print(c[i])
        sys.exit() # Exit the program

