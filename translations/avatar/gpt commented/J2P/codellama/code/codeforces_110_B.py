
# Importing the Scanner class for user input
from java.util import Scanner

# Creating a Scanner object to read input from the console
sc = Scanner(System.in)

# Declaring variables
n = 0 # Initializing 'n' to 0
i = 0 # Initializing 'i' to 0
j = 0 # Initializing 'j' to 0
p = 97 # Initializing 'p' to 97, which is the ASCII value for 'a'

# Reading an integer input from the user which determines the size of the character array
n = sc.nextInt()

# Creating a character array of size 'n'
c = [0] * n

# Filling the character array with letters starting from 'a' (ASCII 97)
for i in range(4): # Looping through the first 4 positions
    for j in range(i, n, 4): # Filling every 4th position starting from 'i'
        c[j] = chr(p) # Assigning the character corresponding to ASCII value 'p'
        p += 1 # Incrementing 'p' to get the next character

# Printing the filled character array to the console
for i in range(n):
    print(c[i], end="") # Outputting each character in the array

# End of code
