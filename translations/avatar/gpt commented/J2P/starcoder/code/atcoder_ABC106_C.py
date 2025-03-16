
# Importing the necessary classes from the sys and string packages
import sys
import string

# Reading a string input from the user
str = sys.stdin.readline()

# Converting the string to a character array for easier manipulation
c = list(str)

# Reading a long integer input from the user
k = int(sys.stdin.readline())

# Getting the length of the input string
n = len(str)

# Looping through the first k characters of the character array
for i in range(k):
    # Checking if the current character is '1'
    if c[i] == '1':
        # If it's the last character in the range, print 1 and exit
        if i == k - 1:
            print(1)
            break # Exit the program
    else:
        # If the current character is not '1', print it and exit
        print(c[i])
        break # Exit the program

# 